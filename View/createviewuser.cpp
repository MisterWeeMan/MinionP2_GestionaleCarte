#include "createviewuser.h"

// costruttore di default
CreateViewUser::CreateViewUser(): CreateView(){
    createVariables();
    setFormLayout();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(getFormGroupBox());
    mainLayout->addWidget(getButtonsGroupBox());
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
}

// crea le variabili utilizzate nella view
void CreateViewUser::createVariables(){
    m_editUsername = new QLineEdit();
    m_editUsername->setMaxLength(40);
    m_editPassword = new QLineEdit();
    m_editPassword->setEchoMode(QLineEdit::Password);
    m_editPassword->setMaxLength(12);
    m_editEmail = new QLineEdit();
    m_editEmail->setMaxLength(70);
    m_layout = new QFormLayout();
}

// aggiunge campi alla form
void CreateViewUser::setFormLayout(){
    QLabel* username = new QLabel("Username: ");
    QLabel* password = new QLabel("Password: ");
    QLabel* email = new QLabel("E-mail: ");
    m_layout->addRow(username, m_editUsername);
    m_layout->addRow(password, m_editPassword);
    m_layout->addRow(email, m_editEmail);
    QGroupBox* formBox = getFormGroupBox();
    formBox->setLayout(m_layout);
}

// controlli sull'input utente
bool CreateViewUser::validateUsern(QString t_username) const{
    QRegExp exp("^[a-z0-9_]{3,16}$", Qt::CaseInsensitive);
    QRegExpValidator match(exp);
    int pos = 0;
    if(match.validate(t_username, pos) == QValidator::Acceptable){
        return true;
    }
    else{
        return false;
    }
}

bool CreateViewUser::validatePass(QString t_password) const{
    QRegExp exp("^[a-z0-9_]{8,16}$", Qt::CaseInsensitive);
    QRegExpValidator match(exp);
    int pos = 0;
    if(match.validate(t_password, pos) == QValidator::Acceptable){
        return true;
    }
    else{
        return false;
    }
}

bool CreateViewUser::validateEmail(QString t_email) const{
    QRegExp exp("^[a-z0-9]+[_a-z0-9.-]*[a-z0-9]+@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,4})$", Qt::CaseInsensitive);
    QRegExpValidator match(exp);
    int pos = 0;
    if(match.validate(t_email, pos) == QValidator::Acceptable){
        return true;
    }
    else{
        return false;
    }
}

// getter per i campi della form e per il layout
QLineEdit* CreateViewUser::getEditUsername() const{
    return m_editUsername;
}

QLineEdit* CreateViewUser::getEditPassword() const{
    return m_editPassword;
}

QLineEdit* CreateViewUser::getEditEmail() const{
    return m_editEmail;
}

QFormLayout* CreateViewUser::getFormLayout() const{
    return m_layout;
}











