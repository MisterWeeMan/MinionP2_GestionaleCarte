#include "createviewadminuser.h"

// costruttore di default
CreateViewAdminUser::CreateViewAdminUser(): CreateViewUser(){
    createVariables();
    setFormLayout();

    connect(getSaveButton(), SIGNAL(clicked(bool)),
            this, SLOT(saveAdminInfo()));
    connect(getCancelButton(), SIGNAL(clicked(bool)),
            this, SLOT(close()));
}

// crea le variabili utilizzate nella view
void CreateViewAdminUser::createVariables(){
    m_editNome = new QLineEdit();
    m_editNome->setMaxLength(40);
    m_editCognome = new QLineEdit();
    m_editCognome->setMaxLength(40);
    m_editType = new QComboBox();
    m_editType->insertItem(1, "Admin");
    m_editType->insertItem(2, "Moderatore");
}

// aggiunge campi alla form
void CreateViewAdminUser::setFormLayout(){
    QFormLayout* formLayout = getFormLayout();
    QLabel* nome = new QLabel("Nome: ");
    QLabel* cognome = new QLabel("Cognome: ");
    QLabel* tipo = new QLabel("Tipo: ");
    formLayout->addRow(nome, m_editNome);
    formLayout->addRow(cognome, m_editCognome);
    formLayout->addRow(tipo, m_editType);
}

// controlli sull'input utente
bool CreateViewAdminUser::validateName(QString t_nome) const{
    QRegExp exp("^[a-z]{3,16}$", Qt::CaseInsensitive);
    QRegExpValidator match(exp);
    int pos = 0;
    if(match.validate(t_nome, pos) == QValidator::Acceptable){
        return true;
    }
    else{
        return false;
    }
}

bool CreateViewAdminUser::validateSurname(QString t_cognome) const{
    QRegExp exp("^[a-z]{3,16}$", Qt::CaseInsensitive);
    QRegExpValidator match(exp);
    int pos = 0;
    if(match.validate(t_cognome, pos) == QValidator::Acceptable){
        return true;
    }
    else{
        return false;
    }
}

// getter per i campi della form
QLineEdit* CreateViewAdminUser::getEditNome() const{
    return m_editNome;
}

QLineEdit* CreateViewAdminUser::getEditCognome() const{
    return m_editCognome;
}

QComboBox* CreateViewAdminUser::getEditType() const{
    return m_editType;
}

// slot attivato al premere del tasto salva, prende i dati dalla
// form e li invia con un segnale
void CreateViewAdminUser::saveAdminInfo(){
    QString nome = m_editNome->text();
    QString cognome = m_editCognome->text();
    QString username = getEditUsername()->text();
    QString password = getEditPassword()->text();
    QString email = getEditEmail()->text();
    QString type = m_editType->currentText();

    if(validateUsern(username) && validatePass(password) && validateEmail(email)
            && validateName(nome) && validateSurname(cognome)){
        emit sendAdminInfo(nome, cognome, username, password, email, type);
    }
    else{
        QMessageBox msgErrore;
        msgErrore.setText("Errore nell'input");
        msgErrore.setDetailedText("L'errore può essere stato causato da: \t"
                                  "\n - nome non inserito o formato errato"
                                  "\n - cognome non inserito o formato errato"
                                  "\n - username non inserito o formato errato"
                                  "\n - password non inserita o formato errato"
                                  "\n - email non inserita o formato errato");
        msgErrore.setStyleSheet("QLabel{min-width: 250px;}");
        msgErrore.exec();
    }
}
