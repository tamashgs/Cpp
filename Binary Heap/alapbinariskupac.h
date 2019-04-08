class AlapBinKupac{
    int *a;
    int n;
    int kupac_meret;
public:
    AlapBinKupac();
    AlapBinKupac(const BinKupac & );
    AlapBinKupac(elem*, int, int );
    ~AlapBinKupac();
    void Maximum_Kupacol(int);
    void Kupacot_Epit();
    void Kupacrendezes();
    void Minimum_Kupacol(int);
    void Min_Kupacot_Epit();
    void Min_Kupacrendezes();
    void ki();
};

AlapBinKupac::AlapBinKupac(int t[], int db, int m){
    if ( db > m ) throw "Ennyi elem nem fer bele a kupacba!";
    n = db;
    kupac_meret = m;
    a = new int[kupac_meret + 1];
    for(int i=0; i<n; i++){
        a[i + 1] = t[i];
    }
}

AlapBinKupac::AlapBinKupac(const BinKupac & k){
    n = k.n;
    kupac_meret = k.kupac_meret;
    a = new int[kupac_meret];
    for(int i=0; i<n; i++){
        a[i] = k.a[i];
    }
}

AlapBinKupac::AlapBinKupac(){
    n = 0;
    kupac_meret = 0;
    a = new int[0];
}

AlapBinKupac::~AlapBinKupac(){
    delete []a;
}

void AlapBinKupac::Minimum_Kupacol(int i){

    int b = 2*i;
    int j = 2*i + 1;
    int ma;
    if ( (b <= kupac_meret) && (a[b] < a[i]) ) ma = b;
    else ma = i;
    if ( (j <= kupac_meret) && (a[j] < a[ma]) ) ma = j;
    if ( ma != i){
        int seged = a[i];
        a[i] = a[ma];
        a[ma] = seged;
        Minimum_Kupacol(ma);
    }
}

void AlapBinKupac::Min_Kupacot_Epit(){

    kupac_meret = n;
    for(int i = n/2; i>=1; i--){
        Minimum_Kupacol(i);
    }
}

void AlapBinKupac::Min_Kupacrendezes(){

    for(int i = n; i>=2; i--){
        int seged = a[1];
        a[1] = a[i];
        a[i] = seged;
        kupac_meret--;
        Minimum_Kupacol(1);
    }
}

void AlapBinKupac::Maximum_Kupacol(int i){

    int b = 2*i;
    int j = 2*i + 1;
    int ma;
    if ( (b <= kupac_meret) && (a[b]> a[i]) ) ma = b;
    else ma = i;
    if ( (j <= kupac_meret) && (a[j] > a[ma]) ) ma = j;
    if ( ma != i){
        int seged = a[i];
        a[i] = a[ma];
        a[ma] = seged;
        Maximum_Kupacol(ma);
    }
}

void BinKupac::Maximum_Kupacol(int i){

    int b = 2*i;
    int j = 2*i + 1;
    int ma;
    if ( (b <= kupac_meret) && (a[b] > a[i]) ) ma = b;
    else ma = i;
    if ( (j <= kupac_meret) && (a[j] > a[ma]) ) ma = j;
    if ( ma != i){
        int seged = a[i];
        a[i] = a[ma];
        a[ma] = seged;
        Maximum_Kupacol(ma);
    }
}

void AlapBinKupac::Kupacot_Epit(){

    kupac_meret = n;
    for(int i = n/2; i>=1; i--){
        Maximum_Kupacol(i);
    }
}

void AlapBinKupac::Kupacrendezes(){

void ki(){
    for(int i=1;i<n;i++){
        cout<<a[i]<<" ";
    }
}

    for(int i = n; i>=2; i--){
        int seged = a[1];
        a[1] = a[i];
        a[i] = seged;
        kupac_meret--;
        Maximum_Kupacol(1);
    }
}
