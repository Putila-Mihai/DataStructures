//
// Created by ultra on 31.03.2023.
//
#include "IteratorColectie.h"
#include "Colectie.h"

//WC=BC=AC = Theta(1)
IteratorColectie::IteratorColectie(const Colectie &c) : col(c) {
    curent = 0;
}
//WC=BC=AC = Theta(1)
void IteratorColectie::prim() {
    curent = 0;
}

//WC=BC=AC = Theta(1)
void IteratorColectie::urmator() {
    if(valid())
        curent++;
    else
    {
        throw "Iterator invalid";
    }
}

//WC=BC=AC = Theta(1)
bool IteratorColectie::valid() const {
    return curent < col.dim();
}

//WC=BC=AC = Theta(1)
TElem IteratorColectie::element() const {
    if(valid())
    return col.D[col.P[curent]];
    else
    {
        throw "Iterator invalid";
    }
}