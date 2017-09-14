#include "chooseuser.h"

// costruttore di default
ChooseUser::ChooseUser(): ChooseDialog(){
    setVariables();

    connect(getFirstButton(), SIGNAL(clicked(bool)),
            this, SIGNAL(createBaseUser()));
    connect(getSecondButton(), SIGNAL(clicked(bool)),
            this, SIGNAL(createAdmin()));
}

// setta le label dei widgets
void ChooseUser::setVariables(){
    getMessage()->setText("Creare una Utente base o un Amministratore?");
    getFirstButton()->setText("Utente base");
    getSecondButton()->setText("Amministratore");
}

