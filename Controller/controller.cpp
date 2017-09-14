#include "controller.h"

// costruttore di default di controller
Controller::Controller(){
    setVariables();
    loadData();
}

// salvataggio dei dati alla chiusura dell'applicazione
Controller::~Controller(){
    writeData();
    delete m_listaCarte;
    delete m_listaUtenti;

    if(m_tableDialog){
        delete m_tableDialog;
    }

    if(m_loginView){
        delete m_loginView;
    }
}

// avvio dell'applicazione
void Controller::startApplication() const{
    m_loginView->show();
}

// gettere per la tabella
TableView* Controller::getTableDialog() const{
    return m_tableDialog;
}

// setta i membri privati della classe
void Controller::setVariables(){
    m_listaCarte = new Lista<Carta*>();
    m_listaUtenti = new Lista<Utente*>();
    m_loggedUser = nullptr;
    m_loginView = new LoginDialog();

    connect(m_loginView, SIGNAL(acceptLogin(QString,QString)), this, SLOT(login(QString,QString)));

    m_tableDialog = nullptr;
    m_createBaseUserDialog = nullptr;
    m_createAdminDialog = nullptr;
    m_createMagicDialog = nullptr;
    m_createCreatureDialog = nullptr;
    m_scegliCarta = nullptr;
    m_scegliUtente = nullptr;
}

// carica i dati dai due file
void Controller::loadData(){
    QIODevice* fileCarte(new QFile("Xml/database.xml"));

    if(fileCarte->open(QIODevice::ReadOnly)){
        CardReader readXML(fileCarte, m_listaCarte);
        readXML.readFile();
        fileCarte->close();
    }

    QIODevice* fileUtenti(new QFile("Xml/databaseUser.xml"));

    if(fileUtenti->open(QIODevice::ReadOnly)){
        UserReader readXML2(fileUtenti, m_listaUtenti);
        readXML2.readFile();
        fileUtenti->close();
    }
    else{
        m_listaUtenti->push_back(new Admin("admin", "admin", "admin@admin.it", "admin", "admin"));
    }

}

// salva i dati nei due file
void Controller::writeData(){
    QIODevice* fileCarte(new QFile("Xml/database.xml"));

    if(fileCarte->open(QIODevice::WriteOnly)){
        CardWriter writeXML(fileCarte, m_listaCarte);
        writeXML.writeFile();
        fileCarte->close();
    }

    QIODevice* fileUtenti(new QFile("Xml/databaseUser.xml"));

    if(fileUtenti->open(QIODevice::WriteOnly)){
        UserWriter writeXML2(fileUtenti, m_listaUtenti);
        writeXML2.writeFile();
        fileUtenti->close();
    }

}

// setta la tabella con gli elementi del contenitore carte
void Controller::setCardTable(){
    QTableWidget* tabella = m_tableDialog->getTable();
    tabella->clear();
    tabella->setRowCount(m_listaCarte->getN_elem());
    tabella->setColumnCount(10);
    tabella->setHorizontalHeaderLabels(QStringList() << "Nome"
                                       << "Costo Mana" << "Rarita'"
                                       << "Espansione" << "Effetto"
                                       << "Tipo Carta" << "Tipo Creatura"
                                       << "Attacco" << "Vita" << "Costo Polvere");

    for(int i = 0; i < m_listaCarte->getN_elem(); i++){
        insertCardRow(i);
    }
}

// setta la tabella con gli elementi del contenitore utenti
void Controller::setUserTable(){
    QTableWidget* tabella = m_tableDialog->getTable();
    tabella->clear();
    tabella->setRowCount(m_listaUtenti->getN_elem());
    tabella->setColumnCount(6);
    tabella->setHorizontalHeaderLabels(QStringList() << "Username" << "Password"
                                       << "Email" << "Nome" << "Cognome"
                                       << "Tipo Utente");

    for(int i = 0; i < m_listaUtenti->getN_elem(); i++){
        insertUserRow(i);
    }
}

