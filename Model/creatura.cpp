#include "creatura.h"

// costruttore di default
Creatura::Creatura(): Carta(), m_attacco(0), m_vita(0){}

// costruisce un oggetto della classe Carta settando tutti i membri
Creatura::Creatura(const QString& t_nome, unsigned int t_costoMana,
                   const QString& t_rarita, const QString& t_espansione,
                   double t_attacco, double t_vita, const QString& t_effetto):
                    Carta(t_nome, t_costoMana, t_rarita, t_espansione, t_effetto){

    if(t_attacco < 0){
        m_attacco = 0;
    }
    else{
        m_attacco = t_attacco;
    }

    if(t_vita < 0){
        m_vita = 0;
    }
    else{
        m_vita = t_vita;
    }
}

// operatore di uguaglianza
bool Creatura::operator==(const Creatura& t_toCheck){

    return Carta::operator ==(t_toCheck) && getAttacco() == t_toCheck.getAttacco()
            && getVita() == t_toCheck.getVita();
}

// getter e setter per i membri della classe Creatura
double Creatura::getAttacco() const{
    return m_attacco;
}

void Creatura::setAttacco(double t_attacco){

    if(t_attacco < 0){
        m_attacco = 0;
    }
    else{
        m_attacco = t_attacco;
    }
}

double Creatura::getVita() const{
    return m_vita;
}

void Creatura::setVita(double t_vita){

    if(t_vita <0){
        m_vita = 0;
    }
    else{
        m_vita = t_vita;
    }
}

// restituisce il costo base di polvere per gli oggetti
// della classe Creatura
double Creatura::costoPolvereBase() const{
    return 70;
}

// restituisce il costo totale di polvere gli oggetti
// della classe Creatura
double Creatura::costoPolvere() const{
    return costoPolvereBase()*rarityMultiply()*typeMultiply();
}

// restituisce una stringa che identifica il tipo della carta
QString Creatura::getTipoCarta() const{
    return "Creatura";
}









