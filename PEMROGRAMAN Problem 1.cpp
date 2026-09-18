#include <iostream>

using namespace std;

// Fungsi buatan sendiri untuk mengecek apakah astronot masih aktif
bool isAktif(const bool status[], int idx) {
    return status[idx];
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    if (N <= 0 || K < 2) {
        cout << "Input tidak valid! Minimal 1 astronot dan K >= 2." << endl;
        return 0;
    }

    // Array indikator astronot (index 1 sampai N)
    // Gunakan array statis ukuran maksimum
    bool aktif[1001];
    for (int i = 1; i <= N; i++) {
        aktif[i] = true;
    }

    int sisa = N;
    int indeksSekarang = 1;

    cout << "\n--- Urutan Eliminasi Astronot ---" << endl;

    while (sisa > 1) {
        int hitungan = 0;

        // Cari astronot ke-K yang masih tersisa
        while (hitungan < K) {
            if (aktif[indeksSekarang]) {
                hitungan++;
            }
            if (hitungan < K) {
                indeksSekarang = (indeksSekarang % N) + 1;
            }
        }

        // Eliminasi astronot
        aktif[indeksSekarang] = false;
        int tereliminasi = indeksSekarang;
        cout << "Astronot " << tereliminasi << " dieliminasi (K awal = " << K << ")" << endl;

        // Aturan perubahan nilai K
        if (tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        // Batas minimal K adalah 2
        if (K < 2) {
            K = 2;
        }

        // Pindahkan indeks ke astronot aktif berikutnya
        do {
            indeksSekarang = (indeksSekarang % N) + 1;
        } while (!aktif[indeksSekarang]);

        sisa--;
    }

    // Cari astronot terakhir
    for (int i = 1; i <= N; i++) {
        if (aktif[i]) {
            cout << "\nAstronot terakhir yang bertahan: " << i << endl;
            break;
        }
    }

    return 0;
}
