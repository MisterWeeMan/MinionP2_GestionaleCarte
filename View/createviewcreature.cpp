#include "createviewcreature.h"

// costruttore di default
CreateViewCreature::CreateViewCreature(): CreateViewCard(){
    createVariables();
    setFormLayout();

    connect(getSaveButton(), SIGNAL(clicked(bool)),
            this, SLOT(saveCreatureInfo()));
    connect(getCancelButton(), SIGNAL(clicked(bool)),
            this, SLOT(close()));
}

// crea le variabili utilizzate nella view
void CreateViewCreature::createVariables(){
    m_editAttack = new QSpinBox();
    m_editAttack->setMinimum(0);
    m_editAttack->setMaximum(50);
    m_editHealt = new QSpinBox();
    m_editHealt->setMinimum(0);
    m_editHealt->setMaximum(50);
    m_editType = new QComboBox();
    m_editType->insertItem(1, "Neutrale");
    m_editType->insertItem(2, "Bestia");
    m_editType->insertItem(3, "Demone");
    m_editType->insertItem(4, "Drago");
    m_editType->insertItem(5, "Murloc");
    m_editType->insertItem(6, "Pirata");
}

// aggiunge campi alla form
void CreateViewCreature::setFormLayout(){
    QFormLayout* formLayout = getFormLayout();
    QLabel* attacco = new QLabel("Attacco: ");
    QLabel* vita = new QLabel("Vita: ");
    QLabel* tipo = new QLabel("Tipo: ");
    formLayout->addRow(attacco, m_editAttack);
    formLayout->addRow(vita, m_editHealt);
    formLayout->addRow(tipo, m_editType);
}

// getter per i campi della form
QSpinBox* CreateViewCreature::getEditAttack() const{
    return m_editAttack;
}

QSpinBox* CreateViewCreature::getEditHealt() const{
    return m_editHealt;
}

QComboBox* CreateViewCreature::getEditType() const{
    return m_editType;
}

// slot attivato al premere del tasto salva, prende i dati dalla
// form e li invia con un segnale
void CreateViewCreature::saveCreatureInfo(){
    QString nome = getEditNome()->text();
    unsigned int costoMana = getEditManaCost()->value();
    QString rarita = getEditRarity()->currentText();
    QString espansione = getEditExpansion()->currentText();
    QString effetto = getEditEffect()->toPlainText();
    double attacco = m_editAttack->value();
    double vita = m_editHealt->value();
    QString tipo = m_editType->currentText();

    if(nome.isEmpty()){
        QMessageBox msgErrore;
        msgErrore.setText("Errore nell'input");
        msgErrore.setDetailedText("Non è stato inserito nessuno nome");
        msgErrore.setStyleSheet("QLabel{min-width: 250px;}");
        msgErrore.exec();
    }
    else{
        emit sendCreatureInfo(nome, costoMana, rarita, espansione, effetto,
                              attacco, vita, tipo);
    }
}












