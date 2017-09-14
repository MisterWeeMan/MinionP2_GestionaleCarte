#include "utentefree.h"

// costruttore di default
UtenteFree::UtenteFree(): Utente(){}

// costruisce un oggetto della classe UtenteFree settandone i membri
UtenteFree::UtenteFree(const QString& t_username, const QString& t_password,
                       const QString& t_email):
                        Utente(t_username, t_password, t_email){}

// restituisce il tipo dell'utente
QString UtenteFree::getTipo() const{
    return "UtenteFree";
}
