#include "w_game.h"
#include "ui_mainwindow.h"
#include "ui_standarddialog.h"
#include "ui_cardbutton.h"
#include "cardset.h"
#include <QStringList>
#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QStringBuilder>
#include <QByteArray>
#include <QDataStream>
#include <QtGlobal>
#include <QPropertyAnimation>

#define PGAMEREADY 0
#define PWAITING 1
#define PCHOOSE 2
#define PGAMING 3
#define PSCORE 4
#define PFINALSCORE 5


Game::Game(QWidget *parent) : QStackedWidget(parent), tip(new QLabel(nullptr))
{
    handlers["ready"] = &Game::hReady;
    handlers["start"] = &Game::hStart;
    handlers["changeRound"] = &Game::hChangeRound;
    handlers["changeStrenth"] = &Game::hChangeStrenth;
    handlers["move"] = &Game::hMove;
    handlers["ohandChange"] = &Game::hohandChange;
    handlers["specialCard"] = &Game::hSpecialCard;
    handlers["giveup"] = &Game::hoGiveup;
}

void Game::init(Player *aPlayer, Ui::MainWindow *aui)
{
    ui = aui;
    player = aPlayer;
    battleField = ui->battleField;
    this->setCurrentIndex(PGAMEREADY);
    connect(ui->asClientButton, SIGNAL(clicked()), this, SLOT(asClient()), Qt::UniqueConnection);
    connect(ui->asServerButton, SIGNAL(clicked()), this, SLOT(asServer()), Qt::UniqueConnection);
}

void Game::asClient()
{
    Dialog dlg("invitation code:", true, this);
    if (QDialog::Accepted == dlg.exec())
    {
        this->setCurrentIndex(PWAITING);
        QStringList list = dlg.content.split('&');
        QHostAddress address = QHostAddress(list.at(0));
        int port = list.at(1).toInt();
        socket = new QTcpSocket(this);
        socket->connectToHost(address, port, QTcpSocket::ReadWrite);
        connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
    }
}

void Game::asServer()
{
    QHostAddress ip;
    int port = 56700;
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address, info.addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol)
         {
             ip = address;
             break;
         }
    }
    server = new QTcpServer(this);
    while (!server->listen(ip, port))
    {
        port++;
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    Dialog dlg("invitation code:", true, this);
    dlg.setText(ip.toString() % "&" % QString::number(port));
    if (QDialog::Accepted == dlg.exec())
    {
        this->setCurrentIndex(PWAITING);
    }
    else
    {
        server->close();
        server->deleteLater();
    }
}

void Game::onNewConnection()
{
    if (this->currentIndex() != PWAITING)
    {
        for (auto it: this->children())
        {
            if (it->inherits("Dialog"))
            {
                static_cast<Dialog*>(*&it)->accept();
            }
        }
        this->setCurrentIndex(PWAITING);
    }
    socket = server->nextPendingConnection();
    onConnect();
}

void Game::onConnect()
{
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMsg()));
    ui->msg->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; color:#b7b7b7;\">Connect successfully!</span></p></body></html>", Q_NULLPTR));


    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(chooseCardSet()), Qt::UniqueConnection);
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()), Qt::UniqueConnection);
    timer->start(1200);
    battleField->initForFirst(ui);
}

void Game::chooseCardSet()
{
    ui->gamingChooseSlot->setLimit(3); // 设置一页最多几张
    for (auto it: player->cardSets)
    {
        CardSetButton* set = new CardSetButton(&*it, ui->gamingChooseSlot); // 实例化按钮
        ui->gamingChooseSlot->addCard(set); // 显示
        if (it->isValid) {
            connect(set, SIGNAL(selected(CardSet*)), this, SLOT(start(CardSet*)));
        } else {
            set->setEnabled(false);
        }
    }
    this->setCurrentIndex(PCHOOSE);
}