// inserisce una carta nella tabella
void Controller::insertCardRow(int t_riga){
    Lista<Carta*>::Iteratore it = m_listaCarte->begin();

    for(int x = 0; x < t_riga; x++){
        it++;
    }

    Carta* carta = *it;
    QTableWidget* tabella = m_tableDialog->getTable();
    tabella->setItem(t_riga, 0, new QTableWidgetItem(carta->getNome()));
    tabella->setItem(t_riga, 1, new QTableWidgetItem(QString().setNum(carta->getCostoMana())));
    tabella->setItem(t_riga, 2, new QTableWidgetItem(carta->getRarita()));
    tabella->setItem(t_riga, 3, new QTableWidgetItem(carta->getEspansione()));
    tabella->setItem(t_riga, 4, new QTableWidgetItem(carta->getEffetto()));
    tabella->setItem(t_riga, 5, new QTableWidgetItem(carta->getTipoCarta()));
    Creatura* monster = dynamic_cast<Creatura*>(carta);

    if(monster){
        tabella->setItem(t_riga, 6, new QTableWidgetItem(monster->getTipoCreatura()));
        tabella->setItem(t_riga, 7, new QTableWidgetItem(QString().setNum(monster->attaccoTotale())));
        tabella->setItem(t_riga, 8, new QTableWidgetItem(QString().setNum(monster->vitaTotale())));
    }

    tabella->setItem(t_riga, 9, new QTableWidgetItem(QString().setNum(carta->costoPolvere())));
}

// inserisce un utente nella tabella
void Controller::insertUserRow(int t_riga){
    Lista<Utente*>::Iteratore it = m_listaUtenti->begin();

    for(int x = 0; x < t_riga; x++){
        it++;
    }

    Utente* utente = *it;
    QTableWidget* tabella = m_tableDialog->getTable();
    tabella->setItem(t_riga, 0, new QTableWidgetItem(utente->getUsername()));
    tabella->setItem(t_riga, 1, new QTableWidgetItem(utente->getPassword()));
    tabella->setItem(t_riga, 2, new QTableWidgetItem(utente->getEmail()));
    Amministratore* admin = dynamic_cast<Amministratore*>(utente);

    if(admin){
        tabella->setItem(t_riga, 3, new QTableWidgetItem(admin->getNome()));
        tabella->setItem(t_riga, 4, new QTableWidgetItem(admin->getCognome()));
    }

    tabella->setItem(t_riga, 5, new QTableWidgetItem(utente->getTipo()));
}

// apre la view corretta in base al tipo utente
void Controller::login(const QString& t_username, const QString& t_password){
    bool check = false;

    for(auto it = m_listaUtenti->begin(); it != m_listaUtenti->end(); ++it){
        if((*it)->getUsername() == t_username && (*it)->getPassword() == t_password){
            m_loggedUser = *it;
            check = true;
        }
    }

    if(!check){
        QMessageBox message;
        message.setText("Username o password errati");
        message.exec();
    }
    else{

        if(dynamic_cast<UtenteFree*>(m_loggedUser)){
            m_tableDialog = new TableView();
        }
        else if(dynamic_cast<UtentePro*>(m_loggedUser)){
            m_tableDialog = new TableViewPro();

            connect(m_tableDialog, SIGNAL(modifyCardPushed()), this, SLOT(modifyCardView()));
        }
        else if(dynamic_cast<Moderatore*>(m_loggedUser)){
            m_tableDialog = new TableViewMod();

            connect(m_tableDialog, SIGNAL(modifyCardPushed()), this, SLOT(modifyCardView()));
            connect(m_tableDialog, SIGNAL(createCardPushed()), this, SLOT(createCardView()));
            connect(m_tableDialog, SIGNAL(deleteCardPushed()), this, SLOT(destroyCard()));
        }
        else if(dynamic_cast<Admin*>(m_loggedUser)){
            m_tableDialog = new TableViewAdmin();

            connect(m_tableDialog, SIGNAL(setCardTable()), this, SLOT(cardTableView()));
            connect(m_tableDialog, SIGNAL(setUserTable()), this, SLOT(userTableView()));
            connect(m_tableDialog, SIGNAL(createCardPushed()), this, SLOT(createCardView()));
            connect(m_tableDialog, SIGNAL(modifyCardPushed()), this, SLOT(modifyCardView()));
            connect(m_tableDialog, SIGNAL(deleteCardPushed()), this, SLOT(destroyCard()));
            connect(m_tableDialog, SIGNAL(createUserPushed()), this, SLOT(createUserView()));
            connect(m_tableDialog, SIGNAL(modifyUserPushed()), this, SLOT(modifyUserView()));
            connect(m_tableDialog, SIGNAL(deleteUserPushed()), this, SLOT(destroyUser()));
        }

        connect(m_tableDialog, SIGNAL(logoutClicked()), this, SLOT(logout()));

        setCardTable();
        m_loginView->close();
        delete m_loginView;
        m_loginView = nullptr;
        m_tableDialog->show();
    }
}

