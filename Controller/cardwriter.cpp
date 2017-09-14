#include "cardwriter.h"

// costruisce un oggetto della classe cardWriter settando file e lista
CardWriter::CardWriter(QIODevice* t_file, Lista<Carta*>* t_lista):
                        m_file(t_file), m_lista(t_lista){
    setDevice(m_file);
    setAutoFormatting(true);
}

// distruttore
CardWriter::~CardWriter(){
    delete m_file;
}

// scrive il file xml
void CardWriter::writeFile(){
    writeStartDocument();
    writeStartElement("collezione");

    for(auto it = m_lista->begin(); it != m_lista->end(); ++it){
        writeItem(*it);
    }

    writeEndElement();
    writeEndDocument();
}

// scrive un elemento carta sul file xml
void CardWriter::writeItem(Carta* t_card){
    Magia* magic = dynamic_cast<Magia*>(t_card);
    Creatura* creature = dynamic_cast<Creatura*>(t_card);

    if(magic){
        writeStartElement("magia");
        writeTextElement("nome", magic->getNome());
        writeTextElement("costoMana", QString(QString::number(magic->getCostoMana())));
        writeTextElement("rarita", magic->getRarita());
        writeTextElement("espansione", magic->getEspansione());
        writeTextElement("effetto", magic->getEffetto());
        writeEndElement();
    }
    else if(creature){
        writeStartElement("creatura");
        writeStartElement(creature->getTipoCreatura().toLower());
        writeTextElement("nome", creature->getNome());
        writeTextElement("costoMana", QString(QString::number(creature->getCostoMana())));
        writeTextElement("rarita", creature->getRarita());
        writeTextElement("espansione", creature->getEspansione());
        writeTextElement("effetto", creature->getEffetto());
        writeTextElement("attacco", QString(QString::number(creature->getAttacco())));
        writeTextElement("vita", QString(QString::number(creature->getVita())));
        writeEndElement();
        writeEndElement();
    }
}
















