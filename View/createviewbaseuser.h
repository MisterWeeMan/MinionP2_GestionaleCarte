#ifndef CREATEVIEWBASEUSER_H
#define CREATEVIEWBASEUSER_H

#include "createviewuser.h"

class CreateViewBaseUser: public CreateViewUser{

    Q_OBJECT

private:

    QComboBox* m_editType;

    void createVariables() override;
    void setFormLayout() override;

public:

    CreateViewBaseUser();

    QComboBox* getEditType() const;

signals:

    void sendBaseUserInfo(const QString&, const QString&,
                          const QString&, const QString&);

public slots:

    void saveBaseUserInfo();

};

#endif
