//
// Created by ultra on 02.06.2023.
//

#ifndef TADDICTIONAR_DICTIONAR_H
#define TADDICTIONAR_DICTIONAR_H
#define NULL_TVALOARE -1
#include <cstdlib>
#include <cmath>
typedef int TCheie;
typedef int TValoare;

#define MAX 10

class IteratorDictionar;

#include <utility>

typedef std::pair<TCheie, TValoare> TElem;

class Nod;
typedef Nod *PNod;

class Nod {
private:
    TElem e;
    PNod urm;
public:
    friend class Dictionar;

    friend class IteratorDictionar;
    Nod(TElem e, PNod urm);
    TElem element();
    PNod urmator();
    void set_value(TValoare v);
};

class Dictionar {
    friend class IteratorDictionar;

private:
    int m; //numarul de liste din tabela


    [[nodiscard]] int d(int e) const;

public:
    PNod l[MAX];
    // constructorul implicit al dictionarului
    Dictionar();

    // adauga o pereche (cheie, valoare) in dictionar
    //daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
    // daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
    TValoare adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
    [[nodiscard]] TValoare cauta(TCheie c) const;

    //sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
    TValoare sterge(TCheie c);

    //returneaza numarul de perechi (cheie, valoare) din dictionar
    [[nodiscard]] int dim() const;

    //verifica daca dictionarul e vid
    [[nodiscard]] bool vid() const;

    // se returneaza iterator pe dictionar
    [[nodiscard]] IteratorDictionar iterator() const;


    // destructorul dictionarului
    ~Dictionar();

};


#endif //TADDICTIONAR_DICTIONAR_H
