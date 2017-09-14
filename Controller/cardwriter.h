#ifndef CARDWRITER_H
#define CARDWRITER_H

#include <QXmlStreamWriter>

#include "Model/list.h"
#include "Model/magia.h"
#include "Model/creatura.h"

class CardWriter: public QXmlStreamWriter{

private:

    QIODevice* m_file;
    Lista<Carta*>* m_lista;

    void writeItem(Carta*);

public:

    CardWriter(QIODevice*, Lista<Carta*>*);
    ~CardWriter();

    void writeFile();

};

#endif
