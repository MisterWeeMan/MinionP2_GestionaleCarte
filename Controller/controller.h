#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QFile>

#include "View/logindialog.h"
#include "Model/list.h"
#include "Model/utente.h"
#include "Model/carta.h"
#include "userreader.h"
#include "userwriter.h"
#include "cardreader.h"
#include "cardwriter.h"
#include "View/createviewcreature.h"
#include "View/createviewmagic.h"
#include "View/createviewbaseuser.h"
#include "View/createviewadminuser.h"
#include "View/choosecard.h"
#include "View/chooseuser.h"
#include "View/tableview.h"
#include "View/tableviewpro.h"
#include "View/tableviewmod.h"
#include "View/tableviewadmin.h"

class Controller: public QObject{

    Q_OBJECT

private:

    Lista<Carta*>* m_listaCarte;
    Lista<Utente*>* m_listaUtenti;
    Utente* m_loggedUser;

    LoginDialog* m_loginView;
    TableView* m_tableDialog;
    CreateViewBaseUser* m_createBaseUserDialog;
    CreateViewAdminUser* m_createAdminDialog;
    CreateViewMagic* m_createMagicDialog;
    CreateViewCreature* m_createCreatureDialog;
    ChooseCard* m_scegliCarta;
    ChooseUser* m_scegliUtente;

    void setVariables();

    void loadData();
    void writeData();

    void setCardTable();
    void setUserTable();

    void insertCardRow(int);
    void insertUserRow(int);

public:

    Controller();
    ~Controller();

    void startApplication() const;

    TableView* getTableDialog() const;

public slots:

    void login(const QString&, const QString&);
    void logout();

    void userTableView();
    void cardTableView();

    void createCardView();
    void createUserView();

    void createCreatureView();
    void createMagicView();

    void createBaseUserView();
    void createAdminView();

    void createNewCreature(const QString&, uint, const QString&, const QString&, const QString&,
                           double, double, const QString&);
    void createNewMagic(const QString&, uint, const QString&, const QString&, const QString&);

    void createNewBaseUser(const QString&, const QString&,
                           const QString&, const QString&);
    void createNewAdmin(const QString&, const QString&, const QString&,
                       const QString&, const QString&, const QString&);

    void modifyUserView();
    void modifyCardView();

    void modifyOldBaseUser(const QString&, const QString&,
                           const QString&, const QString&);
    void modifyOldAdmin(const QString&, const QString&, const QString&,
                        const QString&, const QString&, const QString&);

    void modifyOldMagic(const QString&, unsigned int,
                        const QString&, const QString&, const QString&);
    void modifyOldCreature(const QString&, unsigned int, const QString&,
                           const QString&, const QString&, double,
                           double, const QString&);

    void destroyUser();
    void destroyCard();

};

#endif
