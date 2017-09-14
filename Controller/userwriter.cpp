#include "userwriter.h"

// costruisce un oggetto della classe userWriter settando file e lista
UserWriter::UserWriter(QIODevice* t_file, Lista<Utente*>* t_lista):
                        m_file(t_file), m_lista(t_lista){
    setDevice(m_file);
    setAutoFormatting(true);
}

// distruttore
UserWriter::~UserWriter(){
    delete m_file;
}

// scrive il file xml
void UserWriter::writeFile(){
    writeStartDocument();
    writeStartElement("utenti");

    for(auto it = m_lista->begin(); it != m_lista->end(); ++it){
        writeItem(*it);
    }

    writeEndElement();
    writeEndDocument();
}

// scriver un elemento utente sul file xml
void UserWriter::writeItem(Utente* user){
    QString type = user->getTipo().toLower();

    if(type == "admin" || type == "moderatore"){
        Amministratore* adminUser = dynamic_cast<Amministratore*>(user);
        writeStartElement("amministratore");
        writeStartElement(adminUser->getTipo().toLower());
        writeTextElement("nome", adminUser->getNome());
        writeTextElement("cognome", adminUser->getCognome());
        writeTextElement("username", adminUser->getUsername());
        writeTextElement("password", adminUser->getPassword());
        writeTextElement("email", adminUser->getEmail());
        writeEndElement();
        writeEndElement();
    }
    else if(type == "utentefree" || type == "utentepro"){
        writeStartElement(user->getTipo().toLower());
        writeTextElement("username", user->getUsername());
        writeTextElement("password", user->getPassword());
        writeTextElement("email", user->getEmail());
        writeEndElement();
    }
}
