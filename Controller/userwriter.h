#ifndef USERWRITER_H
#define USERWRITER_H

#include <QXmlStreamWriter>

#include "Model/list.h"
#include "Model/utente.h"
#include "Model/amministratore.h"

class UserWriter: public QXmlStreamWriter{

private:

    QIODevice* m_file;
    Lista<Utente*>* m_lista;

    void writeItem(Utente*);

public:

    UserWriter(QIODevice*, Lista<Utente*>*);
    ~UserWriter();

    void writeFile();

};

#endif
