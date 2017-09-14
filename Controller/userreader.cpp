#include "userreader.h"

// costruisce un oggetto userReader settando file e lista
UserReader::UserReader(QIODevice* t_file, Lista<Utente*>* t_list):
                        m_file(t_file), m_lista(t_list){
    setDevice(m_file);
}

// distruttore
UserReader::~UserReader(){
    delete m_file;
}

// legge il file
void UserReader::readFile(){
    if(readNextStartElement()){
        if(name() == "utenti"){
            readXML();
        }
    }
}

// legge il file dal secondo elemento
void UserReader::readXML(){
    while(readNextStartElement()){
        if(name() == "utentefree" || name() == "utentepro"){
            readBaseUser();
        }
        else if(name() == "amministratore"){
            readAdminUser();
        }
    }
}

// legge i dati di un utente base
void UserReader::readBaseUser(){
    Utente* newUser = nullptr;

    if(name() == "utentefree"){
        newUser = new UtenteFree();
    }
    else if(name() == "utentepro"){
        newUser = new UtentePro();
    }

    readNextStartElement();

    while(!(isEndElement() && (name() == "utentefree" || name() == "utentepro"))){
        if(isStartElement()){
            if(name() == "username"){
                newUser->setUsername(readElementText());
            }
            else if(name() == "password"){
                newUser->setPassword(readElementText());
            }
            else if(name() == "email"){
                newUser->setEmail(readElementText());
            }
            else{
                skipCurrentElement();
            }
        }
        else{
            readNext();
        }
    }

    m_lista->push_back(newUser);
    newUser = nullptr;
}

// legge i dati di un utente amministratore
void UserReader::readAdminUser(){
    Amministratore* newUser = nullptr;
    readNextStartElement();

    if(name() == "moderatore"){
        newUser = new Moderatore();
    }
    else if(name() == "admin"){
        newUser = new Admin();
    }

    readNextStartElement();

    while(!(isEndElement() && name() == "amministratore")){
        if(isStartElement()){
            if(name() == "nome"){
                newUser->setNome(readElementText());
            }
            else if(name() == "cognome"){
                newUser->setCognome(readElementText());
            }
            else if(name() == "username"){
                newUser->setUsername(readElementText());
            }
            else if(name() == "password"){
                newUser->setPassword(readElementText());
            }
            else if(name() == "email"){
                newUser->setEmail(readElementText());
            }
            else{
                skipCurrentElement();
            }
        }
        else{
            readNext();
        }
    }

    m_lista->push_back(newUser);
    newUser = nullptr;
}










