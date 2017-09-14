#include "moderatore.h"

// costruttore di default
Moderatore::Moderatore(): Amministratore(){}

// costruisce un oggetto della classe Moderatore settandone i membri
Moderatore::Moderatore(const QString& t_username, const QString& t_password,
                       const QString& t_email, const QString& t_nome,
                       const QString& t_cognome):
                        Amministratore(t_username, t_password, t_email, t_nome,
                                       t_cognome){}

// ritorna il tipo della classe Moderatore
QString Moderatore::getTipo() const{
    return "Moderatore";
}
