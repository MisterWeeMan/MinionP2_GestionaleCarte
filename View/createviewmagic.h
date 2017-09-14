#ifndef CREATEVIEWMAGIC_H
#define CREATEVIEWMAGIC_H

#include "createviewcard.h"

class CreateViewMagic: public CreateViewCard{

    Q_OBJECT

public:

    CreateViewMagic();

signals:

    void sendMagicInfo(const QString&, unsigned int,
                       const QString&, const QString&,
                       const QString&);

public slots:

    void saveMagicInfo();

};

#endif
