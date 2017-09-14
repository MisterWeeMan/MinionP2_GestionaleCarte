#ifndef CHOOSECARD_H
#define CHOOSECARD_H

#include "choosedialog.h"

class ChooseCard: public ChooseDialog{

    Q_OBJECT

private:

    void setVariables() override;

public:

    ChooseCard();

signals:

    void createCreature();
    void createMagic();

};

#endif
