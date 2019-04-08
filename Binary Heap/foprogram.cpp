#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "binariskupac.h"

using namespace std;

void beolvas(elem *a,int &db,int &m){
    ifstream f("teszt5.txt");
    f>>db;
    f>>m;
    for(int i=0; i<db; i++){
        f>>a[i].sorsz>>a[i].kezd>>a[i].veg>>a[i].nev>>a[i].tel;
    }
}

void kit(elem *a,int db){
    for(int i=1; i<db; i++){
        cout<<a[i].sorsz<<". Nev: "<<a[i].nev<<" Tel.:"<<a[i].tel<<" berbe vevesi szandek: "<<a[i].kezd<<" - "<<a[i].veg<<endl;
    }
}

void menu(){
    cout<<"------------------------------------"<<endl;
    cout<<"     1. Megrendelesek"<<endl;
    cout<<"     2. Beosztas"<<endl;
    cout<<"     3. Beszuras"<<endl;
    cout<<"     4. Torles"<<endl;
    cout<<"     5. Szabad napok"<<endl;
    cout<<"     6. A honap strukturaja"<<endl;
    cout<<"     7. Jelenlegi allapot"<<endl;
    cout<<"     8. Nyeremenyjatek"<<endl;
    cout<<"     9. Bevetel"<<endl;
    cout<<"     15. Kilepes"<<endl;
    cout<<"------------------------------------"<<endl;
}

int main(){
    system("Color 3");
    int m;
    int db;
    elem *a;
    a = new elem[100];
    beolvas(a,db,m);
    menu();
    try{
        int opcio;
        BinKupac k(a,db,m);
        cin>>opcio;
        while(opcio != 15){
        switch(opcio){
            case 1:
                k.ki();
                break;
            case 2:{
                k.Kupacot_Epit();
                k.Kupacrendezes();
                elem *viszut;
                int viszutdb = 1;
                viszut = k.utkozesek(viszutdb);
                k.ki();
                cout<<"Visszautasitottak:"<<endl;
                kit(viszut,viszutdb);
                break;
            }
            case 3:
                try{
                k.Beszur();
                k.ki();
                }catch (const char *h){ cout<<h<<endl; }
                break;
            case 4:{
                cout<<"Hogyan szeretne torolni?"<<endl;
                cout<<"1. Nev szerint."<<endl;
                cout<<"2. Telefonszam szerint."<<endl;
                cout<<"3. Sorszam szerint."<<endl;
                int t;
                cin>>t;
                string s;
                int b;
                switch(t){
                case 1:
                    cout<<"Irja be a torlendo nevet: ";
                    cin>>s;
                    k.Torol_Nev(s);
                    break;
                case 2:
                    cout<<"Irja be a torlendo telefonszamat: ";
                    cin>>s;
                    k.Torol_Telefon(s);
                    break;
                case 3:
                    cout<<"Irja be a torlendo sorszamat: ";
                    cin>>b;
                    k.Torol_Sorsz(b);
                    break;
                }
            break;
            }
            case 5:
                k.szabad();
            break;
            case 6:
                k.struktura();
            break;
            case 7:{
                int d;
                cout<<"Mai datum: "; cin>>d;
                try{ k.allapot(d);
                }catch (const char *h){ cout<<h<<endl; }
            break;
            }
            case 8:{
                cout<<"Ki kapjon nyeremenyt?"<<endl;
                cout<<"1. Random !!epp nem mukodik!!"<<endl;
                cout<<"2. Legtobb napra berbe vevo"<<endl;
                cout<<"3. Legkevesebb napra berbe vevo"<<endl;
                int t;
                cin>>t;
                switch(t){
                case 1:
                    //k.random();
                    break;
                case 2:
                    k.maxnap();
                    break;
                case 3:
                    k.minnap();
                    break;
                }
            break;
            }
            case 9:{
                cout<<"1. Bevetel szemelyenkent."<<endl;
                cout<<"2. Oszbevetel."<<endl;
                int t;
                cin>>t;
                switch(t){
                case 1:
                    k.bevetel_lista();
                break;
                case 2:
                    cout<<"Bevetel: "<<k.bevetel()<<" €";
                break;
                }
            break;
            }
        }
        cin>>opcio;
        system("cls");
        menu();
        }
    }
    catch(const char *h){ cout<<h; }
    cout<<"Viszont latasra!";
}
