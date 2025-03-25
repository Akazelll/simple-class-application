#include "header.h"
int main()
{
    Mhs mm[40];
    int jml_mhs;

    cout << "Masukkan Jumlah Mahasiswa : "; cin >> jml_mhs;

    for (int i = 0; i < jml_mhs; i++){
        cout << "Mahasiswa ke-"<< i+1 << endl;
        mm[i].input();
    }
    cout << "+------+----------------+-----------------------+---------------+\n";
    cout << "|  No  |\tNIM\t|\tNama\t\t|\tIPK\t|\n";
    cout << "+------+----------------+-----------------------+---------------+\n";

    for (int i = 0; i < jml_mhs; i++) {
        cout << "|  " << i+1 << "   |\t"
        << mm[i].getNim() << "\t|\t"
        << mm[i].getNama() << "\t\t|\t"
        << mm[i].getIPK() << "\t|\n";
    }

    cout << "+------+----------------+-----------------------+---------------+\n";

    sortingIpkDesc(mm, jml_mhs);
    cout << "Urutan Setelah sorting IPK Desc" << endl;
    cout << "+------+----------------+-----------------------+---------------+\n";
    cout << "|  No  |\tNIM\t|\tNama\t\t|\tIPK\t|\n";
    cout << "+------+----------------+-----------------------+---------------+\n";
    for (int i = 0; i < jml_mhs; i++) {
        cout << "|  " << i+1 << "   |\t"
        << mm[i].getNim() << "\t|\t"
        << mm[i].getNama() << "\t\t|\t"
        << mm[i].getIPK() << "\t|\n";
    }
    cout << "+------+----------------+-----------------------+---------------+\n";

    int pil, urutan;
    float ipk_baru;
    char lanjut;
    string cari_nim, hasilcari_nim, nama_mhs;
    do{
        cout << "Pilihan : \n1. Update IPK berdasarkan urutan \n"<<"2. Cari Mahasiswa berdasarkan IPK \n"<<
        "3. Cari IPK Mahasiswa Berdasarkan Nama \n"<<"4. Analisa \nMasukkan Pilihan : "; cin >> pil;
        if (pil == 1) {
            do {
                cout << "Masukkan Urutan (1 - " << jml_mhs << "): ";
                cin >> urutan;

                if (urutan < 1 || urutan > jml_mhs) {
                    cout << "Urutan tidak valid! Silakan coba lagi.\n";
                }
            } while (urutan < 1 || urutan > jml_mhs);
            urutan--;
            do {
                cout << "Masukkan IPK baru antara 0 - 4: ";
                cin >> ipk_baru;

                if (ipk_baru < 0 || ipk_baru > 4) {
                    cout << "IPK harus antara 0 dan 4! Silakan coba lagi.\n";
                }
            } while (ipk_baru < 0 || ipk_baru > 4);
            mm[urutan].setIPK(ipk_baru);
            cetakSemuaMhs(mm, jml_mhs);
        }
        else if(pil == 2){
            cout << "Masukkan NIM Mahasiswa yang Dicari : "; cin >> cari_nim;
            hasilcari_nim = (searchNim(cari_nim, jml_mhs, mm)==1)? " Ada":" Tidak Ada";
            cout << "Mahasiswa NIM : " << cari_nim << " "<< hasilcari_nim << endl;
        }
        else if (pil == 3){
            cout << "Masukkan Nama Mahasiswa yang Ingin Dicari : " ; cin >> nama_mhs;
            cout << "IPK " << nama_mhs << " = " << cariIPKdariNama(nama_mhs, jml_mhs, mm) << endl;
        }
        else if (pil == 4){
            analisaMhs(mm, jml_mhs);
        }
        else{
            cout << "Input Salah";
        }
        cout << "Apakah ingin melanjutkan ? (y/n) : " ; cin >> lanjut;
    }while(lanjut =='y');

    return 0;
}
