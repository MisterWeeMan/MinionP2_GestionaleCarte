#include "tableviewadmin.h"

// costruttore di default
TableViewAdmin::TableViewAdmin(): TableViewMod(){
    createVariables();
    setRadioLayout();
    setLabel("Benvenuto Admin");
    getMainLayout()->addWidget(m_radioButtons);

    connect(m_radio1, SIGNAL(toggled(bool)), this, SLOT(radio1Toggle(bool)));
    connect(m_radio2, SIGNAL(toggled(bool)), this, SLOT(radio2Toggle(bool)));

    disconnect(getCreateButton(), SIGNAL(clicked(bool)), this, SIGNAL(createCardPushed()));
    disconnect(getModifyButton(), SIGNAL(clicked(bool)), this, SLOT(clickedModifyCard()));
    disconnect(getDeleteButton(), SIGNAL(clicked(bool)), this, SLOT(clickedDeleteCard()));

    connect(getCreateButton(), SIGNAL(clicked(bool)), this, SLOT(createButtonClicked()));
    connect(getModifyButton(), SIGNAL(clicked(bool)), this, SLOT(modifyButtonClicked()));
    connect(getDeleteButton(), SIGNAL(clicked(bool)), this, SLOT(deleteButtonClicked()));
}

// creo variabili per la view
void TableViewAdmin::createVariables(){
    m_radioButtons = new QGroupBox();
    m_radio1 = new QRadioButton("Carte");
    m_radio2 = new QRadioButton("Utenti");
}

// setta il layout per i bottoni radio
void TableViewAdmin::setRadioLayout(){
    QHBoxLayout* radioLayout = new QHBoxLayout();
    m_radio1->setChecked(true);
    radioLayout->addWidget(m_radio1);
    radioLayout->addWidget(m_radio2);
    m_radioButtons->setLayout(radioLayout);
}

// se un radio button viene cliccato viene cambiata la tabella
void TableViewAdmin::radio1Toggle(bool checked){
    if(checked){
        emit setCardTable();
    }
}

void TableViewAdmin::radio2Toggle(bool checked){
    if(checked){
        emit setUserTable();
    }
}

// lancia il segnale di creazione in base a quale bottone
// radio è selezionato
void TableViewAdmin::createButtonClicked(){
    if(m_radio1->isChecked()){
        emit createCardPushed();
    }
    else if(m_radio2->isChecked()){
        emit createUserPushed();
    }
}

// lancia il segnale di modifica se una riga è selezionata e
// in base a quale bottone radio è selezionato, se nessuna
// riga è selezionata allora lancio un messaggio di errore
void TableViewAdmin::modifyButtonClicked(){
    if(m_radio1->isChecked()){
        if(getTable()->currentRow() == -1){
            QMessageBox msgBox;
            msgBox.setText("Nessuna carta selezionata da modificare");
            msgBox.exec();
        }
        else{
            emit modifyCardPushed();
        }
    }
    else if(m_radio2->isChecked()){
        if(getTable()->currentRow() == -1){
            QMessageBox msgBox;
            msgBox.setText("Nessun utente selezionato da modificare");
            msgBox.exec();
        }
        else{
            emit modifyUserPushed();
        }
    }
}

// lancia il segnale di eliminazione se una riga è selezionata e
// in base a quale bottone radio è selezionato, se nessuna
// riga è selezionata allora lancio un messaggio di errore
void TableViewAdmin::deleteButtonClicked(){
    if(m_radio1->isChecked()){
        if(getTable()->currentRow() == -1){
            QMessageBox msgBox;
            msgBox.setText("Nessuna carta selezionata da eliminare");
            msgBox.exec();
        }
        else{
            emit deleteCardPushed();
        }
    }
    else if(m_radio2->isChecked()){
        if(getTable()->currentRow() == -1){
            QMessageBox msgBox;
            msgBox.setText("Nessun utente selezionato da eliminare");
            msgBox.exec();
        }
        else{
            emit deleteUserPushed();
        }
    }
}