void Game::start(CardSet *cardSet)
{
    ui->msg->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; color:#b7b7b7;\">Please wait patiently.</span></p></body></html>", Q_NULLPTR));
    this->setCurrentIndex(PWAITING);
    ui->gamingChooseSlot->clear();
    battleField->setCardSet(cardSet);
    connect(battleField, SIGNAL(sendMsg(QMap<QString,QString>)), this, SLOT(sendMsg(QMap<QString,QString>)));
    connect(battleField, SIGNAL(showToBechosen(QList<CardButton*>)), this, SLOT(showToBechosen(QList<CardButton*>)));
    connect(battleField, SIGNAL(clearChooseSlot()), this, SLOT(clearChooseSlot()));
    connect(ui->gamingRound, SIGNAL(giveup()), this, SLOT(mgiveup()));
    signalTimesLimit = 3;
    showToBechosen(battleField->drawCards(10), &Game::dispatchCard);
}

void Game::showToBechosen(QList<CardButton *> list, standardSlot slot)
{
    for (auto it: list) {
        ui->gamingChooseSlot->addCard(&*it);
        connect(&*it, &CardButton::selected, this, slot);
    }
    this->setCurrentIndex(PCHOOSE);
    ui->gamingChooseSlot->setCurrentIndex(0);
}

void Game::dispatchCard(CardButton * card)
{
    ui->gamingChooseSlot->setAllEnabled(false);
    auto newCard = battleField->drawCards(1, card->card->id).first();
    ui->gamingChooseSlot->replaceCard(card, newCard);
    battleField->addCardToMDeck(card->card->id);
    connect(newCard, SIGNAL(selected(CardButton*)), this, SLOT(dispatchCard(CardButton*)));
    signalTimes++;
    if (signalTimes < signalTimesLimit)
    {
        ui->gamingChooseSlot->setAllEnabled(true);
        return;
    }
    ui->gamingChooseSlot->setAllEnabled(true);
    for (auto it: ui->gamingChooseSlot->cardList)
    {
        disconnect(it, SIGNAL(selected(CardButton*)), this, SLOT(dispatchCard(CardButton*)));
    }
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(changePageToGaming()), Qt::UniqueConnection);
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()), Qt::UniqueConnection);
    timer->start(1500);
}

void Game::returnToField(CardButton*)
{
    ui->gameStackWidget->setCurrentIndex(PGAMING);
}

void Game::clearChooseSlot()
{
    ui->gamingChooseSlot->clear();
}

void Game::changePageToGaming()
{
    battleField->init(now);
    Msg msg;
    msg["type"] = "ready";
    msg["who"] = "opponent";
    sendMsg(msg);
    msg["who"] = "me";
    hReady(msg);
    ui->gamingChooseSlot->clear();
    ui->gamingMBcak->clear();
    ui->gamingMFront->clear();
    ui->gamingMMiddle->clear();
    ui->gamingOBack->clear();
    ui->gamingOFront->clear();
    ui->gamingOMiddle->clear();
    battleField->updateStrenthSum();
    ui->gameStackWidget->setCurrentIndex(PGAMING);
}

void Game::sendMsg(QMap<QString, QString> msg)
{
    QString str = stringify(msg);
    qDebug() << "send" << str;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out << str;
    socket->write(block);
    socket->flush();
}

void Game::receiveMsg()
{
    QString str;
    QByteArray block = socket->readAll();
    QDataStream in(&block, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_9);
    in >> str;
    qDebug() << "receive" << str;
    msgHandler(parse(str));
}

Msg Game::parse(QString msg)
{
    QList<QString> temp = msg.split('&');
    QList<QString> kv;
    Msg map;
    for (auto it: temp)
    {
        kv = it.split('=');
        map[kv.at(0)] = kv.at(1);
    }
    return map;
}

QString Game::stringify(Msg msgMap)
{
    QList<QString> temp;
    for (QString it: msgMap.keys())
    {
        temp.append(it % "=" % msgMap.value(it));
    }
    return temp.join('&');
}

