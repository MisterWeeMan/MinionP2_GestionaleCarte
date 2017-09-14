#ifndef DRAGO_H
#define DRAGO_H

#include "creatura.h"

class Drago: public Creatura{

public:

    Drago();
    Drago(const QString&, unsigned int, const QString&,
          const QString&, double, double, const QString& = "");

    double attaccoTotale() const override;
    double vitaTotale() const override;
    double typeMultiply() const override;
    QString getTipoCreatura() const override;
    QString getEffettoBase() const override;

};

#endif
