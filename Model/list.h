#ifndef LIST_H
#define LIST_H

template <class T>
class Lista{

    friend class Iteratore;

private:

    class Nodo{

    public:

        T m_info;
        Nodo* m_next;
        Nodo* m_prec;

        Nodo(const T&, Nodo* = nullptr, Nodo* = nullptr);

    };

    static void distruggi(Nodo*);
    Nodo* copia(Nodo*);

    Nodo* m_first;
    Nodo* m_last;

public:

    class Iteratore{

        friend class Lista;

    private:

        Nodo* m_punt;

    public:

        bool operator==(const Iteratore&) const;
        bool operator!=(const Iteratore&) const;
        Iteratore& operator++();
        Iteratore operator++(int);
        Iteratore& operator--();
        Iteratore operator--(int);
        T& operator*();

    };

    Lista();
    Lista(const Lista&);
    ~Lista();

    Lista& operator=(const Lista&);
    T& operator[](Iteratore);

    bool isEmpty() const;
    void push_front(const T&);
    void push_back(const T&);
    int getN_elem();
    bool find(const T&);

    Iteratore findIterator(const T&);
    void erase(Iteratore);
    Iteratore begin() const;
    Iteratore end() const;

};

// ======================================
//     IMPLEMENTAZIONE CLASSE NODO
// ======================================

// costruzione oggetto classe nodo settando i membri
template <class T>
Lista<T>::Nodo::Nodo(const T& t_info, Nodo* t_next, Nodo* t_prec):
                    m_info(t_info), m_next(t_next), m_prec(t_prec){}

// ======================================
//   IMPLEMENTAZIONE CLASSE ITERATORE
// ======================================

// operatori di iteratore
// == , != , ++ (pre,post), -- (pre,post), *
template <class T>
bool Lista<T>::Iteratore::operator==(const Iteratore& t_iter) const{
    return m_punt == t_iter.m_punt;
}

template <class T>
bool Lista<T>::Iteratore::operator!=(const Iteratore& t_iter) const{
    return m_punt != t_iter.m_punt;
}

template <class T>
typename Lista<T>::Iteratore& Lista<T>::Iteratore::operator++(){
    if(m_punt){
        m_punt = m_punt->m_next;
    }

    return *this;
}

template <class T>
typename Lista<T>::Iteratore Lista<T>::Iteratore::operator++(int){
    Iteratore aux = *this;

    if(m_punt){
        m_punt = m_punt->m_next;
    }

    return aux;
}

template <class T>
typename Lista<T>::Iteratore& Lista<T>::Iteratore::operator--(){
    if(m_punt){
        m_punt = m_punt->m_prec;
    }

    return *this;
}

template <class T>
typename Lista<T>::Iteratore Lista<T>::Iteratore::operator--(int){
    Iteratore aux = *this;

    if(m_punt){
        m_punt = m_punt->m_prec;
    }

    return aux;
}

template <class T>
T& Lista<T>::Iteratore::operator*(){
    return m_punt->m_info;
}

// ======================================
//   IMPLEMENTAZIONE CLASSE LISTA
// ======================================

// distrugge ricorsivamente la lista a partire da p
template <class T>
void Lista<T>::distruggi(Nodo* t_delete){
    if(t_delete){
        distruggi(t_delete->m_next);
        delete t_delete;
    }
}

// copia ricorsivamente la lista a partire da p
template <class T>
typename Lista<T>::Nodo* Lista<T>::copia(Nodo* t_copia){
    Nodo* temp = nullptr;

    if(t_copia){
        temp = new Nodo(t_copia->m_info, copia(t_copia->m_next));

        if(temp->m_next){
            temp->m_next->m_prec = temp;
        }
        else{
            m_last = temp;
        }
    }

    return temp;
}

// costruzione di default
template <class T>
Lista<T>::Lista(): m_first(nullptr), m_last(nullptr){}

// costruttore di copia
template <class T>
Lista<T>::Lista(const Lista& t_lista): m_first(copia(t_lista.m_first)){}

// distruttore
template <class T>
Lista<T>::~Lista(){
    if(m_first){
        distruggi(m_first);
    }
}

// operatore della classe Lista
// = , []
template <class T>
Lista<T>& Lista<T>::operator=(const Lista& t_lista){
    if(*this != t_lista){
        delete this;
        m_first = copia(t_lista.m_first);
    }

    return *this;
}

template <class T>
T& Lista<T>::operator[](Iteratore t_pos){
    return *t_pos;
}

// restituisce true se la coda è vuota, false altrimenti
template <class T>
bool Lista<T>::isEmpty() const{
    return (m_first == nullptr);
}

// inserisce un elemento in testa alla lista
template <class T>
void Lista<T>::push_front(const T& t_info){
    if(isEmpty()){
        m_first = m_last = new Nodo(t_info);
    }
    else{
        m_first = new Nodo(t_info, m_first);
        m_first->m_next->m_prec = m_first;
    }
}

// inserisce un elemento in coda alla lista
template <class T>
void Lista<T>::push_back(const T& t_info){
    if(isEmpty()){
        m_first = m_last = new Nodo(t_info);
    }
    else{
        m_last->m_next = new Nodo(t_info);
        m_last->m_next->m_prec = m_last;
        m_last = m_last->m_next;
    }
}

// restituisce il numero di elementi all'interno della lista
template <class T>
int Lista<T>::getN_elem(){
    int elementi = 0;
    Nodo* scorro = m_first;

    if(scorro){
        while(scorro){
            elementi++;
            scorro = scorro->m_next;
        }
    }

    return elementi;
}

// restituisce true se l'elemento "cercato" è nella lista
// false altrimenti
// NOTA: per funzionare, il tipo T deve avere l'operatore di uguaglianza
template <class T>
bool Lista<T>::find(const T& t_cercato){
    for(Nodo* scorro = m_first; scorro; scorro = scorro->m_next){
        if(t_cercato == scorro->m_info){
            return true;
        }

        scorro = scorro->m_next;
    }

    return false;
}

// restituisce l'iteratore dell'elemento uguale a T se questo è nella
// lista, altrimenti restituisce l'iteratore nullo (iteratore con
// campo punt a "nullptr")
template <class T>
typename Lista<T>::Iteratore Lista<T>::findIterator(const T& t_cercato){
    for(Iteratore it = begin(); it != end(); ++it){
        if((*it) == t_cercato){
            return it;
        }
    }

    return nullptr;
}

// elimina l'elemento alla posizione "iteratore" e restituisce
// l'iteratore all'elemento successivo
template <class T>
void Lista<T>::erase(Lista<T>::Iteratore t_pos){
    Nodo* daEliminare = t_pos.m_punt;

    if(daEliminare == m_first){
        m_first = daEliminare->m_next;
    }
    else{
        daEliminare->m_prec->m_next = daEliminare->m_next;

        if(daEliminare->m_next){
            daEliminare->m_next->m_prec = daEliminare->m_prec;
        }
        else{
            m_last = daEliminare->m_prec;
            daEliminare->m_prec = 0;
        }
    }

    delete daEliminare;
}

// restituisce l'iteratore al primo elemento
template <class T>
typename Lista<T>::Iteratore Lista<T>::begin() const{
    Iteratore aux;
    aux.m_punt = m_first;
    return aux;
}

// restituisce l'iteratore all'ultimo elemento
template <class T>
typename Lista<T>::Iteratore Lista<T>::end() const{
    Iteratore aux;
    aux.m_punt = 0;
    return aux;
}

#endif
















