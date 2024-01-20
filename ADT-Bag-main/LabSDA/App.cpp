#include <iostream>
#include "Colectie.h"
#include "IteratorColectie.h"
#include "TestExtins.h"
#include "TestScurt.h"
using namespace std;
void creare(Colectie& c) {
    for(int i=1; i<=6;i++){
        c.adauga(i);
    }
}
void tiparire(Colectie& c){
    IteratorColectie i =c.iterator();
    i.prim();
    while(i.valid()){
        cout<<i.element()<<' ';
        i.urmator();
    }
}

int main() {
	testAll();
    testAllExtins();
    cout<<"End";
}