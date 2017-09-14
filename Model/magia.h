#ifndef MAGIA_H
#define MAGIA_H

#include "carta.h"

class Magia: public Carta{

public:

    Magia();
    Magia(const QString&, unsigned int, const QString&,
          const QString&, const QString& = "");

    double costoPolvereBase() const override;
    double costoPolvere() const override;
    QString getTipoCarta() const override;

};

#endif
