/*Név: Hegyesi Lóránt-Tamás
Azonosító: hlim1722
Csoport:512
Feladat: Változótiszta
∧1. $ = ∃
 2. # = ∀
 3. ∧ = és
 4. ∨ = vagy
 5. > = implikació
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("input.dat");
ofstream g("output.dat");

char karakter(bool kar[]){  //viszaterit egy karaktert amire atnevezhetjuk
    for(int i=0;i<26;i++)
        if (kar[i]){return i+'a';}
    return -1;
}

void torol(bool kar[],string s){ //kar-bol torlom a letezo karaktereket
    for(int i=0;s[i]!=0;i++){
        if (s[i]>='A'&& s[i]<='Z'){kar[s[i]-'A']=false;} //kar-bol torlom a letezo karaktereket
        if (s[i]>='a'&& s[i]<='z'){kar[s[i]-'a']=false;}
    }
    return;
}

void atnevez(bool kar[],string &s){ //atnevez parametert
    int i=0;
    while(s[i]!=0){
        if (s[i]=='$' || s[i]=='#'){
            int j=i+1;
            char seg=s[j];
            char ujkar=karakter(kar);
            kar[ujkar-'a']=false;
            s[j]=ujkar;
            int z=0;
            bool k=true;
            while((z!=0 || k) && s[j]!=0){
                j++;
                if (seg==s[j]){
                    s[j]=ujkar;
                    k=false;
                }
                if (s[j]=='(') z++;
                if (s[j]==')') z--;
            }
        }
        i++;


    }


}

bool valtozotiszta(string s){ //visszateriti hogy valtozotiszta e vagy nem
    int i=0;
    bool tiszta=true;
    char seg;
    while(s[i]!=0 && tiszta){
        if (s[i]=='$' || s[i]=='#'){
            int j=i+1;
            seg=s[j];
            char ujkar='*';
            s[j]=ujkar;
            int z=0;
            bool k=true;
            while((z!=0 || k) && s[j]!=0){
                j++;
                if (seg==s[j]){
                    s[j]=ujkar;
                    k=false;
                }
                if (s[j]=='(') z++;
                if (s[j]==')') z--;
            }
        }
        //cout<<endl<<s;
        //cout<<"seg:"<<seg;
        int j=0;
        while(s[j]!=0 && tiszta){
            if (s[j]==seg){tiszta=false;}
            j++;
        }


            /*while((s[j]!='>' && s[j]!='^' && s[j]!='|' && s[j]!=0) || (z!=0 || z1)){
                    if (s[j]=='(') {z1=false; z++;}
                    if (s[j]==')') z--;
                    j++;
            }
            while(tiszta && s[j]!=0){
                j++;
                if (seg==s[j]){tiszta=false;}
            }
            j=i-2;
            z=0;
            z1=true;
            while((s[j]!='>' && s[j]!='^' && s[j]!='|' && j>0) || (z!=0 || z1)){
                    if (s[j]==')') {z1=false; z++;}
                    if (s[j]=='(') z--;
                    j--;
            }
            while(tiszta && j>0){
                j--;
                if (seg==s[j]){tiszta=false;}
            }
        }*/
        i++;
    }
    return tiszta;

}

void valt(string &s){ //atnevezzuk ha nem valtozotiszta
    bool kar[26];
    for(int i=0;i<26;i++)kar[i]=true;

    torol(kar,s);

    if (valtozotiszta(s)) g<<"Valtozotiszta!";
        else{
            atnevez(kar,s);
            if (valtozotiszta(s)) g<<"Valtozotiszta alakra hozva: ";
        }
}

void par(string s){ //kiirja a kifejezes parametereit
    bool param[26];
    int i;
    for(i=0;i<26;i++)param[i]=true;
    i=0;
    while(s[i]!=0){
        if(s[i]=='('){
            int j=i+1;
            bool jo=true;
            int vz=0;
            while(jo && vz==0){
                if (s[j]==')') vz=j;
                if ( (s[j]>='a'&& s[j]<='z') || s[j]==',' || s[j]==')' )j++;
                    else jo=false;
            }

            if (jo){
                for(int k=i+1;k<vz;k++){
                    if (s[k]!=',') param[s[k]-'a']=false;
                }
            }
        }
    i++;
    }
    i=0;
    while(s[i]!=0){
        if (s[i]=='$' || s[i]=='#')(param[s[i+1]-'a'])=true;
       i++;
    }

    g<<"Formula parameterei: ";
    for(i=0;i<26;i++)
        if (!param[i]){char l=i+'a';g<<l<<" ";}
    g<<"   ";
}

int main(){

    int db=0;
    while (!f.eof()){
    db++;
    g<<db<<". ";
    string s;
    getline(f,s);
    valt(s); //valtozotisztasag vizsgalata
    g<<s<<endl;
    par(s); //parameterek kiirasa
    g<<endl;
    g<<endl;
    cout<<s<<endl;

    }
}
