#include "tableviewpro.h"

// costruttore di default
TableViewPro::TableViewPro(): TableView(){
    createVariables();
    setButtonsLayout();
    setLabel("Benvenuto UtentePro");
    getMainLayout()->addWidget(m_doStuffButtons);

    connect(m_modifyButton, SIGNAL(clicked(bool)),
            this, SLOT(clickedModifyCard()));
}

// creo variabili per la view
void TableViewPro::createVariables(){
    m_doStuffButtons = new QGroupBox();
    m_buttonsLayout = new QHBoxLayout();
    m_modifyButton = new QPushButton("Modifica");
    m_modifyButton->setFixedWidth(150);
}

// setta il layout per i bottoni
void TableViewPro::setButtonsLayout(){
    m_buttonsLayout->addWidget(m_modifyButton);
    m_doStuffButtons->setLayout(m_buttonsLayout);
}

// getter per bottone e layout
QHBoxLayout* TableViewPro::getButtonLayout() const{
    return m_buttonsLayout;
}

QPushButton* TableViewPro::getModifyButton() const{
    return m_modifyButton;
}

// se una riga è selezionata allora viene lanciato un segnale
// per la modifica della carta selezionata, altrimenti lancia
// un messaggio di errore
void TableViewPro::clickedModifyCard(){
    if(getTable()->currentRow() == -1){
        QMessageBox msgBox;
        msgBox.setText("Nessuna carta selezionata da modificare");
        msgBox.exec();
    }
    else{
        emit modifyCardPushed();
    }
}














