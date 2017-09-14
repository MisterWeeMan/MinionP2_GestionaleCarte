#ifndef UTENTE_H
#define UTENTE_H

#include <QString>

class Utente{

private:

    QString m_username;
    QString m_password;
    QString m_email;

public:

    Utente();
    Utente(const QString&, const QString&, const QString&);
    virtual ~Utente() = default;

    bool operator==(const Utente&);

    QString getUsername() const;
    void setUsername(const QString&);

    QString getPassword() const;
    void setPassword(const QString&);

    QString getEmail() const;
    void setEmail(const QString&);

    virtual QString getTipo() const = 0;

};

#endif
