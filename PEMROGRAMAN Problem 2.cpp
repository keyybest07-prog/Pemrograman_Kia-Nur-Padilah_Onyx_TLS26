#include <iostream>

using namespace std;

// Fungsi buatan sendiri untuk menghitung panjang string
int hitungPanjangString(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi buatan sendiri untuk mengubah huruf kecil ke kapital
char keKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int main() {
    char pesan[500];
    cout << "Masukkan pesan rahasia (huruf saja): ";
    cin >> pesan;

    int panjang = hitungPanjangString(pesan);
    char pesanSandi[500];

    int nilaiGeserSebelumnya = 0;

    for (int i = 0; i < panjang; i++) {
        char c = keKapital(pesan[i]);

        if (c >= 'A' && c <= 'Z') {
            // Urutan huruf asli (A=1, B=2, ..., Z=26)
            int nilaiAsli = c - 'A' + 1;

            // Geser nilai huruf
            int nilaiBaru = nilaiAsli + nilaiGeserSebelumnya;

            // Jika melebihi 26, putar balik ke A (wrap around)
            while (nilaiBaru > 26) {
                nilaiBaru -= 26;
            }

            // Kembalikan ke karakter ASCII
            pesanSandi[i] = (char)('A' + nilaiBaru - 1);

            // Simpan nilai huruf asli sebagai pergeseran huruf berikutnya
            nilaiGeserSebelumnya = nilaiAsli;
        } else {
            pesanSandi[i] = c;
        }
    }
    pesanSandi[panjang] = '\0';

    cout << "Pesan Ter-sandi: " << pesanSandi << endl;

    return 0;
}