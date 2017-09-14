#include "choosecard.h"

// costruttore di default
ChooseCard::ChooseCard(): ChooseDialog(){
    setVariables();

    connect(getFirstButton(), SIGNAL(clicked(bool)),
            this, SIGNAL(createCreature()));
    connect(getSecondButton(), SIGNAL(clicked(bool)),
            this, SIGNAL(createMagic()));
}

// setta le label dei widgets
void ChooseCard::setVariables(){
    getMessage()->setText("Creare una Creatura o una Magia?");
    getFirstButton()->setText("Creatura");
    getSecondButton()->setText("Magia");
}





