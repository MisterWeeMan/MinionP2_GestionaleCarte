#ifndef CHOOSEUSER_H
#define CHOOSEUSER_H

#include "choosedialog.h"

class ChooseUser: public ChooseDialog{

    Q_OBJECT

private:

    void setVariables() override;

public:

    ChooseUser();

signals:

    void createBaseUser();
    void createAdmin();

};

#endif
