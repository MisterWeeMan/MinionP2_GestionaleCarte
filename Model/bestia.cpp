#include "bestia.h"

// costruzione di default
Bestia::Bestia(): Creatura(){}

// costruisce un oggetto della classe Bestia settandone i membri
Bestia::Bestia(const QString& t_nome, unsigned int t_costoMana,
               const QString& t_rarita, const QString& t_espansione,
               double t_attacco, double t_vita, const QString& t_effetto):
                Creatura(t_nome, t_costoMana, t_rarita, t_espansione,
                         t_attacco, t_vita, t_effetto){}

// calcolo dell'attacco per la classe Bestia
double Bestia::attaccoTotale() const{
    return getAttacco()*2.5;
}

// calcolo della vita per la classe Bestia
double Bestia::vitaTotale() const{
    return getVita()*7;
}

// restituisce il moltiplicatore per il calcolo del
// costo di mana per la classe Bestia
double Bestia::typeMultiply() const{
    return 3.5;
}

// ritorna il tipo della classe Bestia
QString Bestia::getTipoCreatura() const{
    return "Bestia";
}

// ritorna l'effetto base per la classe Bestia
QString Bestia::getEffettoBase() const{
    return "Per ogni creatura di tipo bestia, alla fine del turno infliggi "
           "1 danno a 3 nemici casuali";
}
