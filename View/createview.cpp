#include "createview.h"

// costruttore di default
CreateView::CreateView(): QDialog(0, Qt::WindowTitleHint | Qt::WindowSystemMenuHint
                                  | Qt::WindowCloseButtonHint){
    setFixedWidth(300);
    createVariables();
    setButtonsLayout();
}

// crea le variabili utilizzate nella view
void CreateView::createVariables(){
    m_formGroupBox = new QGroupBox();
    m_buttonsGroupBox = new QGroupBox();
    m_saveButton = new QPushButton("Salva");
    m_cancelButton = new QPushButton("Annulla");
}

// setta il layout dei bottoni
void CreateView::setButtonsLayout(){
    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(m_saveButton);
    layout->addWidget(m_cancelButton);
    m_buttonsGroupBox->setLayout(layout);
}

// getter per bottoni e groupBox
QGroupBox* CreateView::getFormGroupBox() const{
    return m_formGroupBox;
}

QGroupBox* CreateView::getButtonsGroupBox() const{
    return m_buttonsGroupBox;
}

QPushButton* CreateView::getSaveButton() const{
    return m_saveButton;
}

QPushButton* CreateView::getCancelButton() const{
    return m_cancelButton;
}





