#include <iostream>
#include <unistd.h>
#include "NagyEgesz.h"

using namespace std;

NagyEgesz::NagyEgesz(){
    szamjegyek = new int[1];
    szamjegyek[0]=0;
    n=0;
    elojel=1;
}

NagyEgesz::NagyEgesz(int elojel, int m, const int* szamjegyek){
    m--;
    this->elojel = elojel;
    this->n = m;
    this->szamjegyek = new int[n];
    for(int i=0;i<=n;i++){
        this->szamjegyek[i] = szamjegyek[i];
    }
}

NagyEgesz::NagyEgesz(const NagyEgesz& a){

    this->elojel = a.elojel;
    this->n = a.n;
    this->szamjegyek = new int[n];
    for(int i=0;i<=n;i++){
        this->szamjegyek[i] = a.szamjegyek[i];
    }
}

NagyEgesz::~NagyEgesz(){
    delete []szamjegyek;
}

bool NagyEgesz::nulla(){
    if(n == 0 && szamjegyek[0] == 0) return true;
    return false;
}

bool NagyEgesz::operator>(const NagyEgesz& a){

    if (n>a.n) return true;
    if (a.n>n) return false;
    if (n == a.n){
        int i = 0;
        while (szamjegyek[i] == a.szamjegyek[i]){
            i++;
        }
        if (szamjegyek[i]>a.szamjegyek[i]) return true;
        else return false;
    }
    return false;
}

bool NagyEgesz::operator>=(const NagyEgesz& a){

    if (n>a.n) return true;
    if (a.n>n) return false;
    if (n == a.n){
        int i = 0;
        while (szamjegyek[i] == a.szamjegyek[i]){
            i++;
        }
        if (szamjegyek[i]>=a.szamjegyek[i]) return true;
        else return false;
    }
    return false;
}

void kit(int a[],int n){
    for(int i=0;i<=n;i++) cout<<a[i]<<" ";
}

void szorozegyel(int a[],int &n,int b){
    int m=0;
    for(int i=n;i>=0;i--){
        a[i] = (a[i] * b) + m;
        m = a[i] / 10;
        a[i]%=10;
    }
    //cout<<"**";kit(a,n);cout<<"**";
    if(m){
        for(int i=n;i>=0;i--) a[i+1]=a[i];
        a[0]=m;
        n++;
    }
    //cout<<"**";kit(a,n);cout<<"**";
}

void szamol(){
    int e[100];
    int ne = 0;
    int i = 0;
    int z = 0;
    while(z < 1000){
        i++;
        z++;
        if (i > 9){
            if (ne == 0){
                ne++;
                e[ne-1] = 1;
                i = 0;
            }
            else{

            bool veg = false;
            int j = ne - 1;
            while (!veg && j >=0){
                if (e[j] < 9) veg = true;
                else{
                    e[j] = 0;
                    j--;
                }
            }
            if(!veg){
                ne++;
                e[0] = 1;
                for(int k=ne;k>0;k--) e[k] = 0;
                i = 0;
            }else{
                e[j]++;
                i = 0;
            }
            }
        }
        e[ne] = i;
        kit(e,ne);
        cout<<endl;
        //usleep(100000);
    }
}

NagyEgesz NagyEgesz::szoroz(const NagyEgesz& n){
    int thisn = this->n;
    int nn = n.n;
    thisn--;
    nn--;

    if (((nn == 0) && (n.szamjegyek[0] == 0)) || ((thisn == 0) && (szamjegyek[0] == 0))){
        NagyEgesz erdm;
        return erdm;
    }

    int s[thisn*nn];
    int ns;
    s[0]=0;
    int e[thisn*nn];
    int ne = thisn;

    for(int i=0;i<=ne;i++) e[i] = this->szamjegyek[i]; //MASOL

    szorozegyel(e,ne,n.szamjegyek[0]); //ELSO SZORZAS

    int cs=0;
    for(int i=1;i<=nn;i++){ //MINDEN SZAMJEGY A SZORZOBOL
        ne++;
        cs++;
        e[ne] = 0;

        ns = thisn;
        for(int ii=0;ii<=ns;ii++) s[ii] = this->szamjegyek[ii]; //MASOL EREDETIT, HOGY BESZOROZZUK UJRA
        for (int p=cs;p>0;p--){                                  //TOL
            for(int j=ns;j>=0;j--) s[j+1] = s[j];
            ns++;
            s[0]=0;
        }

        szorozegyel(s,ns,n.szamjegyek[i]); //UJRA SZOROZ

        int m = 0;
        for(int j=ne;j>=0;j--){ //OSSZEAD
            e[j] += s[j] + m;
            m = e[j] / 10;
            if (m>10){

            }
            e[j] %= 10;
        }

        if(m){  //CSINAL HELYET MARADEKNAK
            for(int j=ne;j>=0;j--) e[j+1] = e[j];
            ne++;
            cs++;
            e[0] = m;
        }
    }

    NagyEgesz erdm( this->elojel * n.elojel, ne, e);
    return erdm;
}

