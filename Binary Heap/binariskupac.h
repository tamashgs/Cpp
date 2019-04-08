#include <iostream>
#include <windows.h>

using namespace std;

typedef struct elem{
    int kezd;
    int veg;
    string nev;
    string tel;
    int sorsz;
};

class BinKupac{
    elem *A;
    int n;
    int kupac_meret;
public:
    BinKupac();
    BinKupac(const BinKupac & );
    BinKupac(elem*, int, int );
    ~BinKupac();
    void Maximum_Kupacol(int);
    void Kupacot_Epit();
    void Kupacrendezes();
    void Minimum_Kupacol(int);
    void Min_Kupacot_Epit();
    void Min_Kupacrendezes();
    void Torol(int);
    void Torol_Sorsz(int);
    void Torol_Nev(string);
    void Torol_Telefon(string);
    void Beszur();
    void struktura();
    void szabad();
    void allapot(int);
    void maxnap();
    void minnap();
    int bevetel();
    void bevetel_lista();
    elem* utkozesek(int&);
    void ki();


};

BinKupac::BinKupac(elem t[], int db, int m){
    if ( db > m ) throw "Ennyi elem nem fer bele a kupacba!";
    n = db;
    kupac_meret = m;
    A = new elem[kupac_meret + 10];
    for(int i=0; i<n; i++){
        A[i + 1] = t[i];
    }
}

BinKupac::BinKupac(const BinKupac & k){
    n = k.n;
    kupac_meret = k.kupac_meret;
    A = new elem[kupac_meret];
    for(int i=0; i<n; i++){
        A[i] = k.A[i];
    }
}

BinKupac::BinKupac(){
    n = 0;
    kupac_meret = 0;
    A = new elem[0];
}

BinKupac::~BinKupac(){
    delete []A;
}

void BinKupac::Maximum_Kupacol(int i){

    int b = 2*i;
    int j = 2*i + 1;
    int ma;
    if ( (b <= kupac_meret) && (A[b].veg > A[i].veg) ) ma = b;
    else ma = i;
    if ( (j <= kupac_meret) && (A[j].veg > A[ma].veg) ) ma = j;
    if ( ma != i){
        elem seged = A[i];
        A[i] = A[ma];
        A[ma] = seged;
        Maximum_Kupacol(ma);
    }
}

void BinKupac::Kupacot_Epit(){

    kupac_meret = n;
    for(int i = n/2; i>=1; i--){
        Maximum_Kupacol(i);
    }
}

void BinKupac::Kupacrendezes(){

    for(int i = n; i>=2; i--){
        elem seged = A[1];
        A[1] = A[i];
        A[i] = seged;
        kupac_meret--;
        Maximum_Kupacol(1);
    }
}

void BinKupac::ki(){
    for(int i=1; i<=n; i++){
        cout<<i<<".  "<<A[i].sorsz<<". Nev: "<<A[i].nev<<" Tel.:"<<A[i].tel<<" berbevevesi szandek: "<<A[i].kezd<<" - "<<A[i].veg<<endl;
    }
}

void BinKupac::Torol(int i) {
    A[i] = A[n];
    n--;
    Kupacot_Epit();
    Kupacrendezes();
}

void BinKupac::Torol_Sorsz(int keres) {
    int i = 1;
    while (A[i].sorsz != keres && i<=n ){
        i++;
    }
    if ( i > n) cout<<"Nem letezo sorszam!";
    else{
        cout<<"A kovetkezo megrendelo torolve lett a rendszerbol: ";
        cout<<A[i].sorsz<<". Nev: "<<A[i].nev<<" Tel.:"<<A[i].tel<<" berbevevesi szandek: "<<A[i].kezd<<" - "<<A[i].veg<<endl;
        A[i] = A[n];
        n--;
        Kupacot_Epit();
        Kupacrendezes();
    }
}

void BinKupac::Torol_Nev(string keres) {
    int i = 1;
    while (A[i].nev != keres && i<=n ){
        i++;
    }
    if ( i > n) cout<<"A '"<<keres<<"' nev nem talalhato!"<<endl;
    else{
        cout<<"A kovetkezo megrendelo torolve lett a rendszerbol: ";
        cout<<A[i].sorsz<<". Nev: "<<A[i].nev<<" Tel.:"<<A[i].tel<<" berbevevesi szandek: "<<A[i].kezd<<" - "<<A[i].veg<<endl;
        A[i] = A[n];
        n--;
        Kupacot_Epit();
        Kupacrendezes();
    }
}

void BinKupac::Torol_Telefon(string keres) {
    int i = 1;
    while (A[i].tel != keres && i<=n ){
        i++;
    }
    if ( i > n) cout<<"A '"<<keres<<"' telefonszam nem talalhato!";
    else{
        cout<<"A kovetkezo megrendelo torolve lett a rendszerbol: ";
        cout<<A[i].sorsz<<". Nev: "<<A[i].nev<<" Tel.:"<<A[i].tel<<" berbevevesi szandek: "<<A[i].kezd<<" - "<<A[i].veg<<endl;
        A[i] = A[n];
        n--;
        Kupacot_Epit();
        Kupacrendezes();
    }
}

