#include "carta.h"

// costruttore di default
Carta::Carta(): m_nome(""), m_costoMana(0), m_rarita(listRarity[0]),
                m_espansione(listExpansion[0]), m_effetto(""){}

// costruisce un oggetto della classe Carta settando i membri
Carta::Carta(const QString& t_nome, unsigned int t_costoMana,
             const QString& t_rarita, const QString& t_espansione,
             const QString& t_effetto):
                m_nome(t_nome), m_costoMana(t_costoMana), m_effetto(t_effetto){

    if(controlloRarita(t_rarita)){
        m_rarita = t_rarita;
    }
    else{
        m_rarita = listRarity[0];
    }

    if(controlloEspansione(t_espansione)){
        m_espansione = t_espansione;
    }
    else{
        m_espansione = listExpansion[0];
    }
}

// operatore di uguaglianza per Carta
bool Carta::operator==(const Carta& t_check){

    return getNome() == t_check.getNome() && getCostoMana() == t_check.getCostoMana()
            && getRarita() == t_check.getRarita() && getEspansione() == t_check.getEspansione()
            && getEffetto() == t_check.getEffetto();
}

// getter e setter per i membri di carta
QString Carta::getNome() const{
    return m_nome;
}

void Carta::setNome(const QString& t_nome){
    m_nome = t_nome;
}

unsigned int Carta::getCostoMana() const{
    return m_costoMana;
}

void Carta::setCostoMana(unsigned int t_costoMana){
    m_costoMana = t_costoMana;
}

QString Carta::getRarita() const{
    return m_rarita;
}

void Carta::setRarita(const QString& t_rarita){

    if(controlloRarita(t_rarita)){
        m_rarita = t_rarita;
    }
    else{
        m_rarita = listRarity[0];
    }
}

QString Carta::getEspansione() const{
    return m_espansione;
}

void Carta::setEspansione(const QString& t_espansione){

    if(controlloEspansione(t_espansione)){
        m_espansione = t_espansione;
    }
    else{
        m_espansione = listExpansion[0];
    }
}

QString Carta::getEffetto() const{
    return m_effetto;
}

void Carta::setEffetto(const QString& t_effetto){
    m_effetto = t_effetto;
}

// restituisce true se la stringa passata è tra le rarita disponibili, false altrimenti
bool Carta::controlloRarita(const QString& t_rarita){
    bool controlloRarita = false;

    for(auto it = listRarity.begin(); it != listRarity.end(); ++it){
        if(t_rarita == *it){
            controlloRarita = true;
        }
    }

    return controlloRarita;
}

// restituisce true se la stringa passata è tra le espansioni disponibili, false altrimenti
bool Carta::controlloEspansione(const QString& t_espansione){
    bool controlloEspansione = false;

    for(auto it = listExpansion.begin(); it != listExpansion.end(); ++it){
        if(t_espansione == *it){
            controlloEspansione = true;
        }
    }

    return controlloEspansione;
}

const QVector<QString> Carta::listRarity = {"Nessuna", "Comune", "Rara", "Epica", "Leggendaria"};
const QVector<QString> Carta::listExpansion = {"Nessuna", "Base", "Classica", "FIUP League"};

// restituisce il moltiplicatore per il calcolo della polvere in base alla rarità della carta
double Carta::rarityMultiply() const{
    QString rarita = getRarita();

    if(rarita == Carta::listRarity[2]){
        return 2.5;
    }
    else if(rarita == Carta::listRarity[3]){
        return 5;
    }
    else if(rarita == Carta::listRarity[4]){
        return 10;
    }

    return 1;
}


