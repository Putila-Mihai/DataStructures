#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>

using namespace std;

 // BC=WC=AC = Theta(1)
Colectie::Colectie(int capacity) {
    this->capacity = capacity;
    this->D = new TElem[capacity];
    this->P = new TElem[capacity*2];
    this->lenght = 0;
    this->nr = 0;
    this->distincte = 0;
}

//BC = Theta(1) , WC = Theta(n) , AC= O(n) || Method for adding an element in the bag (element in D and it's pozition in P)
void Colectie::adauga(TElem elem) {
    if (nr == capacity) {
        redim();
    }
    int ok = 0,gasit=0;
    for (int i = 0; i < this->lenght; i++) {
        if (elem == this->D[i]) {
            ok = i;
            gasit = 1;
            i= this->lenght;
        }
    }
    if (gasit == 0) {
        D[this->lenght] = elem;
        this->lenght++;
        P[this->nr] = this->distincte;
        this->nr++;
        this->distincte++;
    } else {
        P[this->nr] = ok;
        nr++;
    }
}

//WC = theta(n) , BC = Theta(1) , AC = O(n) || This method remove an element from the bag by searching it in
// D and after that deleting an occurence in P if there are no occurences left in P that delete the number from D too
bool Colectie::sterge(TElem elem) {
    if(this->lenght==1 && this->nr == 1){
        if(D[0]==elem){
            this->lenght--;
            this->nr--;
            this->distincte--;
            return true;
        }
        else
            return false;
    }
    int poz = 0,gasit=0;//cauta elementul in dictionar
    for (int i = 0; i < this->lenght; i++) {
        if (elem == this->D[i]) {
            poz = i;
            gasit = 1;
            i= this->lenght;
        }
    }
    if (gasit == 0)
        return false;
    else {
        int ok = 0, start;
        for (int i = 0; i < this->nr; i++) {
            if (poz == this->P[i]) {
                start = i;
                i = this->nr + 1;
            }
        }
        for (int j = start; j < this->nr; j++) {
            this->P[j] = this->P[j + 1];
        }
        for (int j = start; j < this->nr; j++) {
            if (P[j] == poz)ok++;
        }
        this->nr--;
        if (ok == 0) {
            for (int j = poz; j < this->lenght; j++) {
                this->D[j] = this->D[j + 1];
            }
            for (int i = 0; i < this->nr; i++){
                if(P[i]>=poz){
                    P[i]--;
                }
            }
            this->distincte--;
            this->lenght--;
        }
        return true;
    }

}

// WC = Theta(n) , BC = Theta(1) , AC = O(n)  || this method use sequential search to find an element in the bag
bool Colectie::cauta(TElem elem) const {
    int ok = 0;//cauta elementul in dictionar
    for (int i = 0; i < this->lenght; i++) {
        if (elem == this->D[i]) {
            ok = 1;
            i= this->lenght;
        }
    }
    if (ok == 0)
        return false;
    return true;
}
// WC=BC=AC = Theta(n) || this method search if the elemnt exist in the bag and count he number of occurences in P
int Colectie::nrAparitii(TElem elem) const {
    int poz = 0,numere=0,ok=0;//cauta elementul in dictionar
    for (int i = 0; i < this->lenght; i++) {
        if (elem == this->D[i]) {
            poz = i;
            ok=1;
            i= this->lenght;
        }
    }
    if (ok ==1) {
        for (int j = 0; j < this->nr; j++) {
        if (poz == P[j])
            numere++;
    }
    }
    return numere;
}

//WC=BC=AC = Theta(1)
int Colectie::dim() const {

    return this->nr;
}

//WC=BC=AC = Theta(1)
bool Colectie::vida() const {
    if (this->lenght == 0)
    return true;
    else
        return false;
}
//WC=BC=AC = Theta(1)
IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}

//WC=BC=AC = Theta(1)
Colectie::~Colectie() {
    delete[] D;
    delete[] P;
}
//WC=BC=AC = Theta(n)
void Colectie::redim() {
    TElem *Dnou = new int[2 * capacity];
    TElem *Pnou = new int[2 * capacity];
    for (int i = 0; i < lenght; i++)
        Dnou[i] = D[i];
    for (int i = 0; i < nr; i++)
        Pnou[i] = P[i];
    capacity = capacity * 2;
    delete[] D;
    delete[] P;
    D = Dnou;
    P = Pnou;
}
//BC=WC=AC =Theta (n)
 int Colectie::transformainmultime() {
    for(int i=0;i<this->lenght;i++){
        int aparitii = nrAparitii(D[i]);
        int nr=0;
        while(aparitii > 1){
            sterge(D[i]);
            aparitii--;
            nr++;
        }
    }
    return nr;
}