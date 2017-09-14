#include "demone.h"

// costruttore di default
Demone::Demone(): Creatura(){}

// costruisce un oggetto della classe Demone settandone i membri
Demone::Demone(const QString& t_nome, unsigned int t_costoMana,
               const QString& t_rarita, const QString& t_espansione,
               double t_attacco, double t_vita, const QString& t_effetto):
                Creatura(t_nome, t_costoMana, t_rarita, t_espansione,
                         t_attacco, t_vita, t_effetto){}

// calcolo dell'attacco per la classe Demone
double Demone::attaccoTotale() const{
    return getAttacco()*5.5;
}

// calcolo della vita per la classe Demone
double Demone::vitaTotale() const{
    return getVita()*5;
}

// restituisce il moltiplicatore per il calcolo del
// costo di polvere per la classe Demone
double Demone::typeMultiply() const{
    return 4.5;
}

// ritorna il tipo della classe Demone
QString Demone::getTipoCreatura() const{
    return "Demone";
}

// ritorna l'effetto base per la classe Demone
QString Demone::getEffettoBase() const{
    return "Quando 2 o piu' creature di tipo demone sono nel tuo lato "
           "del campo alla fine del turno del tuo avversario, "
           "il tuo avversario scarta una carta casuale dalla mano";
}

