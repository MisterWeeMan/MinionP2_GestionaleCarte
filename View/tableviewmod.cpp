#include "tableviewmod.h"

// costruttore di default
TableViewMod::TableViewMod(): TableViewPro(){
    createVariables();
    setLabel("Benvenuto Moderatore");
    getButtonLayout()->addWidget(m_createButton);
    getButtonLayout()->addWidget(m_deleteButton);

    connect(m_createButton, SIGNAL(clicked(bool)),
            this, SIGNAL(createCardPushed()));
    connect(m_deleteButton, SIGNAL(clicked(bool)),
            this, SLOT(clickedDeleteCard()));
}

// creo variabili per la view
void TableViewMod::createVariables(){
    m_createButton = new QPushButton("Crea");
    m_deleteButton = new QPushButton("Elimina");
    m_createButton->setFixedWidth(150);
    m_deleteButton->setFixedWidth(150);
}

// getter per i bottoni
QPushButton* TableViewMod::getCreateButton() const{
    return m_createButton;
}

QPushButton* TableViewMod::getDeleteButton() const{
    return m_deleteButton;
}

// se una riga è selezionata allora viene lanciato un segnale
// per l'eliminazione della carta selezionata, altrimenti lancia
// un messaggio di errore
void TableViewMod::clickedDeleteCard(){
    if(getTable()->currentRow() == -1){
        QMessageBox msgBox;
        msgBox.setText("Nessuna carta selezionata da eliminare");
        msgBox.exec();
    }
    else{
        emit deleteCardPushed();
    }
}




