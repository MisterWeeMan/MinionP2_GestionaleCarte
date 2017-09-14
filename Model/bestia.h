#ifndef BESTIA_H
#define BESTIA_H

#include "creatura.h"

class Bestia: public Creatura{

public:

    Bestia();
    Bestia(const QString&, unsigned int, const QString&,
           const QString&, double, double, const QString& = "");

    double attaccoTotale() const override;
    double vitaTotale() const override;
    double typeMultiply() const override;
    QString getTipoCreatura() const override;
    QString getEffettoBase() const override;

};

#endif
