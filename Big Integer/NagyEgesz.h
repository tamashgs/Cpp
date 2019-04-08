#ifndef NAGYEGESZ_H_INCLUDED
#define NAGYEGESZ_H_INCLUDED

class NagyEgesz{
    int* szamjegyek;
    int n;
    int elojel;
public:
    NagyEgesz();
    NagyEgesz(int elojel, int n, const int* szamjegyek);
    NagyEgesz(const NagyEgesz&);
    ~NagyEgesz();
    NagyEgesz osszead(const NagyEgesz&);
    NagyEgesz kivon(const NagyEgesz&);
    NagyEgesz szoroz(const NagyEgesz&);
    NagyEgesz oszt(const NagyEgesz&);
    bool operator > (const NagyEgesz&);
    bool operator >= (const NagyEgesz&);
    class NullavalValoOsztas{};
    bool nulla();
    void kiir() const;
};

#endif // NAGYEGESZ_H_INCLUDED