void Controller::logout(){
    m_tableDialog->close();
    delete m_tableDialog;
    m_tableDialog = nullptr;
    m_loginView = new LoginDialog();

    connect(m_loginView, SIGNAL(acceptLogin(QString,QString)),
            this, SLOT(login(QString,QString)));

    m_loginView->show();
}

// setta la tabella con gli utenti
void Controller::userTableView(){
    setUserTable();
}

// setta la tabella con le carte
void Controller::cardTableView(){
    setCardTable();
}

// scelta del tipo di carta che si vuol creare
void Controller::createCardView(){
    m_scegliCarta = new ChooseCard();

    connect(m_scegliCarta, SIGNAL(createCreature()), this, SLOT(createCreatureView()));
    connect(m_scegliCarta, SIGNAL(createMagic()), this, SLOT(createMagicView()));

    m_scegliCarta->exec();
}

// scelta del tipo di utente che si vuol creare
void Controller::createUserView(){
    m_scegliUtente = new ChooseUser();

    connect(m_scegliUtente, SIGNAL(createBaseUser()), this, SLOT(createBaseUserView()));
    connect(m_scegliUtente, SIGNAL(createAdmin()), this, SLOT(createAdminView()));

    m_scegliUtente->exec();
}

// creo finestra di creazione per carta creatura
void Controller::createCreatureView(){
    m_createCreatureDialog = new CreateViewCreature();

    connect(m_createCreatureDialog, SIGNAL(sendCreatureInfo(const QString&, uint, const QString&, const QString&, const QString&,
                                                      double, double, const QString&)),
            this, SLOT(createNewCreature(const QString&, uint, const QString&, const QString&, const QString&,
                                      double, double, const QString&)));

    m_scegliCarta->close();
    delete m_scegliCarta;
    m_scegliCarta = nullptr;
    m_createCreatureDialog->exec();
}

// creo finestra di creazione per carta magia
void Controller::createMagicView(){
    m_createMagicDialog = new CreateViewMagic();

    connect(m_createMagicDialog, SIGNAL(sendMagicInfo(const QString&, uint, const QString&, const QString&, const QString&)),
            this, SLOT(createNewMagic(const QString&, uint, const QString&, const QString&, const QString&)));

    m_scegliCarta->close();
    delete m_scegliCarta;
    m_scegliCarta = nullptr;
    m_createMagicDialog->exec();
}

// creo finestra di creazione per utente base
void Controller::createBaseUserView(){
    m_createBaseUserDialog = new CreateViewBaseUser();

    connect(m_createBaseUserDialog, SIGNAL(sendBaseUserInfo(const QString&, const QString&,
                                                          const QString&, const QString&)),
            this, SLOT(createNewBaseUser(const QString&, const QString&,
                                         const QString&, const QString&)));

    m_scegliUtente->close();
    delete m_scegliUtente;
    m_scegliUtente = nullptr;
    m_createBaseUserDialog->exec();
}

