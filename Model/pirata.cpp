#include "pirata.h"

// costruttore di default
Pirata::Pirata(): Creatura(){}

// costruisce un oggetto della classe Pirata settandone i membri
Pirata::Pirata(const QString& t_nome, unsigned int t_costoMana,
               const QString& t_rarita, const QString& t_espansione,
               double t_attacco, double t_vita, const QString& t_effetto):
                Creatura(t_nome, t_costoMana, t_rarita, t_espansione,
                         t_attacco, t_vita, t_effetto){}

// calcolo dell'attacco per la classe Pirata
double Pirata::attaccoTotale() const{
    return getAttacco()*5;
}

// calcolo della vita per la classe Pirata
double Pirata::vitaTotale() const{
    return getVita()*2.5;
}

// restituisce il moltiplicatore per il calcolo del
// costo di mana per la classe Pirata
double Pirata::typeMultiply() const{
    return 3;
}

// ritorna il tipo della classe Pirata
QString Pirata::getTipoCreatura() const{
    return "Pirata";
}

// ritorna l'effetto base per la classe Pirata
QString Pirata::getEffettoBase() const{
    return "Quando una creatura di tipo pirata viene evocata "
           "guadagna 'carica' se controlli già un'altra creatura di "
           "tipo pirata";
}
