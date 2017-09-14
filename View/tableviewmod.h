#ifndef TABLEVIEWMOD_H
#define TABLEVIEWMOD_H

#include "tableviewpro.h"

class TableViewMod: public TableViewPro{

    Q_OBJECT

private:

    QPushButton* m_createButton;
    QPushButton* m_deleteButton;

    void createVariables();

public:

    TableViewMod();

    QPushButton* getCreateButton() const;
    QPushButton* getDeleteButton() const;

signals:

    void createCardPushed();
    void deleteCardPushed();

public slots:

    void clickedDeleteCard();

};

#endif