// creo finestra di creazione per admin
void Controller::createAdminView(){
    m_createAdminDialog = new CreateViewAdminUser();

    connect(m_createAdminDialog, SIGNAL(sendAdminInfo(const QString&, const QString&, const QString&,
                                                    const QString&, const QString&, const QString&)),
            this, SLOT(createNewAdmin(const QString&, const QString&, const QString&,
                                      const QString&, const QString&, const QString&)));

    m_scegliUtente->close();
    delete m_scegliUtente;
    m_scegliUtente = nullptr;
    m_createAdminDialog->exec();
}

// creazione nuova magia
void Controller::createNewMagic(const QString& t_nome, uint t_costoMana, const QString& t_rarita,
                                const QString& t_espansione, const QString& t_effetto){
    Carta* newMagic = new Magia(t_nome, t_costoMana, t_rarita, t_espansione, t_effetto);
    m_listaCarte->push_back(newMagic);
    setCardTable();
    m_createMagicDialog->close();
    delete m_createMagicDialog;
    m_createMagicDialog = nullptr;
}

// creazione nuova creatura
void Controller::createNewCreature(const QString& t_nome, uint t_costoMana, const QString& t_rarita,
                                   const QString& t_espansione, const QString& t_effetto, double t_attacco,
                                   double t_vita, const QString& t_tipo){
    Creatura* newCreature = nullptr;

    if(t_tipo == "Bestia"){
        newCreature = new Bestia(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
    }
    else if(t_tipo == "Demone"){
        newCreature = new Demone(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
    }
    else if(t_tipo == "Neutrale"){
        newCreature = new Neutrale(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
    }
    else if(t_tipo == "Drago"){
        newCreature = new Drago(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
    }
    else if(t_tipo == "Murloc"){
        newCreature = new Murloc(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
    }
    else if(t_tipo == "Pirata"){
        newCreature = new Pirata(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
    }

    m_listaCarte->push_back(newCreature);
    setCardTable();
    m_createCreatureDialog->close();
    delete m_createCreatureDialog;
    m_createCreatureDialog = nullptr;
}

// creazione nuovo utente base
void Controller::createNewBaseUser(const QString& t_username, const QString& t_password,
                                   const QString& t_email, const QString& t_tipo){
    Utente* newUser = nullptr;
    bool check = false;

    for(auto it = m_listaUtenti->begin(); it != m_listaUtenti->end(); ++it){
        if((*it)->getUsername() == t_username){
            check = true;
        }
    }

    if(check){
        QMessageBox message;
        message.setText("Username già utilizzato");
        message.exec();
    }
    else{

        if(t_tipo == "UtenteFree"){
            newUser = new UtenteFree(t_username, t_password, t_email);
        }
        else if(t_tipo == "UtentePro"){
            newUser = new UtentePro(t_username, t_password, t_email);
        }

        m_listaUtenti->push_back(newUser);
        setUserTable();
        m_createBaseUserDialog->close();
        delete m_createBaseUserDialog;
        m_createBaseUserDialog = nullptr;
    }
}

// creazione nuovo admin
void Controller::createNewAdmin(const QString& t_nome, const QString& t_cognome, const QString& t_username,
                               const QString& t_password, const QString& t_email, const QString& t_tipo){
    Amministratore* newUser = nullptr;
    bool check = false;

    for(auto it = m_listaUtenti->begin(); it != m_listaUtenti->end(); ++it){
        if((*it)->getUsername() == t_username){
            check = true;
        }
    }

    if(check){
        QMessageBox message;
        message.setText("Username già utilizzato");
        message.exec();
    }
    else{

        if(t_tipo == "Admin"){
            newUser = new Admin(t_username, t_password, t_email, t_nome, t_cognome);
        }
        else if(t_tipo == "Moderatore"){
            newUser = new Moderatore(t_username, t_password, t_email, t_nome, t_cognome);
        }

        m_listaUtenti->push_back(newUser);
        setUserTable();
        m_createAdminDialog->close();
        delete m_createAdminDialog;
        m_createAdminDialog = nullptr;
    }
}

// creazione della finestra di modifica per un utente
void Controller::modifyUserView(){
    Lista<Utente*>::Iteratore it = m_listaUtenti->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    Utente* daModificare = *it;
    Amministratore* adminDaModificare = dynamic_cast<Amministratore*>(daModificare);

    if(adminDaModificare){
        m_createAdminDialog = new CreateViewAdminUser();
        m_createAdminDialog->getEditNome()->setText(adminDaModificare->getNome());
        m_createAdminDialog->getEditCognome()->setText(adminDaModificare->getCognome());
        m_createAdminDialog->getEditUsername()->setText(adminDaModificare->getUsername());
        m_createAdminDialog->getEditPassword()->setText(adminDaModificare->getPassword());
        m_createAdminDialog->getEditEmail()->setText(adminDaModificare->getEmail());
        m_createAdminDialog->getEditType()->setCurrentIndex(
                    m_createAdminDialog->getEditType()->findText(adminDaModificare->getTipo()));

        connect(m_createAdminDialog, SIGNAL(sendAdminInfo(const QString&, const QString&,
                                                       const QString&, const QString&,
                                                       const QString&, const QString&)),
                this, SLOT(modifyOldAdmin(const QString&, const QString&,
                                          const QString&, const QString&,
                                          const QString&, const QString&)));

        m_createAdminDialog->exec();
    }
    else{
        m_createBaseUserDialog = new CreateViewBaseUser();
        m_createBaseUserDialog->getEditUsername()->setText(daModificare->getUsername());
        m_createBaseUserDialog->getEditPassword()->setText(daModificare->getPassword());
        m_createBaseUserDialog->getEditEmail()->setText(daModificare->getEmail());
        m_createBaseUserDialog->getEditType()->setCurrentIndex(
                    m_createBaseUserDialog->getEditType()->findText(daModificare->getTipo()));

        connect(m_createBaseUserDialog, SIGNAL(sendBaseUserInfo(const QString&, const QString&,
                                                              const QString&, const QString&)),
                this, SLOT(modifyOldBaseUser(const QString&, const QString&,
                                             const QString&, const QString&)));

        m_createBaseUserDialog->exec();
    }
}

// crezione della finestra di modifica per una carta
void Controller::modifyCardView(){
    Lista<Carta*>::Iteratore it = m_listaCarte->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    Carta* daModificare = *it;
    Creatura* creatDaModificare = dynamic_cast<Creatura*>(daModificare);

    if(creatDaModificare){

        m_createCreatureDialog = new CreateViewCreature();
        m_createCreatureDialog->getEditNome()->setText(creatDaModificare->getNome());
        m_createCreatureDialog->getEditManaCost()->setValue(creatDaModificare->getCostoMana());
        m_createCreatureDialog->getEditRarity()->setCurrentIndex(
                    m_createCreatureDialog->getEditRarity()->findText(creatDaModificare->getRarita()));
        m_createCreatureDialog->getEditExpansion()->setCurrentIndex(
                    m_createCreatureDialog->getEditExpansion()->findText(creatDaModificare->getEspansione()));
        m_createCreatureDialog->getEditEffect()->setText(creatDaModificare->getEffetto());
        m_createCreatureDialog->getEditAttack()->setValue(creatDaModificare->getAttacco());
        m_createCreatureDialog->getEditHealt()->setValue(creatDaModificare->getVita());
        m_createCreatureDialog->getEditType()->setCurrentIndex(
                    m_createCreatureDialog->getEditType()->findText(creatDaModificare->getTipoCreatura()));

        connect(m_createCreatureDialog, SIGNAL(sendCreatureInfo(const QString&, unsigned int, const QString&, const QString&,
                                                              const QString&, double, double, const QString&)),
                this, SLOT(modifyOldCreature(const QString&, unsigned int, const QString&, const QString&,
                                             const QString&, double, double, const QString&)));
        m_createCreatureDialog->exec();
    }
    else{
        m_createMagicDialog = new CreateViewMagic();
        m_createMagicDialog->getEditNome()->setText(daModificare->getNome());
        m_createMagicDialog->getEditManaCost()->setValue(daModificare->getCostoMana());
        m_createMagicDialog->getEditRarity()->setCurrentIndex(
                    m_createMagicDialog->getEditRarity()->findText(daModificare->getRarita()));
        m_createMagicDialog->getEditExpansion()->setCurrentIndex(
                    m_createMagicDialog->getEditExpansion()->findText(daModificare->getEspansione()));
        m_createMagicDialog->getEditEffect()->setText(daModificare->getEffetto());

        connect(m_createMagicDialog, SIGNAL(sendMagicInfo(const QString&, unsigned int,
                                                        const QString&, const QString&, const QString&)),
                this, SLOT(modifyOldMagic(const QString&, unsigned int,
                                          const QString&, const QString&, const QString&)));

        m_createMagicDialog->exec();
    }
}

// modifica di un utente base
void Controller::modifyOldBaseUser(const QString& t_username, const QString& t_password,
                                   const QString& t_email, const QString& t_tipo){
    Lista<Utente*>::Iteratore it = m_listaUtenti->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    Utente* daModificare = *it;
    bool check = false;

    for(auto it = m_listaUtenti->begin(); it != m_listaUtenti->end(); ++it){
        if((*it)->getUsername() == t_username && t_username != daModificare->getUsername()){
            check = true;
        }
    }

    if(check){
        QMessageBox message;
        message.setText("Username già utilizzato");
        message.exec();
    }
    else{
        if(t_tipo != daModificare->getTipo()){
            delete *it;

            if(t_tipo == "UtenteFree"){
                (*it) = new UtenteFree(t_username, t_password, t_email);
            }
            else if(t_tipo == "UtentePro"){
                (*it) = new UtentePro(t_username, t_password, t_email);
            }
        }
        else{
            if(t_username != daModificare->getUsername()){
                daModificare->setUsername(t_username);
            }
            if(t_password != daModificare->getPassword()){
                daModificare->setPassword(t_password);
            }
            if(t_email != daModificare->getEmail()){
                daModificare->setEmail(t_email);
            }
        }

        setUserTable();
        m_createBaseUserDialog->close();
        delete m_createBaseUserDialog;
        m_createBaseUserDialog = nullptr;
    }
}

// modifica di un utente amministratore
void Controller::modifyOldAdmin(const QString& t_nome, const QString& t_cognome, const QString& t_username,
                                const QString& t_password, const QString& t_email, const QString& t_tipo){
    Lista<Utente*>::Iteratore it = m_listaUtenti->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    Amministratore* daModificare = dynamic_cast<Amministratore*>(*it);
    bool check = false;

    for(auto it = m_listaUtenti->begin(); it != m_listaUtenti->end(); ++it){
        if((*it)->getUsername() == t_username && t_username != daModificare->getUsername()){
            check = true;
        }
    }

    if(check){
        QMessageBox message;
        message.setText("Username già utilizzato");
        message.exec();
    }
    else{
        if(t_tipo != daModificare->getTipo()){
            if(m_loggedUser == *it){
                QMessageBox message;
                message.setText("Non puoi modificare il tipo utente di te stesso!");
                message.exec();
            }
            else{
                delete *it;

                if(t_tipo == "Admin"){
                    (*it) = new Admin(t_username, t_password, t_email, t_nome, t_cognome);
                }
                else if(t_tipo == "Moderatore"){
                    (*it) = new Moderatore(t_username, t_password, t_email, t_nome, t_cognome);
                }
            }
        }
        else{
            if(t_nome != daModificare->getNome()){
                daModificare->setNome(t_nome);
            }
            if(t_cognome != daModificare->getCognome()){
                daModificare->setCognome(t_cognome);
            }
            if(t_username != daModificare->getUsername()){
                daModificare->setUsername(t_username);
            }
            if(t_password != daModificare->getPassword()){
                daModificare->setPassword(t_password);
            }
            if(t_email != daModificare->getEmail()){
                daModificare->setEmail(t_email);
            }
        }

        setUserTable();
        m_createAdminDialog->close();
        delete m_createAdminDialog;
        m_createAdminDialog = nullptr;
    }
}

// modifica di una carta magia
void Controller::modifyOldMagic(const QString& t_nome, unsigned int t_costoMana, const QString& t_rarita,
                                const QString& t_espansione, const QString& t_effetto){
    Lista<Carta*>::Iteratore it = m_listaCarte->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    Carta* daModificare = *it;

    if(t_nome != daModificare->getNome()){
        daModificare->setNome(t_nome);
    }
    if(t_costoMana != daModificare->getCostoMana()){
        daModificare->setCostoMana(t_costoMana);
    }
    if(t_rarita != daModificare->getRarita()){
        daModificare->setRarita(t_rarita);
    }
    if(t_espansione != daModificare->getEspansione()){
        daModificare->setEspansione(t_espansione);
    }
    if(t_effetto != daModificare->getEffetto()){
        daModificare->setEffetto(t_effetto);
    }

    setCardTable();
    m_createMagicDialog->close();
    delete m_createMagicDialog;
    m_createMagicDialog = nullptr;
}

// modifica di una carta creatura
void Controller::modifyOldCreature(const QString& t_nome, unsigned int t_costoMana, const QString& t_rarita,
                                   const QString& t_espansione, const QString& t_effetto, double t_attacco,
                                   double t_vita, const QString& t_tipo){
    Lista<Carta*>::Iteratore it = m_listaCarte->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    Creatura* daModificare = dynamic_cast<Creatura*>(*it);

    if(t_tipo != daModificare->getTipoCreatura()){
        delete *it;

        if(t_tipo == "Bestia"){
            (*it) = new Bestia(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
        }
        else if(t_tipo == "Demone"){
            (*it) = new Demone(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
        }
        else if(t_tipo == "Neutrale"){
            (*it) = new Neutrale(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
        }
        else if(t_tipo == "Drago"){
            (*it) = new Drago(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
        }
        else if(t_tipo == "Murloc"){
            (*it) = new Murloc(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
        }
        else if(t_tipo == "Pirata"){
            (*it) = new Pirata(t_nome, t_costoMana, t_rarita, t_espansione, t_attacco, t_vita, t_effetto);
        }
    }
    else{
        if(t_nome != daModificare->getNome()){
            daModificare->setNome(t_nome);
        }
        if(t_costoMana != daModificare->getCostoMana()){
            daModificare->setCostoMana(t_costoMana);
        }
        if(t_rarita != daModificare->getRarita()){
            daModificare->setRarita(t_rarita);
        }
        if(t_espansione != daModificare->getEspansione()){
            daModificare->setEspansione(t_espansione);
        }
        if(t_effetto != daModificare->getEffetto()){
            daModificare->setEffetto(t_effetto);
        }
        if(t_attacco != daModificare->getAttacco()){
            daModificare->setAttacco(t_attacco);
        }
        if(t_vita != daModificare->getVita()){
            daModificare->setVita(t_vita);
        }
    }

    setCardTable();
    m_createCreatureDialog->close();
    delete m_createCreatureDialog;
    m_createCreatureDialog = nullptr;
}

// eliminazione di un utente
void Controller::destroyUser(){
    Lista<Utente*>::Iteratore it = m_listaUtenti->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    if(m_loggedUser == *it){
        QMessageBox message;
        message.setText("Non puoi eliminare te stesso!");
        message.exec();
    }
    else{
        m_listaUtenti->erase(it);
        QMessageBox message;
        message.setText("Utente eliminato");
        message.exec();
        setUserTable();
    }
}

// eliminazione di una carta
void Controller::destroyCard(){
    Lista<Carta*>::Iteratore it = m_listaCarte->begin();

    for(int index = 0; index < m_tableDialog->getTable()->currentRow(); ++index, ++it){}

    m_listaCarte->erase(it);
    QMessageBox message;
    message.setText("Carta eliminata");
    message.exec();
    setCardTable();
}






