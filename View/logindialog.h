#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>

class LoginDialog: public QDialog{

    Q_OBJECT

private:

    QLabel* m_usernameLabel;
    QLabel* m_passwordLabel;

    QLineEdit* m_editUsername;
    QLineEdit* m_editPassword;

    QDialogButtonBox* m_buttonsBox;

    void createVariables();
    void createGridLayout();

public:

    LoginDialog();

signals:

    void acceptLogin(const QString& m_usernameLabel,
                     const QString& m_passwordLabel);

public slots:

    void slotAcceptLogin();

};

#endif
