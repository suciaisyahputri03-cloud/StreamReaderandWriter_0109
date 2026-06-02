#include <iostream>
#include <array>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class TokoElektronik
{
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik()
    {
        etalase[0] = "Laptop";
        etalase[1] = "Smartphone";
        etalase[2] = "Printer";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&)
        {
            throw string("Gagal Mengambil Barang : Rak nomor " +
                         to_string(nomorRak) +
                         " kosong atau tidak tersedia!");
        }
    }
};

// ================= CRUD FILE =================

void tampilkanBarang()
{
    ifstream file("gudang.txt");

    cout << "\n===== DAFTAR BARANG DI GUDANG =====\n";

    string data;
    int nomor = 1;

    while (getline(file, data))
    {
        cout << nomor++ << ". " << data << endl;
    }

    if (nomor == 1)
    {
        cout << "Gudang masih kosong.\n";
    }

    file.close();
}

void tambahBarang()
{
    ofstream file("gudang.txt", ios::app);

    string barang;

    cin.ignore();
    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}

void updateBarang()
{
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang))
    {
        data.push_back(barang);
    }

    file.close();

    if (data.empty())
    {
        cout << "Tidak ada data untuk diupdate.\n";
        return;
    }

    tampilkanBarang();

    int index;

    cout << "Pilih nomor barang yang ingin diupdate: ";
    cin >> index;

    if (index < 1 || index > data.size())
    {
        cout << "Nomor tidak valid.\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan data baru: ";
    getline(cin, barang);

    data[index - 1] = barang;

    ofstream out("gudang.txt");

    for (string item : data)
    {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil diupdate.\n";
}

void hapusBarang()
{
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang))
    {
        data.push_back(barang);
    }

    file.close();

    if (data.empty())
    {
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }

    tampilkanBarang();

    int index;

    cout << "Pilih nomor barang yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > data.size())
    {
        cout << "Nomor tidak valid.\n";
        return;
    }

    data.erase(data.begin() + (index - 1));

    ofstream out("gudang.txt");

    for (string item : data)
    {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil dihapus.\n";
}

// ================= SIMULASI ETALASE =================

void simulasiEtalase()
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    try
    {
        cout << "\nSkenario 1 (Rak indeks 1)\n";
        cout << "Barang berhasil diambil: "
             << toko.ambilProduk(1) << endl;
    }
    catch (string pesan)
    {
        cout << pesan << endl;
    }

    // Skenario 2
    try
    {
        cout << "\nSkenario 2 (Rak indeks 5)\n";
        cout << "Barang berhasil diambil: "
             << toko.ambilProduk(5) << endl;
    }
    catch (string pesan)
    {
        cout << pesan << endl;
    }
}

// ================= MAIN =================

int main()
{
    int pilihan;

    do
    {
        cout << "\n====================================";
        cout << "\n SISTEM MANAJEMEN TOKO GIBRAN JAYA";
        cout << "\n====================================\n";

        tampilkanBarang();

        cout << "\nMenu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Update Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Simulasi Etalase\n";
        cout << "0. Keluar\n";

        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBarang();
            break;

        case 2:
            updateBarang();
            break;

        case 3:
            hapusBarang();
            break;

        case 4:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}