#include "magia.h"

// costruttore di default
Magia::Magia(): Carta(){}

// costruisce un oggetto della classe Magia settandone i membri
Magia::Magia(const QString& t_nome, unsigned int t_costoMana,
             const QString& t_rarita, const QString& t_espansione,
             const QString& t_effetto):
                Carta(t_nome, t_costoMana, t_rarita, t_espansione, t_effetto){}

// restituisce il costo base di polvere per gli oggetti della classe Magia
double Magia::costoPolvereBase() const{
    return 100;
}

// restituisce il costo totale di polvere per gli oggetti della classe Magia
double Magia::costoPolvere() const{
    return costoPolvereBase()*rarityMultiply();
}

// ritorna il tipo della classe Magia
QString Magia::getTipoCarta() const{
    return "Magia";
}
