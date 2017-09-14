#ifndef USERREADER_H
#define USERREADER_H

#include <QXmlStreamReader>

#include "Model/list.h"
#include "Model/utentefree.h"
#include "Model/moderatore.h"
#include "Model/utentepro.h"
#include "Model/admin.h"

class UserReader: public QXmlStreamReader{

private:

    QIODevice* m_file;
    Lista<Utente*>* m_lista;

    void readXML();
    void readBaseUser();
    void readAdminUser();

public:

    UserReader(QIODevice*, Lista<Utente*>*);
    ~UserReader();

    void readFile();

};

#endif
