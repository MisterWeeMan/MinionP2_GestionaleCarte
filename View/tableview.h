#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
#include <QDebug>
#include <QHeaderView>

class TableView: public QWidget{

    Q_OBJECT

private:

    QTableWidget* m_tableWidget;

    QVBoxLayout* m_mainLayout;

    QLabel* m_tipoTabella;

    QPushButton* m_logoutButton;

    void createVariables();
    void setDefaultTableProperty();   

public:

    TableView();
    virtual ~TableView() = default;

    void setLabel(const QString&);

    QTableWidget* getTable() const;
    QVBoxLayout* getMainLayout() const;
    QLabel* getTipoTabella() const;

signals:

    void logoutClicked();

};

#endif
