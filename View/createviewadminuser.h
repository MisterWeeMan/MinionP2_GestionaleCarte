#ifndef CREATEVIEWADMINUSER_H
#define CREATEVIEWADMINUSER_H

#include "createviewuser.h"

class CreateViewAdminUser: public CreateViewUser{

    Q_OBJECT

private:

    QLineEdit* m_editNome;
    QLineEdit* m_editCognome;
    QComboBox* m_editType;

    void createVariables() override;
    void setFormLayout() override;

public:

    CreateViewAdminUser();

    bool validateName(QString) const;
    bool validateSurname(QString) const;

    QLineEdit* getEditNome() const;
    QLineEdit* getEditCognome() const;
    QComboBox* getEditType() const;

signals:

    void sendAdminInfo(const QString&, const QString&, const QString&,
                       const QString&, const QString&, const QString&);

public slots:

    void saveAdminInfo();

};

#endif
