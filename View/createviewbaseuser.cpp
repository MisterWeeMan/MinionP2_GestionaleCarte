#include "createviewbaseuser.h"

// costruttore di default
CreateViewBaseUser::CreateViewBaseUser(): CreateViewUser(){
    createVariables();
    setFormLayout();

    connect(getSaveButton(), SIGNAL(clicked(bool)),
            this, SLOT(saveBaseUserInfo()));
    connect(getCancelButton(), SIGNAL(clicked(bool)),
            this, SLOT(close()));
}

// crea le variabili utilizzate nella view
void CreateViewBaseUser::createVariables(){
    m_editType = new QComboBox();
    m_editType->insertItem(1, "UtenteFree");
    m_editType->insertItem(2, "UtentePro");
}

// aggiunge campi alla form
void CreateViewBaseUser::setFormLayout(){
    QFormLayout* formLayout = getFormLayout();
    QLabel* tipo = new QLabel("Tipo: ");
    formLayout->addRow(tipo, m_editType);
}

// getter per i campi della form
QComboBox* CreateViewBaseUser::getEditType() const{
    return m_editType;
}

// slot attivato al premere del tasto salva, prende i dati dalla
// form e li invia con un segnale
void CreateViewBaseUser::saveBaseUserInfo(){
    QString username = getEditUsername()->text();
    QString password = getEditPassword()->text();
    QString email = getEditEmail()->text();
    QString type = getEditType()->currentText();

    if(validateUsern(username) && validatePass(password) && validateEmail(email)){
        emit sendBaseUserInfo(username, password, email, type);
    }
    else{
        QMessageBox msgErrore;
        msgErrore.setText("Errore nell'input");
        msgErrore.setDetailedText("L'errore può essere stato causato da: \t"
                                  "\n - username non inserito o formato errato"
                                  "\n - password non inserita o formato errato"
                                  "\n - email non inserita o formato errato");
        msgErrore.setStyleSheet("QLabel{min-width: 250px;}");
        msgErrore.exec();
    }
}






















