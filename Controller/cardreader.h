#ifndef CARDREADER_H
#define CARDREADER_H

#include <QXmlStreamReader>

#include "Model/list.h"
#include "Model/magia.h"
#include "Model/notype.h"
#include "Model/drago.h"
#include "Model/bestia.h"
#include "Model/demone.h"
#include "Model/pirata.h"
#include "Model/murloc.h"

class CardReader: public QXmlStreamReader{

private:

    QIODevice* m_file;
    Lista<Carta*>* m_lista;

    void readMagia();
    void readCreatura();
    void readXml();

public:

    CardReader(QIODevice*, Lista<Carta*>*);
    ~CardReader();

    void readFile();

};

#endif
