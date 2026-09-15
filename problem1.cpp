#include <iostream>

using namespace std;

int main() {
    // Variabel N menyimpan jumlah astronaut, sedangkan K menyimpan nilai hitungan.
    int N, K;

    // Meminta input dari pengguna.
    cout << "Masukkan jumlah astronaut (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // Memastikan input valid dan jumlah astronaut tidak melebihi ukuran array.
    if (!cin || N <= 0 || N > 1000) {
        cout << "Jumlah astronaut harus berada di antara 1 dan 1000." << endl;
        return 1;
    }

    // Sesuai aturan, nilai K tidak boleh kurang dari 2.
    if (K < 2) {
        K = 2;
    }

    // Array untuk menyimpan nomor astronaut.
    // Nilai 0 digunakan sebagai tanda bahwa astronaut sudah dieliminasi.
    int astronauts[1000];

    // Mengisi array dengan nomor astronaut dari 1 sampai N.
    for (int i = 0; i < N; i++) {
        astronauts[i] = i + 1;
    }

    // remaining adalah jumlah astronaut yang belum dieliminasi.
    // idx menunjukkan posisi astronaut yang sedang dihitung.
    int remaining = N;
    int idx = 0;

    cout << "\n--- Urutan Eliminasi ---\n";

    // Proses eliminasi dilakukan sampai hanya tersisa satu astronaut.
    while (remaining > 1) {
        int counted = 0;

        // Menghitung astronaut yang masih berada di dalam lingkaran sampai hitungan K.
        while (counted < K) {
            // Astronaut dengan nilai 0 sudah dieliminasi sehingga dilewati.
            if (astronauts[idx] != 0) {
                counted++;
            }

            // Berpindah ke posisi berikutnya secara melingkar.
            if (counted < K) {
                idx = (idx + 1) % N;
            }
        }

        // Astronaut pada posisi idx adalah astronaut yang akan dieliminasi.
        int eliminated = astronauts[idx];
        cout << "Astronaut " << eliminated
             << " dieliminasi (K saat ini: " << K << ")" << endl;

        // Menandai astronaut sebagai sudah dieliminasi.
        astronauts[idx] = 0;
        remaining--;

        // Jika nomor astronaut genap, K bertambah 2.
        // Jika nomor astronaut ganjil, K berkurang 1.
        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K--;
        }

        // Nilai K tidak boleh kurang dari 2.
        if (K < 2) {
            K = 2;
        }

        // Perhitungan berikutnya dimulai dari posisi setelah astronaut yang dieliminasi.
        idx = (idx + 1) % N;

        // Melewati semua posisi yang astronautnya sudah dieliminasi.
        while (astronauts[idx] == 0) {
            idx = (idx + 1) % N;
        }
    }

    // Mencari satu-satunya astronaut yang masih tersisa.
    int survivor = 0;
    for (int i = 0; i < N; i++) {
        if (astronauts[i] != 0) {
            survivor = astronauts[i];
            break;
        }
    }

    // Menampilkan astronaut terakhir yang bertahan.
    cout << "\n========================================\n";
    cout << "Astronaut terakhir yang bertahan adalah: " << survivor << endl;
    cout << "========================================\n";

    return 0;
}