void BinKupac::Beszur(){
    elem uj;
    cout<<endl<<"Megrendelo adatai:"<<endl;
    cout<<"Nev: ";cin>>uj.nev;
    cout<<"Telefon szam: ";cin>>uj.tel;
    cout<<"Melyik naptol szeretne berbe venni: ";cin>>uj.kezd;
    cout<<"Melyik napig szeretne berbe venni: ";cin>>uj.veg;
    uj.sorsz = n + 1;

    bool megvan = false;
    int i = 1;

    if ( (n == 0) || (A[i].kezd > uj.veg) || (A[n].veg < uj.kezd) )
        megvan = true;

    while (!megvan && i<n){
        if (A[i].veg<uj.kezd && A[i+1].kezd>uj.veg) megvan = true;
            else i++;
    }

    if (megvan){
        n++;
        A[n] = uj;
        Kupacot_Epit();
        Kupacrendezes();
    }else{ throw "Nem lehetseges! Nem szabad abba az idopontba!";}
}

void BinKupac::struktura(){
    char a[32];
    for(int i = 1; i<=31; i++) a[i] = '_';
    for(int i=1; i<=n; i++){
            for(int j=A[i].kezd;j<=A[i].veg;j++) a[j] = '*';
    }

    for(int i = 1; i<=31; i++){
        if (i < 10) cout<<" ";
        cout<<i<<" ";

        if ( (i % 7) == 0){
            cout<<endl;
            for(int j = i - 6; j<=i; j++)
                cout<<" "<<a[j]<<" ";
            cout<<endl;
        }
    }
    cout<<endl;
    for(int j = 29; j<=31; j++)
        cout<<" "<<a[j]<<" ";
}

void BinKupac::szabad(){
    cout<<"Szabad napok:"<<endl;
    int k = 1;
    for(int i=1;i<=n;i++){
        if(A[i].kezd > k) cout<<k<<" - "<<A[i].kezd<<endl;
        k = A[i].veg;
    }
    if (k < 32) cout<<k<<" - 32"<<endl;
}

void BinKupac::allapot(int nap){
    if (nap < 0 || nap > 32){throw "Ilyen nap nincs...";}
    int i = 1;
    int h = 0;
    bool nincs;
    while(i<=n){
        if ((A[i].kezd > nap) && (h < nap)) nincs = true;
            else if ((A[i].kezd <= nap) && (A[i].veg >= nap)) nincs = false;
        h = A[i].veg;
        i++;
    }
    if(nincs || h < nap) cout<<"Jelenleg nincs berbe adva!"<<endl;
        else cout<<"Jelenleg berbe van adva!"<<endl;
}

void BinKupac::maxnap(){
    int max = 0;
    int maxi;
    for(int i=1;i<=n;i++){
        if ((A[i].veg - A[i].kezd) > max){
            max = (A[i].veg - A[i].kezd);
            maxi = i;
        }
    }
    cout<<maxi;
    cout<<"A "<<A[maxi].nev<<" nevu megrendelo vette berbe a leghoszabb idotartamra: "<<A[maxi].veg - A[maxi].kezd<<endl<<"Nyeremenye egy ingyen nap!"<<endl;

}

void BinKupac::minnap(){
    int max = 50;
    int maxi;
    for(int i=1;i<=n;i++){
        if ((A[i].veg - A[i].kezd) < max){
            max = (A[i].veg - A[i].kezd);
            maxi = i;
        }
    }
    cout<<maxi;
    cout<<"A "<<A[maxi].nev<<" nevu megrendelo vette berbe a legrovidebb idotartamra: "<<A[maxi].veg - A[maxi].kezd<<endl<<"Nyeremenye egy ingyen nap!"<<endl;

}

int BinKupac::bevetel(){
    int b = 0;
    for(int i=1;i<=n;i++){
        b += 100;
        b += 50 * (A[i].veg - A[i].kezd);
    }
    return b;
}

void BinKupac::bevetel_lista(){
    int b = 0;
    for(int i=1; i<=n; i++){
        b = 100 + 50 * (A[i].veg - A[i].kezd);
        cout<<A[i].sorsz<<". Nev: "<<A[i].nev<<" Tel.:"<<A[i].tel<<" berbeveves: "<<A[i].kezd<<" - "<<A[i].veg<<" - fizetett oszeg: "<<b<<" €"<<endl;
    }
}

elem* BinKupac::utkozesek(int &j){
    elem *b;
    b = new elem[n];
    int i = 2;

    while( i <= n){
        if (A[i-1].veg >= A[i].kezd){
            b[j] = A[i-1];
            j++;
            A[i-1].veg = 0;
            A[i-1].kezd = 0;
        }
        else i++;
    }

    Min_Kupacot_Epit();
    Min_Kupacrendezes();
    n = n - j + 1;
    Kupacot_Epit();
    Kupacrendezes();
    return b;
}

void BinKupac::Minimum_Kupacol(int i){

    int b = 2*i;
    int j = 2*i + 1;
    int ma;
    if ( (b <= kupac_meret) && (A[b].veg < A[i].veg) ) ma = b;
    else ma = i;
    if ( (j <= kupac_meret) && (A[j].veg < A[ma].veg) ) ma = j;
    if ( ma != i){
        elem seged = A[i];
        A[i] = A[ma];
        A[ma] = seged;
        Minimum_Kupacol(ma);
    }
}

void BinKupac::Min_Kupacot_Epit(){

    kupac_meret = n;
    for(int i = n/2; i>=1; i--){
        Minimum_Kupacol(i);
    }
}

void BinKupac::Min_Kupacrendezes(){

    for(int i = n; i>=2; i--){
        elem seged = A[1];
        A[1] = A[i];
        A[i] = seged;
        kupac_meret--;
        Minimum_Kupacol(1);
    }
}
