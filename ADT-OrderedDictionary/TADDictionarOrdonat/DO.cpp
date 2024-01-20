//
// Created by ultra on 03.06.2023.
//
#include "Iterator.h"
#include "DO.h"
#include <iostream>
#include <exception>

using namespace std;
//θ(capacitate)
DO::DO(Relatie r) : r(r) {
    cap = 256;
    root = 0;
    size = 0;
    elements = new TElem[cap];
    left = new int[cap];
    right = new int[cap];
    firstFREE = 0;
    for (int i = 0; i < cap; i++) {
        left[i] = null;
        right[i] = null;
        elements[i] = {null, null};
    }
}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
//complexitate timp: O(h)
TValoare DO::adauga(TCheie c, TValoare v) {
    if (vid()) {
        this->elements[0] = {c, v};
        this->firstFREE = 1;
        this->size++;
        return NULL_TVALOARE;
    }
    if (this->dim() == this->cap - 1)
        resize();
    int old_value = INT_MAX;
    add_rec(this->root, {c, v}, old_value);
    size += (old_value == INT_MAX);
    return old_value == INT_MAX ? -1 : old_value;
}


//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
//complexitate timp: O(h)
TValoare DO::cauta(TCheie c) const {
    int rez = -1;
    int curent = this->root;
    while (curent != null) {
        if (this->r(this->elements[curent].first, c)) {
            if (c == this->elements[curent].first)
                rez = this->elements[curent].second;
            curent = this->right[curent];
        } else {
            curent = this->left[curent];
        }
    }
    return rez;
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
//complexitate timp: O(h)
TValoare DO::sterge(TCheie c) {
    TValoare f = null;
    this->root = sterge_rec(this->root, c, f);
    if (f == null)
        return NULL_TVALOARE;
    else {
        this->size--;
        return f;

    }
}


//returneaza numarul de perechi (cheie, valoare) din dictionar
//θ(1)
int DO::dim() const {
    return this->size;
}

//verifica daca dictionarul e vid
//θ(1)
bool DO::vid() const {
    return this->size == 0;
}

//θ(1)
Iterator DO::iterator() const {
    return Iterator(*this);
}
//θ(1)
DO::~DO() {
    delete[] elements;
    delete[] left;
    delete[] right;
}

//complexitate timp: O(capacitate)
void DO::resize() {
    int new_cap = 2 * cap;
    TElem *new_elems = new TElem[new_cap];
    int *new_left = new int[new_cap];
    int *new_right = new int[new_cap];
    for (int i = 0; i < cap; i++) {
        new_elems[i] = elements[i];
        new_left[i] = left[i];
        new_right[i] = right[i];
    }
    for (int i = this->cap; i < this->cap * 2; i++) {
        new_elems[i] = {null, null};
        new_left[i] = null;
        new_right[i] = null;
    }
    delete[] elements;
    delete[] left;
    delete[] right;
    elements = new_elems;
    left = new_left;
    right = new_right;
    firstFREE = cap;
    cap = new_cap;
}
//complexitate timp: O(h)
int DO::add_rec(int p, TElem e, int &old_value) {
    if (p == null) {
        this->elements[this->firstFREE] = e;
        int old = this->firstFREE;
        first_free();
        return old;

    }
    if (e.first == elements[p].first) //
    {
        old_value = elements[p].second;
        elements[p].second = e.second;
        return p;
    } else if (!r(this->elements[p].first, e.first)) {
        this->left[p] = add_rec(this->left[p], e, old_value);
        return p;
    } else {
        this->right[p] = add_rec(this->right[p], e, old_value);
        return p;
    }
}
//complexitate timp: O(n)
void DO::first_free() {
    if (this->elements[this->firstFREE] != std::make_pair(null, null))
        this->firstFREE++;
}
//complexitate timp: O(h)
int DO::min(int nod) {//minimul din arbore
    int curent = nod;
    while (this->left[curent] != null) {
        curent = this->left[curent];
    }
    return curent;
}
//complexitate timp: O(h)
int DO::sterge_rec(int p, TCheie e, TValoare &found) {
    if (p == null) {
        return null;
    }
    if (this->elements[p].first == e) {
        found = elements[p].second;
        if (this->left[p] == null && this->right[p] == null)
            return null;
        else if (this->left[p] == null) {
            return this->right[p];
        } else if (this->right[p] == null) {
            return this->left[p];
        } else {
            int minim = min(this->right[p]);
            this->elements[p] = this->elements[minim];
            this->right[p] = sterge_rec(this->right[p], this->elements[minim].first, found);
            return p;
        }
    } else if (!r(this->elements[p].first, e)) {
        this->left[p] = sterge_rec(this->left[p], e, found);
        return p;
    } else {
        this->right[p] = sterge_rec(this->right[p], e, found);
        return p;
    }
}