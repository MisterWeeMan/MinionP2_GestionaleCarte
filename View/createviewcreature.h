#ifndef CREATEVIEWCREATURE_H
#define CREATEVIEWCREATURE_H

#include "createviewcard.h"

class CreateViewCreature: public CreateViewCard{

    Q_OBJECT

private:

    QSpinBox* m_editAttack;
    QSpinBox* m_editHealt;
    QComboBox* m_editType;

    void createVariables() override;
    void setFormLayout() override;

public:

    CreateViewCreature();

    QSpinBox* getEditAttack() const;
    QSpinBox* getEditHealt() const;
    QComboBox* getEditType() const;

signals:

    void sendCreatureInfo(const QString&, unsigned int, const QString&, const QString&,
                          const QString&, double, double, const QString&);

public slots:

    void saveCreatureInfo();

};

#endif
