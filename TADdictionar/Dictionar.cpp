#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"
//complexitate timp: theta(1)
int hashCode(int e) {

    return std::abs(e);
}
//complexitate timp: theta(1)
int Dictionar::d(int e) const {
    //dispersia prin diviziune
    return hashCode(e) % m;
}
//complexitate timp: theta(1)
Nod::Nod(TElem e, PNod urm) {
    this->e = e;
    this->urm = urm;
}
//complexitate timp: theta(1)
TElem Nod::element() {
    return this->e;
}
//complexitate timp: theta(1)
PNod Nod::urmator() {
    return this->urm;
}
//complexitate timp: theta(1)
void Nod::set_value(TValoare v) {
    this->e.second = v;
}
//complexitate timp: theta(m)
Dictionar::Dictionar() {
    m = MAX;
    for (int i = 0; i < m; i++) {
        l[i] = nullptr;
    }
}
//complexitate timp: theta(m)
Dictionar::~Dictionar() {
    for (int i = 0; i < m; i++) {
        while (l[i] != nullptr) {
            PNod p = l[i];
            l[i] = l[i]->urm;
            delete p;
        }
    }
}
//complexitatea timp medie : theta(𝟏)
TValoare Dictionar::adauga(TCheie c, TValoare v) {
    //locatia de dispersie a cheii
    int i = d(c);
    //se creeaza un nod
    TElem e = std::make_pair(c, v);
    PNod p = new Nod(e, nullptr);
    PNod j = l[i];
    while (j != nullptr) {
        if (j->element().first == c) {
            TValoare rez = j->element().second;
            j->set_value(e.second);
            return rez;
        }
        j = j->urmator();
    }
    p->urm = l[i];
    l[i] = p;
    return NULL_TVALOARE;
}


//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
//complexitatea timp medie : theta(𝟏) , WC = O(n)
TValoare Dictionar::cauta(TCheie c) const {
    IteratorDictionar I = iterator();
    while(I.valid())
    {
        if(I.element().first == c)
            return I.element().second;
        I.urmator();
    }
    return NULL_TVALOARE;
}

//complexitatea timp medie : O(n)
TValoare Dictionar:: sterge(TCheie c) {
    PNod last = nullptr;
    int i = d(c);
    PNod curr = l[i];
    while(curr!= nullptr){
        if(curr->element().first==c)
        {
            if(last == nullptr){
                l[i]=curr->urmator();
                int rez = curr->element().second;
                free(curr);
                return rez;
            }
            else
            {
                last->urm=curr->urmator();
                int rez = curr->element().second;
                free(curr);
                return rez;
            }
        }
        last = curr;
        curr = curr ->urmator();
    }
    return NULL_TVALOARE;
}

//complexitatea timp medie : theta(n)
int Dictionar::dim() const {
    IteratorDictionar I = iterator();
    int nr=0;
    while(I.valid())
    {
        nr++;
        I.urmator();
    }
    return nr;
}
//complexitatea timp medie : theta(n)
bool Dictionar::vid() const {
    if(dim()==0)
    return true;
    else
        return false;
}

//complexitatea timp medie : theta(𝟏)
IteratorDictionar Dictionar::iterator() const {
    return IteratorDictionar(*this);
}

