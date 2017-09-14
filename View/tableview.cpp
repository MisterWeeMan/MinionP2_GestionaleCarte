#include "tableview.h"

// costruttore di default
TableView::TableView(){
    setFixedSize(650, 500);
    createVariables();
    setDefaultTableProperty();
    setLabel("Benvenuto UtenteFree");
    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addWidget(m_tipoTabella);
    m_mainLayout->addWidget(m_logoutButton);
    m_mainLayout->addWidget(m_tableWidget);
    setLayout(m_mainLayout);

    connect(m_logoutButton, SIGNAL(clicked(bool)),
            this, SIGNAL(logoutClicked()));
}

// crea le variabili per la view
void TableView::createVariables(){
    m_tableWidget = new QTableWidget();
    m_tipoTabella = new QLabel();
    m_logoutButton = new QPushButton("Logout");
    m_logoutButton->setFixedWidth(150);
}

// setta le proprietà generali della tabella
void TableView::setDefaultTableProperty(){
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableWidget->setFocusPolicy(Qt::NoFocus);
    m_tableWidget->verticalHeader()->hide();
    m_tableWidget->horizontalHeader()->setStyleSheet("color: blue");
}

// setta la label sopra la tabella
void TableView::setLabel(const QString& t_text){
    m_tipoTabella->setText(t_text);
    m_tipoTabella->setFont(QFont("Arial", 15, QFont::Bold));
    m_tipoTabella->setFrameStyle(QFrame::Box);
    m_tipoTabella->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    m_tipoTabella->setFixedSize(630, 50);
}

// getter per tabella, label e layout
QTableWidget* TableView::getTable() const{
    return m_tableWidget;
}


QVBoxLayout* TableView::getMainLayout() const{
    return m_mainLayout;
}

QLabel* TableView::getTipoTabella() const{
    return m_tipoTabella;
}
