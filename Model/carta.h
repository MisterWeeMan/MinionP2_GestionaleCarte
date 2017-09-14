#ifndef CARTA_H
#define CARTA_H

#include <QString>
#include <QVector>

class Carta{

private:

    QString m_nome;
    unsigned int m_costoMana;
    QString m_rarita;
    QString m_espansione;
    QString m_effetto;

    static bool controlloRarita(const QString&);
    static bool controlloEspansione(const QString&);

public:

    static const QVector<QString> listRarity;
    static const QVector<QString> listExpansion;

    Carta();
    Carta(const QString &, unsigned int, const QString &,
          const QString &, const QString & = "");
    virtual ~Carta() = default;

    bool operator==(const Carta&);

    QString getNome() const;
    void setNome(const QString &value);

    unsigned int getCostoMana() const;
    void setCostoMana(unsigned int value);

    QString getRarita() const;
    void setRarita(const QString &value);

    QString getEspansione() const;
    void setEspansione(const QString &value);

    QString getEffetto() const;
    void setEffetto(const QString &value);

    double rarityMultiply() const;

    virtual double costoPolvere() const = 0;
    virtual double costoPolvereBase() const = 0;
    virtual QString getTipoCarta() const = 0;

};

#endif
