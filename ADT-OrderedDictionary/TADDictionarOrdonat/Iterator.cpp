//
// Created by ultra on 03.06.2023.
//
#include "Iterator.h"
#include "DO.h"
#include <iostream>
using namespace std;
//complexitate timp: O(h)
Iterator::Iterator(const DO& d) : dict(d){
    int nod = dict.root;
    while(nod!=null)
    {
        this->stiva.push(nod);
        nod = dict.left[nod];
    }
    if(!this->stiva.empty())
    {
        this->pos = stiva.top();
    }
    else
        this->pos = null;
}
//complexitate timp: O(h)
void Iterator::prim(){
    while (!this->stiva.empty()) {
        this->stiva.pop();
    }
    int nod = dict.root;
    while (nod != null) {
        this->stiva.push(nod);
        nod = dict.left[nod];
    }
    if (!this->stiva.empty()) {
        this->pos = this->stiva.top();
    }
    else {
        this->pos = null;
    }
}
//complexitate timp: O(h)
void Iterator::urmator(){
    if (!valid())
        throw std::exception();
    int nod = this->stiva.top();
    this->stiva.pop();
    if (dict.right[nod] != null) {
        nod = dict.right[nod];
        while (nod != null) {
            this->stiva.push(nod);
            nod = dict.left[nod];
        }
    }
    if (!this->stiva.empty()) {
        this->pos = this->stiva.top();
    }
    else {
        this->pos = null;
    }
}
//complexitate timp:theta(1)
bool Iterator::valid() const{
    if (dict.vid())
        return false;
    return this->pos != null;
}
//complexitate timp: theta(h)
TElem Iterator::element() const{
    if (!valid())
        throw std::exception();
    return dict.elements[pos];
}
//complexitate timp: O(k)
void Iterator::avanseazaKPasi(int k) {
    prim();
    if(k<0)
        throw std::exception();
    for(int i=1;i<k;i++)
    {
        urmator();
    }
    if(!valid())
        throw std::exception();
}