NagyEgesz NagyEgesz::kivon(const NagyEgesz &b){
    int ej = 0;
    if (this->elojel == b.elojel){ //HA EGYFORMA AZ ELOJEL

        int ne = 0;
        int e[n+b.n];
        int s[n+b.n];

        if ( *this > b ){
            ej = 1 * elojel;
            ne = n;
            for(int i=0; i<=n; i++){
                e[i] = szamjegyek[i];
                s[i] = 0;
            }
            int j = b.n;
            while( j >= 0 ){
                s[ne-b.n+j] = b.szamjegyek[j];
                j--;
            }
        }
        else{
            ej = -1 * elojel;
            ne = b.n;
            for(int i=0; i<=ne; i++){
                e[i] = b.szamjegyek[i];
                s[i] = 0;
            }
            int j = n;
            while( j >= 0 ){
                s[ne-n+j] = szamjegyek[j];
                j--;
            }
        }

        for(int i = ne; i>=0; i--){
            if((e[i] - s[i]) >= 0) e[i] -= s[i];
            else{
                int j = i - 1;
                while(!e[j]) j--;
                e[j]--;
                for(int w=j+1;w<i;w++) e[w] = 9;
                e[i] = e[i] + 10 - s[i];
            }
        }

        while(!e[0] && ne>0){
            for(int i=0; i<ne; i++)
                e[i] = e[i+1];
            ne--;
        }
        if(!ne) ej = 1;

    NagyEgesz erdm(ej,ne+1,e);
    if( !(*this > b)) erdm.elojel = -1;
    return erdm;
    }
    else{
        NagyEgesz c(*this);
        NagyEgesz d(b);
        if( elojel == -1 ){
                d.elojel = -1;
                NagyEgesz erdm = c.osszead(d);
                return erdm;
        }
        if( b.elojel == -1 ){
                d.elojel = 1;
                NagyEgesz erdm = (d).osszead(c);
                return erdm;
        }
    }

}

NagyEgesz NagyEgesz::osszead(const NagyEgesz &b){

    if (this->elojel == b.elojel){ //HA EGYFORMA AZ ELOJEL

        int ne = 0;
        int e[n+b.n];
        int s[n+b.n];

        if (n >= b.n){
            ne = n;
            for(int i=0; i<=n; i++){
                e[i] = szamjegyek[i];
                s[i] = 0;
            }
            int j = b.n;
            while( j >= 0 ){ //(n-b.n-1)
                s[ne - b.n + j] = b.szamjegyek[j];
                j--;
            }
        }
        else{
            ne = b.n;
            for(int i=0; i<=ne; i++){
                e[i] = b.szamjegyek[i];
                s[i] = 0;
            }
            int j = n;
            while( j >= 0 ){
                s[ne-n+j] = szamjegyek[j];
                j--;
            }
        }

        int m = 0;
        for(int i = ne; i>=0; i--){
                e[i] = e[i] + s[i] + m;
                m = e[i] / 10;
                e[i] = e[i] % 10;
        }
        if(m){  //CSINAL HELYET MARADEKNAK
                for(int j=ne;j>=0;j--) e[j+1] = e[j];
                ne++;
                e[0] = m;
       }

    NagyEgesz erdm(elojel,ne+1,e);
    return erdm;
    }
    else{
        NagyEgesz c(b);
        NagyEgesz d(*this);
        if( elojel == -1 ){
                d.elojel = 1;
                NagyEgesz erdm = c.kivon(d);
                return erdm;
        }
        if( b.elojel == -1 ){
                c.elojel = 1;
                NagyEgesz erdm = (d).kivon(c);
                return erdm;
        }
    }
}

NagyEgesz NagyEgesz::oszt(const NagyEgesz& b){

    if (b.n == 0 && b.szamjegyek[0] == 0) throw NullavalValoOsztas();

    if (*this > b){

    NagyEgesz c(*this);
    NagyEgesz d(b);
    int e[c.n];
    int ne = 0;
    int i = 0;
     while(c >= d){
        i++;
        if (i > 9){
            if (ne == 0){
                ne++;
                e[ne-1] = 1;
                i = 0;
            }
            else{

            bool veg = false;
            int j = ne - 1;
            while (!veg && j >=0){
                if (e[j] < 9) veg = true;
                else{
                    j--;
                    e[j] = 0;
                }
            }
            if(!veg){
                ne++;
                e[0] = 1;
                for(int k=ne;k>0;k--) e[k] = 0;
                i = 0;
            }else{
                e[j]++;
                i = 0;
            }
            }
        }
        e[ne] = i;
        c = c.kivon(d);
     }
    NagyEgesz erdm(1,ne+1,e);
    return erdm;
    }
    else{
        NagyEgesz erdm;
        return erdm;
    }
}

void NagyEgesz::kiir()const{
    //cout<<"A szam: ";
    if (elojel<0) cout<<"- ";
    for(int i=0;i<=n;i++){
        cout<<szamjegyek[i]<<" ";
    }
}

int main(){
    int a[]={1,2,3,4};
    //int a[]={1,0,0,0};
    int b[]={1,2,1,6};
    NagyEgesz t(1,3,a);
    NagyEgesz l(-1,3,b);

    if (t>l){ t.kiir(); cout<<" > "; l.kiir(); }
    else{ t.kiir(); cout<<" < "; l.kiir(); }

    cout<<endl;

    t.kiir();
    cout<<" * ";
    l.kiir();
    cout<<" = ";
    NagyEgesz sz = t.szoroz(l);
    sz.kiir();

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

