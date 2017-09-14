#ifndef TABLEVIEWPRO_H
#define TABLEVIEWPRO_H

#include "tableview.h"

class TableViewPro: public TableView{

    Q_OBJECT

private:

    QGroupBox* m_doStuffButtons;
    QHBoxLayout* m_buttonsLayout;
    QPushButton* m_modifyButton;

    void createVariables();
    void setButtonsLayout();

public:

    TableViewPro();

    QHBoxLayout* getButtonLayout() const;
    QPushButton* getModifyButton() const;

signals:

    void modifyCardPushed();

public slots:

    void clickedModifyCard();

};

#endif
