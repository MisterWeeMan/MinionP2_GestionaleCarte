#ifndef UTENTEFREE_H
#define UTENTEFREE_H

#include "utente.h"

class UtenteFree: public Utente{

public:

    UtenteFree();
    UtenteFree(const QString&, const QString&, const QString&);

    QString getTipo() const override;

};

#endif
