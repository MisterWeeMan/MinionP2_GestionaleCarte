#include "admin.h"

// costruttore di default
Admin::Admin(): Amministratore(){}

// costruzione di un oggetto admin
Admin::Admin(const QString& t_username, const QString& t_password,
             const QString& t_email, const QString& t_nome, const QString& t_cognome):
                Amministratore(t_username, t_password, t_email, t_nome, t_cognome){}

// restituisce il tipo dell'utente
QString Admin::getTipo() const{
    return "Admin";
}
