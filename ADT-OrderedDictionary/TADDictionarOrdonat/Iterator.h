//
// Created by ultra on 03.06.2023.
//

#ifndef TADDICTIONARORDONAT_ITERATOR_H
#define TADDICTIONARORDONAT_ITERATOR_H

#include "DO.h"
#include<stack>
#include<exception>
#define null -99999
class Iterator{
    friend class DO;
private:
    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    Iterator(const DO& dictionar);

    //contine o referinta catre containerul pe care il itereaza
    const DO& dict;

    int pos;
    std::stack<int>stiva;


public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;

    //mută cursorul iteratorului a.î. să refere al k-lea element începând de la cel curent. Iteratorul devine nevalid în cazul în care există mai puțin de k elemente rămase în dicționar.
    //aruncă excepție în cazul în care iteratorul este nevalid sau k este zero ori negativ.
    void avanseazaKPasi(int k);
};

#endif //TADDICTIONARORDONAT_ITERATOR_H
