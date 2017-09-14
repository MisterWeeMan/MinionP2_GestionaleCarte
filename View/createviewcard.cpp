#include "createviewcard.h"

// costruttore di default
CreateViewCard::CreateViewCard(): CreateView(){
    createVariables();
    setFormLayout();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(getFormGroupBox());
    mainLayout->addWidget(getButtonsGroupBox());
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
}

// crea le variabili utilizzate nella view
void CreateViewCard::createVariables(){
    m_layout = new QFormLayout();
    m_editNome = new QLineEdit();
    m_editNome->setMaxLength(40);
    m_editManaCost = new QSpinBox();
    m_editManaCost->setMinimum(0);
    m_editManaCost->setMaximum(50);
    m_editRarity = new QComboBox();
    m_editRarity->insertItem(1, "Comune");
    m_editRarity->insertItem(2, "Rara");
    m_editRarity->insertItem(3, "Epica");
    m_editRarity->insertItem(4, "Leggendaria");
    m_editExpansion = new QComboBox();
    m_editExpansion->insertItem(1, "Base");
    m_editExpansion->insertItem(2, "Classica");
    m_editExpansion->insertItem(3, "FIUP League");
    m_editEffect = new QTextEdit();
    m_editEffect->setFixedHeight(80);
}

// aggiunge campi alla form
void CreateViewCard::setFormLayout(){
    QLabel* nome = new QLabel("Nome carta: ");
    QLabel* manaCost = new QLabel("Costo mana: ");
    QLabel* rarity = new QLabel("Rarita': ");
    QLabel* expansion = new QLabel("Espansione: ");
    QLabel* effect = new QLabel("Effetto: ");
    m_layout->addRow(nome, m_editNome);
    m_layout->addRow(manaCost, m_editManaCost);
    m_layout->addRow(rarity, m_editRarity);
    m_layout->addRow(expansion, m_editExpansion);
    m_layout->addRow(effect, m_editEffect);
    QGroupBox* formBox = getFormGroupBox();
    formBox->setLayout(m_layout);
}

// getter per i campi della form e per il layout
QFormLayout* CreateViewCard::getFormLayout() const{
    return m_layout;
}

QLineEdit* CreateViewCard::getEditNome() const{
    return m_editNome;
}

QSpinBox* CreateViewCard::getEditManaCost() const{
    return m_editManaCost;
}

QComboBox* CreateViewCard::getEditRarity() const{
    return m_editRarity;
}

QComboBox* CreateViewCard::getEditExpansion() const{
    return m_editExpansion;
}

QTextEdit* CreateViewCard::getEditEffect() const{
    return m_editEffect;
}














