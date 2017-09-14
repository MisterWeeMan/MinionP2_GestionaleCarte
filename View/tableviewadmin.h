#ifndef TABLEVIEWADMIN_H
#define TABLEVIEWADMIN_H

#include "tableviewmod.h"

class TableViewAdmin: public TableViewMod{

    Q_OBJECT

private:

    QGroupBox* m_radioButtons;
    QRadioButton* m_radio1;
    QRadioButton* m_radio2;

    void createVariables();
    void setRadioLayout();

public:

    TableViewAdmin();

signals:

    void setUserTable();
    void setCardTable();

    void createUserPushed();
    void modifyUserPushed();
    void deleteUserPushed();

public slots:

    void radio1Toggle(bool);
    void radio2Toggle(bool);

    void createButtonClicked();
    void modifyButtonClicked();
    void deleteButtonClicked();

};

#endif
