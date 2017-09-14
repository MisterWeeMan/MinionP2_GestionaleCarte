#include "logindialog.h"

// costruttore di default
LoginDialog::LoginDialog(): QDialog(0, Qt::WindowTitleHint | Qt::WindowSystemMenuHint
                                    | Qt::WindowCloseButtonHint){
    setFixedSize(300, 150);
    createVariables();
    setWindowTitle("Minionstone Login");
    setModal(true);
    createGridLayout();

    connect(m_buttonsBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()),
            this, SLOT(slotAcceptLogin()));

    connect(m_buttonsBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()),
            this, SLOT(close()));
}

// crea le variabili utilizzate nella view
void LoginDialog::createVariables(){
    m_editUsername = new QLineEdit();
    m_editPassword = new QLineEdit();
    m_editPassword->setEchoMode(QLineEdit::Password);
    m_usernameLabel = new QLabel();
    m_usernameLabel->setText("Username");
    m_usernameLabel->setBuddy(m_editUsername);
    m_passwordLabel = new QLabel();
    m_passwordLabel->setText("Password");
    m_passwordLabel->setBuddy(m_editPassword);
    m_buttonsBox = new QDialogButtonBox();
    m_buttonsBox->addButton(QDialogButtonBox::Ok);
    m_buttonsBox->addButton(QDialogButtonBox::Cancel);
    m_buttonsBox->button(QDialogButtonBox::Ok)->setText("Accedi");
    m_buttonsBox->button(QDialogButtonBox::Cancel)->setText("Chiudi");
}

// crea il layout a griglia
void LoginDialog::createGridLayout(){
    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(m_usernameLabel, 0, 0);
    gridLayout->addWidget(m_editUsername, 0, 1);
    gridLayout->addWidget(m_passwordLabel, 1, 0);
    gridLayout->addWidget(m_editPassword, 1, 1);
    gridLayout->addWidget(m_buttonsBox, 2, 0, 1, 2);
    setLayout(gridLayout);
}

// slot attivato al premere del tasto accedi, prende i dati dalla
// form e li invia con un segnale
void LoginDialog::slotAcceptLogin(){
    emit acceptLogin(m_editUsername->text(), m_editPassword->text());
}
