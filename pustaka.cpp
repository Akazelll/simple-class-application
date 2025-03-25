#include "header.h"

void Mhs::input(){
    cout <<"Masukkan NIM : "; cin >> nim;
    cout <<"Masukkan Nama : "; cin >> nama;
    cout << "Masukkan IPK : "; cin >> ipk;
}
void Mhs::cetak(){
    cout <<"NIM : "<< nim << endl;
    cout <<"Nama : " << nama << endl;
    cout << "IPK : "<< ipk << endl;
}

string Mhs::getNim(){
    return nim;
}

string Mhs::getNama(){
    return nama;
}

float Mhs::getIPK(){
    return ipk;
}

void Mhs::setIPK(float iipk){
    ipk = iipk;
}

void sortingIpkDesc (Mhs m[], int n){
    int i, j;
    Mhs temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (m[j].getIPK() < m[j + 1].getIPK()) {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}void cetakSemuaMhs(Mhs m[], int n){
    cout << "Update Tabel Terbaru!!!" << endl;
    cout << "+------+----------------+-----------------------+---------------+\n";
    cout << "|  No  |\tNIM\t|\tNama\t\t|\tIPK\t|\n";
    cout << "+------+----------------+-----------------------+---------------+\n";

    for (int i = 0; i < n; i++) {
        cout << "|  " << i+1 << "   |\t"
        << m[i].getNim() << "\t|\t"
        << m[i].getNama() << "\t\t|\t"
        << m[i].getIPK() << "\t|\n";
    }

    cout << "+------+----------------+-----------------------+---------------+\n";
}
bool searchNim(string k, int n, Mhs m[]){
    bool found = false;
    for (int i = 0; i <n; i++){
        if(m[i].getNim()==k){
            found = true;
            break;
        }
    }
    return found;
}

float cariIPKdariNama(string k, int n, Mhs m[]){
    float ipk_dicari;
    for (int i = 0; i<n; i++){
        if(m[i].getNama()==k){
            ipk_dicari = m[i].getIPK();
            break;
        }
    }
    return ipk_dicari;
}

void analisaMhs(Mhs m[], int n){
    float nMax = 0, nMin = 100, jml = 0, nRata;
    int iMax, iMin;

    for (int i = 0; i<n; i++){
        jml += m[i].getIPK();
        if(m[i].getIPK()> nMax){
            nMax = m[i].getIPK();
            iMax = i;
        }
        if(m[i].getIPK()< nMin){
            nMin = m[i].getIPK();
            iMin = i;
        }
    }
    cout << "Analisa Berdasarkan IPK" << endl;
    cout << "IPK Tertinggi : " << nMax << " Diperoleh Mahasiswa : " << m[iMax].getNama() << endl;
    cout << "IPK Terendah : " << nMin << " Diperoleh Mahasiswa : " << m[iMin].getNama() << endl;
    nRata = jml/n;
    cout << "Rata-Rata IPK : " << nRata << endl;
}
