#include "amministratore.h"

// costruzione di default
Amministratore::Amministratore(): Utente(), m_nome(""), m_cognome(""){}

// costruzione di un oggetto Amministratore settando tutti membri
Amministratore::Amministratore(const QString& t_username, const QString& t_password,
                               const QString& t_email, const QString& t_nome, const QString& t_cognome):
                                Utente(t_username, t_password, t_email), m_nome(t_nome), m_cognome(t_cognome){}

// getter e setter per i membri di Amministratore
QString Amministratore::getNome() const{
    return m_nome;
}

void Amministratore::setNome(const QString& t_nome){
    m_nome = t_nome;
}

QString Amministratore::getCognome() const{
    return m_cognome;
}

void Amministratore::setCognome(const QString& t_cognome){
    m_cognome = t_cognome;
}
