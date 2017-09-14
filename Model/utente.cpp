#include "utente.h"

// costruttore di default
Utente::Utente(): m_username(""), m_password(""), m_email(""){}

// costruisce un oggetto della classe Utente settandone i membri
Utente::Utente(const QString& t_username, const QString& t_password,
               const QString& t_email):
                m_username(t_username), m_password(t_password),
                m_email(t_email){}

// operatore uguaglianza
bool Utente::operator==(const Utente& t_check){
    return getUsername() == t_check.getUsername();
}

// getter e setter per i membri della classe
QString Utente::getUsername() const{
    return m_username;
}

void Utente::setUsername(const QString& t_username){
    m_username = t_username;
}

QString Utente::getPassword() const{
    return m_password;
}

void Utente::setPassword(const QString& t_password){
    m_password = t_password;
}

QString Utente::getEmail() const{
    return m_email;
}

void Utente::setEmail(const QString& t_email){
    m_email = t_email;
}
