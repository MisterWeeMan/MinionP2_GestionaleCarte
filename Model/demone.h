#ifndef DEMONE_H
#define DEMONE_H

#include "creatura.h"

class Demone: public Creatura{

public:

    Demone();
    Demone(const QString&, unsigned int, const QString&,
           const QString&, double, double, const QString& = "");

    double attaccoTotale() const override;
    double vitaTotale() const override;
    double typeMultiply() const override;
    QString getTipoCreatura() const override;
    QString getEffettoBase() const override;

};

#endif
