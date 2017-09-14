#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class ChooseDialog: public QDialog{

    Q_OBJECT

private:

    QGroupBox* m_buttonsGroupBox;
    QPushButton* m_firstButton;
    QPushButton* m_secondButton;
    QLabel* m_message;

    void createVariables();
    void setButtonLayout();
    virtual void setVariables() = 0;

public:

    ChooseDialog();
    virtual ~ChooseDialog() = default;

    QPushButton* getFirstButton() const;
    QPushButton* getSecondButton() const;
    QLabel* getMessage() const;

};

#endif
