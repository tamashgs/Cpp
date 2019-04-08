#include <iostream>
#include "NagyEgesz.h"
#include "NagyEgesz.cpp"

using namespace std;


int main(){
    int a[]={1,2,3,4};
    //int a[]={1,0,0,0};
    int b[]={1,2,3,6};
    NagyEgesz t(1,4,a);
    NagyEgesz l(1,4,b);

    if (t>l){ t.kiir(); cout<<" > "; l.kiir(); }
    else{ t.kiir(); cout<<" < "; l.kiir(); }

    cout<<endl;

    /*t.kiir();
    cout<<" * ";
    l.kiir();
    cout<<" = ";
    NagyEgesz sz = t.szoroz(l);
    sz.kiir();*/

    cout<<endl;

    t.kiir();
    cout<<" + ";
    l.kiir();
    cout<<" = ";
    NagyEgesz o = t.osszead(l);
    o.kiir();

    cout<<endl;

    t.kiir();
    cout<<" - ";
    l.kiir();
    cout<<" = ";
    NagyEgesz k = t.kivon(l);
    k.kiir();

    cout<<endl;

    t.kiir();
    cout<<" / ";
    l.kiir();
    cout<<" = ";
    NagyEgesz osz = t.oszt(l);
    osz.kiir();

    //szamol();

    return 0;
}
