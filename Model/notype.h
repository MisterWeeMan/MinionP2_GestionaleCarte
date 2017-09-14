#ifndef NOTYPE_H
#define NOTYPE_H

#include "creatura.h"

class Neutrale: public Creatura{

public:

    Neutrale();
    Neutrale(const QString&, unsigned int, const QString&,
           const QString&, double, double, const QString& = "");

    double attaccoTotale() const override;
    double vitaTotale() const override;
    double typeMultiply() const override;
    QString getTipoCreatura() const override;
    QString getEffettoBase() const override;

};

#endif
