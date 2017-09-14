#ifndef MODERATORE_H
#define MODERATORE_H

#include "amministratore.h"

class Moderatore: public Amministratore{

public:

    Moderatore();
    Moderatore(const QString&, const QString&, const QString&,
               const QString&, const QString&);

    QString getTipo() const override;

};

#endif
