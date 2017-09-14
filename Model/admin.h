#ifndef ADMIN_H
#define ADMIN_H

#include "amministratore.h"

class Admin: public Amministratore{

public:

    Admin();
    Admin(const QString&, const QString&, const QString&,
          const QString&, const QString&);

    QString getTipo() const override;

};

#endif
