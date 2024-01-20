//
// Created by ultra on 02.06.2023.
//

#ifndef TADDICTIONAR_ITERATORDICTIONAR_H
#define TADDICTIONAR_ITERATORDICTIONAR_H
#include "Dictionar.h"

class IteratorDictionar
{
    friend class Dictionar;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorDictionar(const Dictionar& d);

    //contine o referinta catre containerul pe care il itereaza
    const Dictionar& dict;

    int poz; // pozitia curenta din tabela
    PNod curent; //pozitia curenta in interiorul l;istei independente din tabela

    void deplasare();

public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    [[nodiscard]] bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    [[nodiscard]] TElem element() const;
};
#endif //TADDICTIONAR_ITERATORDICTIONAR_H
