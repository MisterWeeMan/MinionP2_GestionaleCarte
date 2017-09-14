#ifndef CREATEVIEW_H
#define CREATEVIEW_H

#include <QDialog>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>

class CreateView: public QDialog{

    Q_OBJECT

private:

    QGroupBox* m_formGroupBox;
    QGroupBox* m_buttonsGroupBox;

    QPushButton* m_saveButton;
    QPushButton* m_cancelButton;

    virtual void createVariables();
    virtual void setFormLayout() = 0;
    void setButtonsLayout();

public:

    CreateView();
    virtual ~CreateView() = default;

    QGroupBox* getFormGroupBox() const;
    QGroupBox* getButtonsGroupBox() const;
    QPushButton* getSaveButton() const;
    QPushButton* getCancelButton() const;

};

#endif
