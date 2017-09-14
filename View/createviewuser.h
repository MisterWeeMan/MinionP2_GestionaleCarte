#ifndef CREATEVIEWUSER_H
#define CREATEVIEWUSER_H

#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QFormLayout>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>

#include "createview.h"

class CreateViewUser: public CreateView{

    Q_OBJECT

private:

    QLineEdit* m_editUsername;
    QLineEdit* m_editPassword;
    QLineEdit* m_editEmail;
    QFormLayout* m_layout;

    void createVariables() override;
    void setFormLayout() override;

public:

    CreateViewUser();

    bool validateUsern(QString) const;
    bool validatePass(QString) const;
    bool validateEmail(QString) const;

    QLineEdit* getEditUsername() const;
    QLineEdit* getEditPassword() const;
    QLineEdit* getEditEmail() const;
    QFormLayout* getFormLayout() const;

};

#endif
