#ifndef CREATEVIEWCARD_H
#define CREATEVIEWCARD_H

#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>
#include <QString>

#include "createview.h"

class CreateViewCard: public CreateView{

    Q_OBJECT

private:

    QLineEdit* m_editNome;
    QSpinBox* m_editManaCost;
    QComboBox* m_editRarity;
    QComboBox* m_editExpansion;
    QTextEdit* m_editEffect;
    QFormLayout* m_layout;

    void createVariables() override;
    void setFormLayout() override;

public:

    CreateViewCard();

    QFormLayout* getFormLayout() const;
    QLineEdit* getEditNome() const;
    QSpinBox* getEditManaCost() const;
    QComboBox* getEditRarity() const;
    QComboBox* getEditExpansion() const;
    QTextEdit* getEditEffect() const;

};

#endif
