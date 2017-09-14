#ifndef PIRATA_H
#define PIRATA_H

#include "creatura.h"

class Pirata: public Creatura{

public:

    Pirata();
    Pirata(const QString&, unsigned int, const QString&,
           const QString&, double, double, const QString& = "Nessuno");

    double attaccoTotale() const override;
    double vitaTotale() const override;
    double typeMultiply() const override;
    QString getTipoCreatura() const override;
    QString getEffettoBase() const override;

};

#endif
