#include "cardreader.h"

// costruisce un oggetto della classe cardReader settando file e lista
CardReader::CardReader(QIODevice* t_file, Lista<Carta*>* t_list):
                        m_file(t_file), m_lista(t_list){
    setDevice(m_file);
}

// distruttore
CardReader::~CardReader(){
    delete m_file;
}

// legge il file
void CardReader::readFile(){
    if(readNextStartElement()){
        if(name() == "collezione"){
            readXml();
        }
    }
}

// legge il file dal secondo elemento
void CardReader::readXml(){
    while(readNextStartElement()){
        if(name() == "magia"){
            readMagia();
        }
        else if(name() == "creatura"){
            readCreatura();
        }
    }
}

// legge i dati di una carta magia
void CardReader::readMagia(){
    Carta* newCard = new Magia();
    readNextStartElement();

    while(!(isEndElement() && name() == "magia")){
        if(isStartElement()){
            if(name() == "nome"){
                newCard->setNome(readElementText());
            }
            else if(name() == "costoMana"){
                newCard->setCostoMana(readElementText().toInt());
            }
            else if(name() == "rarita"){
                newCard->setRarita(readElementText());
            }
            else if(name() == "espansione"){
                newCard->setEspansione(readElementText());
            }
            else if(name() == "effetto"){
                newCard->setEffetto(readElementText());
            }
            else{
                skipCurrentElement();
            }
        }
        else{
            readNext();
        }
    }

    m_lista->push_back(newCard);
    newCard = nullptr;
}

// legge i dati di una carta creatura
void CardReader::readCreatura(){
    Creatura* newCard = nullptr;
    readNextStartElement();

    if(name() == "neutrale"){
        newCard = new Neutrale();
    }
    else if(name() == "drago"){
        newCard = new Drago();
    }
    else if(name() == "bestia"){
        newCard = new Bestia();
    }
    else if(name() == "demone"){
        newCard = new Demone();
    }
    else if(name() == "pirata"){
        newCard = new Pirata();
    }
    else if(name() == "murloc"){
        newCard = new Murloc();
    }

    readNextStartElement();

    while(!(isEndElement() && name() == "creatura")){
        if(isStartElement()){
            if(name() == "nome"){
                newCard->setNome(readElementText());
            }
            else if(name() == "costoMana"){
                newCard->setCostoMana(readElementText().toInt());
            }
            else if(name() == "rarita"){
                newCard->setRarita(readElementText());
            }
            else if(name() == "espansione"){
                newCard->setEspansione(readElementText());
            }
            else if(name() == "effetto"){
                newCard->setEffetto(readElementText());
            }
            else if(name() == "attacco"){
                newCard->setAttacco(readElementText().toDouble());
            }
            else if(name() == "vita"){
                newCard->setVita(readElementText().toDouble());
            }
            else{
                skipCurrentElement();
            }
        }
        else{
            readNext();
        }
    }

    m_lista->push_back(newCard);
    newCard = nullptr;
}
