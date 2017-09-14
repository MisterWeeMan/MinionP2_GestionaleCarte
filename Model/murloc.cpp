#include "murloc.h"

// costruttore di default
Murloc::Murloc(): Creatura(){}

// costruisce un oggetto della classe Murloc settandone i membri
Murloc::Murloc(const QString& t_nome, unsigned int t_costoMana,
               const QString& t_rarita, const QString& t_espansione,
               double t_attacco, double t_vita, const QString& t_effetto):
                Creatura(t_nome, t_costoMana, t_rarita, t_espansione,
                         t_attacco, t_vita, t_effetto){}

// calcolo dell'attacco per la classe Murloc
double Murloc::attaccoTotale() const{
    return getAttacco()*2;
}

// calcolo della vita per la classe Murloc
double Murloc::vitaTotale() const{
    return getVita()*4;
}

// restituisce il moltiplicatore per il calcolo del
// costo di mana per la classe Murloc
double Murloc::typeMultiply() const{
    return 2.5;
}

// ritorna il tipo della classe Murloc
QString Murloc::getTipoCreatura() const{
    return "Murloc";
}

// ritorna l'effetto base per la classe Murloc
QString Murloc::getEffettoBase() const{
    return "Ogni qual volta una creatura di tipo murloc "
           "viene evocata, evoca un token di tipo murloc 2/2";
}
