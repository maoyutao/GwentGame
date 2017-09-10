#ifndef P_EDIT_H
#define P_EDIT_H

#include "cards.h"
#include "cardset.h"
#include "player.h"
#include "ui_cardslot.h"
#include "ui_cardsetbutton.h"
#include <QWidget>
#include <QStackedWidget>
#include <QList>

namespace Ui {
class MainWindow;
}

class Edit : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Edit(QWidget *parent = nullptr);

    void init(Player * player, Ui::MainWindow *aui);
    void clear();
signals:

public slots:

private:
    Ui::MainWindow *ui{nullptr};
    Player * mplayer{nullptr};
    QList<CardSet *> cardSetList;
    QList<Card*> cardList;
};

#endif // P_EDIT_H
