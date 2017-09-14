#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H

#include "utente.h"

class Amministratore: public Utente{

private:

    QString m_nome;
    QString m_cognome;

public:

    Amministratore();
    Amministratore(const QString&, const QString&, const QString&, const QString&, const QString&);

    QString getNome() const;
    void setNome(const QString&);

    QString getCognome() const;
    void setCognome(const QString&);

};

#endif
