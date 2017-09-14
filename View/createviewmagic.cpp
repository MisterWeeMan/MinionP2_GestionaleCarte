#include "createviewmagic.h"

// costruttore di default
CreateViewMagic::CreateViewMagic(): CreateViewCard(){
    connect(getSaveButton(), SIGNAL(clicked(bool)),
            this, SLOT(saveMagicInfo()));
    connect(getCancelButton(), SIGNAL(clicked(bool)),
            this, SLOT(close()));
}

// slot attivato al premere del tasto salva, prende i dati dalla
// form e li invia con un segnale
void CreateViewMagic::saveMagicInfo(){
    QString nome = getEditNome()->text();
    unsigned int costoMana = getEditManaCost()->value();
    QString rarita = getEditRarity()->currentText();
    QString espansione = getEditExpansion()->currentText();
    QString effetto = getEditEffect()->toPlainText();

    if(nome.isEmpty()){
        QMessageBox msgErrore;
        msgErrore.setText("Errore nell'input");
        msgErrore.setDetailedText("Non è stato inserito nessuno nome");
        msgErrore.setStyleSheet("QLabel{min-width: 250px;}");
        msgErrore.exec();
    }
    else{
        emit sendMagicInfo(nome, costoMana, rarita, espansione, effetto);
    }
}




















