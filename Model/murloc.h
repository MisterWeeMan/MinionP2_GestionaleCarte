#ifndef MURLOC_H
#define MURLOC_H

#include "creatura.h"

class Murloc: public Creatura{

public:

    Murloc();
    Murloc(const QString&, unsigned int, const QString&,
           const QString&, double, double, const QString& = "");

    double attaccoTotale() const override;
    double vitaTotale() const override;
    double typeMultiply() const override;
    QString getTipoCreatura() const override;
    QString getEffettoBase() const override;

};

#endif
