#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> kelimeListesi;

void ekranTemizle() {
    system("cls");
}

void kelimeListesiniYukle(const char* dosyaAdi) {
    ifstream dosya(dosyaAdi);

    if (!dosya) {
        cerr << "Hata: Kelime listesi dosyasi acilamadi." << endl;
        exit(1);
    }

    string kelime;
    while (dosya >> kelime) {
        kelimeListesi.push_back(kelime);
    }

    dosya.close();
}

pair<string, string> rasgeleKelimelerSec() {
    int index1 = rand() % kelimeListesi.size();
    int index2 = rand() % kelimeListesi.size();

    while (index2 == index1) {
        index2 = rand() % kelimeListesi.size();
    }

    string kelime1 = kelimeListesi[index1];
    string kelime2 = kelimeListesi[index2];

    return make_pair(kelime1, kelime2);
}

int main() {
    srand(time(0));

    kelimeListesiniYukle("data.txt");

    int skor = 0;
    int soruNumarasi = 1;

    while (true) {
        ekranTemizle();

        pair<string, string> rasgeleKelimeler = rasgeleKelimelerSec();
        string kelime1 = rasgeleKelimeler.first;
        string kelime2 = rasgeleKelimeler.second;

        cout << "Skorun: " << skor << endl << endl;
        
        cout << "Soru " << soruNumarasi << endl;
        cout << "Kelime 1: " << kelime1 << endl;
        cout << "Kelime 2: " << kelime2 << endl << endl;

        string secim;
        cout << "Alfabetik olarak once gelen kelimeyi secin\n(1 veya 2), Cikis icin 0 gir: ";
        cin >> secim;

        if (secim == "0") {
            break;
        } else if (secim == "1" && kelime1 < kelime2) {
            skor++;
        } else if (secim == "2" && kelime2 < kelime1) {
            skor++;
        }

        soruNumarasi++;
    }

    cout << "Oyun bitti! Toplam skorun: " << skor << endl;

    return 0;
}

