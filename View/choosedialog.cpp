#include "choosedialog.h"

// costruttore di default
ChooseDialog::ChooseDialog(): QDialog(0, Qt::WindowTitleHint | Qt::WindowSystemMenuHint
                                      | Qt::WindowCloseButtonHint){
    setModal(true);
    createVariables();
    setButtonLayout();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_message);
    mainLayout->addWidget(m_buttonsGroupBox);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
}

// crea le variabili della view
void ChooseDialog::createVariables(){
    m_buttonsGroupBox = new QGroupBox();
    m_firstButton = new QPushButton();
    m_secondButton = new QPushButton();
    m_message = new QLabel();
}

// crea il layout per i bottoni e lo inserisce in un group box
void ChooseDialog::setButtonLayout(){
    QVBoxLayout* buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(m_firstButton);
    buttonLayout->addWidget(m_secondButton);
    m_buttonsGroupBox->setLayout(buttonLayout);
}

// getter per bottoni e label
QPushButton* ChooseDialog::getFirstButton() const{
    return m_firstButton;
}

QPushButton* ChooseDialog::getSecondButton() const{
    return m_secondButton;
}

QLabel* ChooseDialog::getMessage() const{
    return m_message;
}


