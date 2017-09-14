#ifndef UTENTEPRO_H
#define UTENTEPRO_H

#include "utente.h"

class UtentePro: public Utente{

public:

    UtentePro();
    UtentePro(const QString&, const QString&, const QString&);

    QString getTipo() const override;

};

#endif
