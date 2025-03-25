#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;
class Mhs{
    private:
        string nim, nama;
        float ipk;

    public:
        void input();
        void cetak();
        string getNim();
        string getNama();
        float getIPK();
        void setIPK(float iipk);
};
void sortingIpkDesc(Mhs m[], int n);
void cetakSemuaMhs(Mhs m[], int n);
bool searchNim(string k, int n, Mhs m[]);
float cariIPKdariNama(string k, int n, Mhs m[]);
void analisaMhs(Mhs m[], int n);

#endif // HEADER_H_INCLUDED
