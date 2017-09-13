#ifndef P_EDIT_H
#define P_EDIT_H

#include "cards/index.h"
#include "cardset.h"
#include "player.h"
#include "ui_cardslot.h"
#include "ui_cardsetbutton.h"
#include "ui_cardbutton.h"
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

private slots:
    void enterEdit(CardSet * cardSet);
    void addToSet(CardButton* card);
    void removeFromSet(CardButton* card);
    void returnToChoose();

private:
    QList<int> tempSet;
    CardSet* currentSet{nullptr};
    Ui::MainWindow *ui{nullptr};
    Player * mplayer{nullptr};
    QList<CardSet *> cardSetList;
    QList<CardButton*> cardList;
};

#endif // P_EDIT_H
