#include "drago.h"

// costruttore di default
Drago::Drago(): Creatura(){}

// costruisce un oggetto della classe Drago settandone i membri
Drago::Drago(const QString& t_nome, unsigned int t_costoMana,
             const QString& t_rarita, const QString& t_espansione,
             double t_attacco, double t_vita, const QString& t_effetto):
                Creatura(t_nome, t_costoMana, t_rarita, t_espansione,
                         t_attacco, t_vita, t_effetto){}

// calcolo dell'attacco per la classe Drago
double Drago::attaccoTotale() const{
    return getAttacco()*8;
}

// calcolo della vita per la classe Drago
double Drago::vitaTotale() const{
    return getVita()*5;
}

// restituisce il moltiplicatore per il calcolo del
// costo di mana per la classe Drago
double Drago::typeMultiply() const{
    return 6;
}

// ritorna il tipo della classe Drago
QString Drago::getTipoCreatura() const{
    return "Drago";
}

// ritorna l'effetto base per la classe Drago
QString Drago::getEffettoBase() const{
    return "Quando 3 o piu' creature di tipo drago sono nel tuo "
           "lato del campo distruggi una creatura "
           "nemica casuale alla fine del tuo turno";
}