void Game::msgHandler(Msg msgMap)
{
    QString type = msgMap["type"];
    if (handlers.contains(type))
    {
        (this->*handlers[type])(msgMap);
    }
}

void Game::myRoundAnimation()
{
    tip->setStyleSheet("border-image: url(:/new/prefix1/resource/m_round");
    QPropertyAnimation animation(tip, "geometry");
    animation.setDuration(3000);
    animation.setStartValue(QRect(100, 30, -100, 200));
    animation.setEndValue(QRect(100, 30, 100, 200));
    animation.start();
}

void Game::score()
{
    mScore[now] = battleField->mStrenth;
    oScore[now] = battleField->oStrenth;
    if (mScore[now] > oScore[now])
    {
        win[now] = 1;
    } else if (mScore[now] < oScore[now]) {
        win[now] = -1;
    }
    if (win.count(1) == 2)
    {
        this->setCurrentIndex(PFINALSCORE);
        ui->finalScore->setStyleSheet("#finalScore {border-image: url(:/new/prefix1/resource/final_score_win.png)}#finalScore * {border-image: url()}");
        ui->mscore1->setText(QString::number(mScore.at(0)));
        ui->mscore2->setText(QString::number(mScore.at(1)));
        ui->mscore3->setText(QString::number(mScore.at(2)));
        ui->oscore1->setText(QString::number(oScore.at(0)));
        ui->oscore2->setText(QString::number(oScore.at(1)));
        ui->oscore3->setText(QString::number(oScore.at(2)));
        return;
    }
    if (win.count(-1) == 2)
    {
        this->setCurrentIndex(PFINALSCORE);
        ui->finalScore->setStyleSheet("#finalScore {border-image: url(:/new/prefix1/resource/final_score_lose.png)}#finalScore * {border-image: url()}");
        ui->mscore1->setText(QString::number(mScore.at(0)));
        ui->mscore2->setText(QString::number(mScore.at(1)));
        ui->mscore3->setText(QString::number(mScore.at(2)));
        ui->oscore1->setText(QString::number(oScore.at(0)));
        ui->oscore2->setText(QString::number(oScore.at(1)));
        ui->oscore3->setText(QString::number(oScore.at(2)));
        return;
    }
    this->setCurrentIndex(PSCORE);
    ui->mscore->setText(QString::number(mScore.at(now)));
    ui->oscore->setText(QString::number(oScore.at(now)));
    now++;
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(newMatch()), Qt::UniqueConnection);
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()), Qt::UniqueConnection);
    timer->start(3000);
}

void Game::newMatch()
{
    int draw;
    switch (now) {
    case 1:
        draw = 2;
        break;
    case 2:
        draw = 1;
    default:
        return;
        break;
    }
    ui->gamingChooseSlot->clear();
    signalTimesLimit = 1; // 换几张
    showToBechosen(battleField->drawCards(draw), &Game::dispatchCard);
}

void Game::startNewRound()
{
    qDebug() << "startNewRound" << myRound;
    Msg msg;
    msg["type"] = "changeRound";
    myRound = !myRound;
    qDebug() << myRound;
    ui->gamingRound->change();
    if (myRound)
    {
        if (giveup[0])
        {
            startNewRound();
            return;
        }
        msg["round"] = "op";
        battleField->setAllHandCardExertable(true);
        myRoundAnimation();
    } else {
        if (giveup[1])
        {
            startNewRound();
            return;
        }
        msg["round"] = "my";
        // 理论上在牌的双击槽函数里就要有下面这句 但是以防漏了
        battleField->setAllHandCardExertable(false);
    }
    sendMsg(msg);
    battleField->doBeforeARound();
}

void Game::timeout()
{
    if (myRound)
    {
        if (battleField->mHand->cardList.count() <= 0)
        {
            giveup[0] = true;
            return;
        }
        battleField->randomlyExertCard();
    }
}

