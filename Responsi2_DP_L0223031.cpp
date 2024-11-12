#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Barang {
    string nama;
    int harga_jual;
    int harga_beli;
    int stock;
};

void satu_barang(const Barang &barang) {
    cout << "Nama Barang: " << barang.nama << endl;
    cout << "Harga Beli: " << barang.harga_beli << endl;
    cout << "Harga Jual: " << barang.harga_jual << endl;
    cout << "Stok Barang: " << barang.stock << endl;
}

int main() {
    vector<Barang> daftar_barang;
    bool ditemukan = false;

    while (true) {
        cout << "=========== WARUNG BU YATI ===========" << endl;
        cout << "Pilihan menu berikut: " << endl;
        cout << "1. Tambahkan barang" << endl;
        cout << "2. Tampilkan barang yang tersedia" << endl;
        cout << "3. Tampilkan satu barang" << endl;
        cout << "4. Ganti rincian barang" << endl;
        cout << "5. Hapus barang" << endl;
        cout << "6. Jual barang" << endl;
        cout << "7. Keluar" << endl;
        cout << "______________________________________" << endl;

        int perintah;
        cout << "Masukkan nomer yang akan dipilih: " << endl;
        cin >> perintah;

        switch(perintah) {
            case 1:
            Barang barang_baru;
            cout << "Nama Barang: ";
            cin >> barang_baru.nama;
            cout << "Harga Beli: ";
            cin >> barang_baru.harga_beli;
            cout << "Harga Jual: ";
            cin >> barang_baru.harga_jual;
            cout << "Stok Barang: ";
            cin >> barang_baru.stock;
            daftar_barang.push_back(barang_baru);
            cout << "Barang berhasil ditambahkan!" << endl;
            break;

            case 2:
            cout << "Daftar barang-barang: " << endl;
            for (const auto &barang : daftar_barang) {
                cout << "-" << barang.nama << endl;
            }
            break;

            case 3:
            cout << "Nama barang yang ingin ditampilkan: ";
            string nama_barang_tampil;
            cin >> nama_barang_tampil;
            ditemukan = false;
            for (const auto &barang : daftar_barang) {
                if (barang.nama == nama_barang_tampil) {
                    satu_barang(barang);
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Barang tidak ditemukan!" << endl;
            }
            break;

            case 4:
            cout << "Nama Barang: ";
            string nama_barang_ganti;
            cin >> nama_barang_ganti;
            for (auto &barang : daftar_barang) {
                if (barang.nama == nama_barang_ganti) {
                    cout << "Harga Beli Baru: ";
                    cin >> barang.harga_beli;
                    cout << "Harga Jual Baru: ";
                    cin >> barang.harga_jual;
                    cout << "Tambah Stok: ";
                    int tambah_stock;
                    cin >> tambah_stock;
                    barang.stock += tambah_stock;
                    cout << "Perubahan berhasil!" << endl;
                }
            }
            break;

            case 5:
            cout << "Nama Barang: ";
            string nama_barang_dihapus;
            cin >> nama_barang_dihapus;
            for (auto it = daftar_barang.begin(); it != daftar_barang.end(); ++it) {
                if (it->nama == nama_barang_dihapus) {
                    daftar_barang.erase(it);
                    cout << "Barang berhasil dihapus!" << endl;
                }
            }
            break;

            case 6:
            cout << "Nama Barang: ";
            string nama_barang_dijual;
            cin >> nama_barang_dijual;
            for (auto &barang : daftar_barang) {
                if (barang.nama == nama_barang_dijual) {
                    if (barang.stock > 0) {
                        barang.stock--;
                        cout << "Barang terjual!" << endl;
                    } else {
                        cout << "Stock barang habis!" << endl;
                    }
                }
            }
            break;

            case 7:
            cout << "Program selesai!" << endl;
            return 0;
            
            default:
            cout << "Perintah tidak valid!" << endl;
            break;
        }
    }
    return 0;
}