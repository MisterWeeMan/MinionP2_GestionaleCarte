#ifndef CREATURA_H
#define CREATURA_H

#include "carta.h"

class Creatura: public Carta{

private:

    double m_attacco;
    double m_vita;

public:

    Creatura();
    Creatura(const QString&, unsigned int, const QString&,
             const QString&, double, double, const QString& = "");

    bool operator==(const Creatura&);

    double getAttacco() const;
    void setAttacco(double);

    double getVita() const;
    void setVita(double);

    double costoPolvereBase() const override;
    double costoPolvere() const override;
    QString getTipoCarta() const override;

    virtual double attaccoTotale() const = 0;
    virtual double vitaTotale() const = 0;
    virtual double typeMultiply() const = 0;
    virtual QString getTipoCreatura() const = 0;
    virtual QString getEffettoBase() const = 0;

};

#endif