void Game::mgiveup()
{
    giveup[0] = true;
    Msg msg;
    msg["type"] = "giveup";
    sendMsg(msg);
    if (giveup[0] && giveup[1])
    {
        score();
    }
}

void Game::hReady(Msg msgMap)
{
    ((msgMap["who"] == "me") ? ready[0] : ready[1]) = true;
    if (ready[0] && ready[1] && !on)
    {
        // 开始游戏
        on = true;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        Msg msg;
        msg["type"] = "start";
        if (!now)
        {
            int first = qrand() % 2;
            if (first)
            {
                myRound = true;
                msg["first"] = "opponent";
            } else {
                myRound = false;
                msg["first"] = "me";
            }
        } else {
            msg["first"] = (win[now - 1] == 1) ? "me" : "opponent";
        }
        sendMsg(msg);
        startNewRound();
        ui->gamingRound->start(myRound);
        connect(ui->gamingRound, SIGNAL(timeout()), this, SLOT(timeout()), Qt::UniqueConnection);
    }
}

void Game::hStart(Msg msgMap)
{
    on = true;
    if (msgMap["first"] == "me")
    {
        myRound = true;
    } else {
        myRound = false;
    }
    startNewRound();
    ui->gamingRound->start(myRound);
    connect(battleField, SIGNAL(finishOneRound()), this, SLOT(startNewRound()), Qt::UniqueConnection);
}

void Game::hChangeRound(Msg msgMap)
{
    // 防止循环提醒
    bool i = msgMap["round"] == "my";
    if (i == myRound)
    {
        return;
    }
    startNewRound();
}

void Game::hChangeStrenth(Msg msgMap)
{
    int value = msgMap["value"].toInt();
    int index = msgMap["index"].toInt();
    CardButton * card = battleField->cardsOnBoard.at(index);
    battleField->changeStrenth(value, card, false);
}

void Game::hMove(Msg msgMap)
{
    CardButton* card;
    // 产生新牌
    if (msgMap["fromhand"].toInt() || msgMap["fromEmpty"].toInt())
    {
        qDebug() << "new";
        card = new CardButton(msgMap["id"].toInt(), battleField, nullptr);
    } else {
        qDebug() << "index" << msgMap["index"].toInt();
        card = battleField->cardsOnBoard.at(msgMap["index"].toInt());
    }
    // 改变对方手牌数量
    if (msgMap["fromhand"].toInt())
    {
        qDebug() << "removefromhand";
        battleField->removeCardFromOhand();
        card->card->belongtome = false;
    }
    if (msgMap["tohand"].toInt())
    {
        qDebug() << "addtohand";
        battleField->addCardToOhand();
        battleField->move(nullptr, card, false);
        return;
    }

    // 移动
    if (msgMap["toslot"].toInt())
    {
        qDebug() << "toslot";
        battleField->move(battleField->cardSlot.at(msgMap["to"].toInt()), card, false);
    } else {
        qDebug() << "tostring";
        battleField->move(msgMap["to"], card, false);
    }
}

void Game::hohandChange(Msg msgMap)
{
    int change = msgMap["change"].toInt();
    if (change > 0)
    {
        for (int i = 0; i < change; i++)
        {
            battleField->addCardToOhand();
        }
    } else {
        change = 0 - change;
        for (int i = 0; i < change; i++)
        {
            battleField->removeCardFromOhand();
        }
    }
}

void Game::hSpecialCard(Msg msgMap)
{
    CardButton* card;
    if (msgMap["way"] == "add")
    {
        card = new CardButton(msgMap["id"].toInt(), battleField, nullptr);
    } else {
        card = battleField->cardsOnBoard[msgMap["index"].toInt()];
    }
    battleField->changeSpecialCard(
            battleField->cardSlot.at(msgMap["slot"].toInt()),
            msgMap["way"],
            card,
            false
            );
}

void Game::hoGiveup(Msg msgMap)
{
    giveup[1] = true;
    if (giveup[0] && giveup[1])
    {
        score();
    }
}

