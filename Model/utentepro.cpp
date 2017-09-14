#include "utentepro.h"

// costruttore di default
UtentePro::UtentePro(): Utente(){}

// costruisce un oggetto della classe UtentePro settandone i membri
UtentePro::UtentePro(const QString& t_username, const QString& t_password,
                     const QString& t_email):
                        Utente(t_username, t_password, t_email){}

// restituisce il tipo dell'utente
QString UtentePro::getTipo() const{
    return "UtentePro";
}

