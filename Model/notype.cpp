#include "notype.h"

// costruttore di default
Neutrale::Neutrale(): Creatura(){}

// costruisce un oggetto della classe Neutrale settandone i membri
Neutrale::Neutrale(const QString& t_nome, unsigned int t_costoMana,
                   const QString& t_rarita, const QString& t_espansione,
                   double t_attacco, double t_vita, const QString& t_effetto):
                    Creatura(t_nome, t_costoMana, t_rarita, t_espansione,
                             t_attacco, t_vita, t_effetto){}

// calcolo dell'attacco per la classe Neutrale
double Neutrale::attaccoTotale() const{
    return getAttacco()*3;
}

// calcolo della vita per la classe Neutrale
double Neutrale::vitaTotale() const{
    return getVita()*4.5;
}

// restituisce il moltiplicatore per il calcolo del
// costo di mana per la classe Neutrale
double Neutrale::typeMultiply() const{
    return 2;
}

// ritorna il tipo della classe Neutrale
QString Neutrale::getTipoCreatura() const{
    return "Neutrale";
}

// ritorna l'effetto base per la classe Neutrale
QString Neutrale::getEffettoBase() const{
    return "Quando 2 o piu' creature di tipo neutrale sono "
           "nel tuo lato del campo alla fine del turno del "
           "tuo avversario, pesca una carta in piu'";
}











