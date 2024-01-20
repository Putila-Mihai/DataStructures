#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>
using namespace std;
//complexitatea timp medie : theta(𝟏)
void IteratorDictionar::deplasare(){
//gaseste prima lista nevida incepand cu locatia poz din tabela
    while (poz<dict.m && dict.l[poz]==nullptr) poz++;
    if (poz<dict.m)
        curent=dict.l[poz];
}
//complexitatea timp medie : theta(𝟏)
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
     poz = 0;
     deplasare();
}

//complexitatea timp medie : theta(𝟏)
void IteratorDictionar::prim() {
    poz=0;
    deplasare();
}

//complexitatea timp medie : theta(𝟏)
void IteratorDictionar::urmator() {
    if(valid()==false)
        throw std::exception();
    curent=curent->urm;
    if (curent==nullptr){
        poz=poz+1;
        deplasare();
    }

}

//complexitatea timp medie : theta(𝟏)
TElem IteratorDictionar::element() const{
    if(valid())
    return curent->e;
    else
        throw std::exception();
    //return pair <TCheie, TValoare>  (-1, -1);
}

//complexitatea timp medie : theta(𝟏)
bool IteratorDictionar::valid() const {
    return (poz<dict.m) && (curent != nullptr);
}
