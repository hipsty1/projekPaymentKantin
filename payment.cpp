#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct History
{
    string username;
    string type;
    int amount;
};

void profil(const string &username);
void topup(const string &username, int &saldo);
void buy(const string &username, int &saldo);
void perhitunganHarga(const string &username, int &saldo, int indexMenu, int jumlahBeli);

void signup()
{
    string username, password, line;
    int attempts = 0;
    bool success = false;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGN UP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    while (attempts < 3 && !success)
    {
        cout << "Masukkan username: ";
        cin >> username;

        // Cek apakah username sudah dipakai
        bool username_taken = false;
        ifstream infile("akun.txt");
        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                size_t pos = line.find(',');
                string file_user = line.substr(0, pos);
                if (username == file_user)
                {
                    username_taken = true;
                    break;
                }
            }
            infile.close();
        }

        if (username_taken)
        {
            attempts++;
            cout << "Username sudah dipakai! Percobaan ke-" << attempts << " dari 3." << endl
                 << endl;
            if (attempts == 3)
            {
                cout << "Gagal membuat akun setelah 3 kali percobaan." << endl;
                return;
            }
        }
        else
        {
            cout << "Masukkan password: ";
            cin >> password;

            ofstream file("akun.txt", ios::app);
            if (file.is_open())
            {
                file << username << "," << password << ",0" << endl;
                file.close();
                cout << "Akun berhasil dibuat!" << endl;
                success = true;
            }
            else
            {
                cout << "Gagal membuka file akun.txt!" << endl;
                return;
            }
        }
    }
}

void signin()
{
    string username, password, line;
    int attempts = 0;
    bool success = false;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGN IN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    while (attempts < 3 && !success)
    {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        ifstream file("akun.txt");
        if (file.is_open())
        {
            while (getline(file, line))
            {
                size_t pos1 = line.find(',');
                size_t pos2 = line.rfind(',');
                string file_user = line.substr(0, pos1);
                string file_pass = line.substr(pos1 + 1, pos2 - pos1 - 1);

                if (username == file_user && password == file_pass)
                {
                    success = true;
                    break;
                }
            }
            file.close();
        }
        else
        {
            cout << "Gagal membuka file akun.txt!" << endl;
            return;
        }

        if (!success)
        {
            attempts++;
            cout << "Username atau password salah! Percobaan ke-" << attempts << " dari 3." << endl;
        }
    }

    if (success)
    {
        profil(username);
    }
    else
    {
        cout << "Gagal masuk 3 kali. Keluar dari program." << endl;
        exit(0);
    }
}

void profil(const string &username)
{
    string line, file_user, saldo_str;
    int saldo = 0;
    bool found = false;

    ifstream file("akun.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');
            file_user = line.substr(0, pos1);
            if (file_user == username)
            {
                saldo_str = line.substr(pos2 + 1);
                saldo = stoi(saldo_str);
                found = true;
                break;
            }
        }
        file.close();
    }

    if (!found)
    {
        cout << "User tidak ditemukan!" << endl;
        return;
    }

    int pilihan;
    do
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(17) << " " << "PROFILE" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Username: " << username << endl;
        cout << "Saldo   : " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "1. Top Up" << endl;
        cout << "2. Buy" << endl;
        cout << "3. History" << endl;
        cout << "4. Log Out" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            topup(username, saldo);
            break;
        case 2:
            buy(username, saldo);
            break;
            break;
        case 3:
            cout << "Menu History (belum diimplementasi)" << endl;
            break;
        case 4:
            cout << "Log Out..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 4);
}

void topup(const string &username, int &saldo)
{
    int pilihan, jumlah = 0;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "TOP UP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. 10.000" << endl;
    cout << "2. 20.000" << endl;
    cout << "3. 50.000" << endl;
    cout << "4. 100.000" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih nominal: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        jumlah = 10000;
        break;
    case 2:
        jumlah = 20000;
        break;
    case 3:
        jumlah = 50000;
        break;
    case 4:
        jumlah = 100000;
        break;
    default:
        cout << "Pilihan tidak valid!" << endl;
        return;
    }

    string passwordKonfirmasi;
    cout << "Masukkan password untuk konfirmasi: ";
    cin >> passwordKonfirmasi;

    string baris, userFile, passFile, saldoFile;
    bool passwordBenar = false;

    ifstream file("akun.txt");
    if (file.is_open())
    {
        while (getline(file, baris))
        {
            size_t posisi1 = baris.find(',');
            size_t posisi2 = baris.rfind(',');
            userFile = baris.substr(0, posisi1);
            passFile = baris.substr(posisi1 + 1, posisi2 - posisi1 - 1);

            if (userFile == username && passwordKonfirmasi == passFile)
            {
                passwordBenar = true;
                saldoFile = baris.substr(posisi2 + 1);
                saldo = stoi(saldoFile);
                break;
            }
        }
        file.close();
    }

    if (!passwordBenar)
    {
        cout << "Password salah! Top up dibatalkan." << endl;
        return;
    }

    ifstream infile("akun.txt");
    ofstream outfile("akun_temp.txt");
    bool berhasilUpdate = false;
    while (getline(infile, baris))
    {
        size_t posisi1 = baris.find(',');
        size_t posisi2 = baris.rfind(',');
        string namaUser = baris.substr(0, posisi1);

        if (namaUser == username)
        {
            int saldoLama = stoi(baris.substr(posisi2 + 1));
            int saldoBaru = saldoLama + jumlah;
            outfile << username << "," << baris.substr(posisi1 + 1, posisi2 - posisi1 - 1) << "," << saldoBaru << endl;
            saldo = saldoBaru;
            berhasilUpdate = true;
        }
        else
        {
            outfile << baris << endl;
        }
    }
    infile.close();
    outfile.close();
    remove("akun.txt");
    rename("akun_temp.txt", "akun.txt");

    if (berhasilUpdate)
    {
        cout << "Top up berhasil!" << endl;
        cout << "Username: " << username << endl;
        cout << "Saldo sekarang: " << saldo << endl;

        ofstream histfile("dataAccount.txt", ios::app);
        if (histfile.is_open())
        {
            histfile << username << ",top up," << jumlah << endl;
            histfile.close();
        }
    }
    else
    {
        cout << "Gagal update saldo!" << endl;
    }
}

// Fungsi untuk menampilkan semua history user
void tampilkanHistory(const string &username)
{
    ifstream fileHist("dataAccount.txt");
    string baris;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "HISTORY" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    while (getline(fileHist, baris))
    {
        if (baris.find(username + ",") == 0)
        {
            cout << baris << endl;
        }
    }
    fileHist.close();
}

int cariPivot(string arr[], int awal, int akhir, bool asc);
void quickSortHistory(string arr[], int awal, int akhir, bool asc)
{
    if (awal < akhir)
    {
        int pivot = cariPivot(arr, awal, akhir, asc);
        quickSortHistory(arr, awal, pivot - 1, asc);
        quickSortHistory(arr, pivot + 1, akhir, asc);
    }
}

int ambilJumlah(const string &baris)
{
    size_t pos = baris.rfind(',');
    if (pos == string::npos)
        return 0;
    try
    {
        return stoi(baris.substr(pos + 1));
    }
    catch (...)
    {
        return 0;
    }
}

int cariPivot(string arr[], int awal, int akhir, bool asc)
{
    string pivot = arr[akhir];
    int pivotJumlah = ambilJumlah(pivot);
    int i = awal - 1;
    for (int j = awal; j < akhir; j++)
    {
        int jumlahSekarang = ambilJumlah(arr[j]);
        if ((asc && jumlahSekarang < pivotJumlah) || (!asc && jumlahSekarang > pivotJumlah))
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[akhir]);
    return i + 1;
}

// Fungsi mengurutkan dan menampilkan history sesuai ascending / descending
void urutkanHistory(const string &username, bool ascending)
{
    const int MAX_BARIS = 1000;
    string arrHistory[MAX_BARIS];
    int jumlahBaris = 0;
    string baris;

    ifstream fileHist("dataAccount.txt");
    while (getline(fileHist, baris))
    {
        if (baris.find(username + ",") == 0)
        {
            if (jumlahBaris < MAX_BARIS)
                arrHistory[jumlahBaris++] = baris;
        }
    }
    fileHist.close();

    if (jumlahBaris == 0)
    {
        cout << "Tidak ada history untuk user ini." << endl;
        return;
    }
    quickSortHistory(arrHistory, 0, jumlahBaris - 1, ascending);

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << (ascending ? setw(13) : setw(14)) << " ";
    if (ascending)
        cout << "HISTORY ASCENDING" << endl;
    else
        cout << "HISTORY DESCENDING" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    for (int i = 0; i < jumlahBaris; i++)
    {
        cout << arrHistory[i] << endl;
    }
}

void buy(const string &username, int &saldo)
{
    int pilihan, indexMenu, jumlahBeli;

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "KANTIN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Stand 1" << endl;
    cout << "2. Stand 2" << endl;
    cout << "3. Stand 3" << endl;
    cout << "4. Stand 4" << endl;
    cout << "5. Stand 5" << endl;
    cout << "Pilih stand: ";
    cin >> pilihan;
    cout << "| No  | Nama Menu                     | Harga    |" << endl;
    switch (pilihan)
    {
    case 1:
    {
        ifstream menuFile("menu.txt");
        if (menuFile.is_open())
        {
            string menuLine;
            int idx = 1;
            while (getline(menuFile, menuLine))
            {
                if (idx >= 2 && idx <= 10)
                {
                    cout << menuLine << endl;
                }
                if (idx > 10)
                    break;
                idx++;
            }
            cout << "Pilih menu : ";
            cin >> indexMenu;
            cout << "Jumlah beli: ";
            cin >> jumlahBeli;
            perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
            menuFile.close();
        }
        else
        {
            cout << "Gagal membuka file menu.txt!" << endl;
        }
        break;
    }
    case 2:
    {
        ifstream menuFile("menu.txt");
        if (menuFile.is_open())
        {
            string menuLine;
            int idx = 1;
            while (getline(menuFile, menuLine))
            {
                if (idx >= 12 && idx <= 16)
                {
                    cout << menuLine << endl;
                }
                if (idx > 16)
                    break;
                idx++;
            }
            cout << "Pilih menu : ";
            cin >> indexMenu;
            cout << "Jumlah beli: ";
            cin >> jumlahBeli;
            perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
            menuFile.close();
        }
        else
        {
            cout << "Gagal membuka file menu.txt!" << endl;
        }
        break;
    }
    case 3:
    {
        ifstream menuFile("menu.txt");
        if (menuFile.is_open())
        {
            string menuLine;
            int idx = 1;
            while (getline(menuFile, menuLine))
            {
                if (idx >= 18 && idx <= 24)
                {
                    cout << menuLine << endl;
                }
                if (idx > 24)
                    break;
                idx++;
            }
            cout << "Pilih menu : ";
            cin >> indexMenu;
            cout << "Jumlah beli: ";
            cin >> jumlahBeli;
            perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
            menuFile.close();
        }
        else
        {
            cout << "Gagal membuka file menu.txt!" << endl;
        }
        break;
    }
    case 4:
    {
        ifstream menuFile("menu.txt");
        if (menuFile.is_open())
        {
            string menuLine;
            int idx = 1;
            while (getline(menuFile, menuLine))
            {
                if (idx >= 26 && idx <= 31)
                {
                    cout << menuLine << endl;
                }
                if (idx > 31)
                    break;
                idx++;
            }
            cout << "Pilih menu : ";
            cin >> indexMenu;
            cout << "Jumlah beli: ";
            cin >> jumlahBeli;
            perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
            menuFile.close();
        }
        else
        {
            cout << "Gagal membuka file menu.txt!" << endl;
        }
        break;
    }
    case 5:
    {
        ifstream menuFile("menu.txt");
        if (menuFile.is_open())
        {
            string menuLine;
            int idx = 1;
            while (getline(menuFile, menuLine))
            {
                if (idx >= 33 && idx <= 38)
                {
                    cout << menuLine << endl;
                }
                if (idx > 38)
                    break;
                idx++;
            }
            cout << "Pilih menu (33-38): ";
            cin >> indexMenu;
            cout << "Jumlah beli: ";
            cin >> jumlahBeli;
            perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
            menuFile.close();
        }
        else
        {
            cout << "Gagal membuka file menu.txt!" << endl;
        }
        break;
    }
    default:
    {
        cout << "Pilihan tidak valid!" << endl;
    }
    }
}

void perhitunganHarga(const string &username, int &saldo, int indexMenu, int jumlahBeli)
{
    // Ambil harga dari menu.txt sesuai indexMenu (berdasarkan nomor menu di tabel)
    ifstream menuFile("menu.txt");
    string menuLine;
    int idx = 1;
    int harga = 0;
    while (getline(menuFile, menuLine))
    {
        // Cari baris menu yang sesuai dengan indexMenu (nomor menu di kolom pertama)
        size_t posNo = menuLine.find('|');
        if (posNo != string::npos)
        {
            // Ambil nomor menu dari kolom pertama
            size_t posNoEnd = menuLine.find('|', posNo + 1);
            string noMenuStr = menuLine.substr(posNo + 1, posNoEnd - posNo - 1);
            // Hilangkan spasi
            noMenuStr.erase(remove(noMenuStr.begin(), noMenuStr.end(), ' '), noMenuStr.end());
            int noMenu = 0;
            try
            {
                noMenu = stoi(noMenuStr);
            }
            catch (...)
            {
                continue;
            }
            if (noMenu == indexMenu)
            {
                // Cari ".Rp" lalu ambil harga setelahnya sampai sebelum '|'
                size_t posRp = menuLine.find(".Rp");
                if (posRp != string::npos)
                {
                    size_t posHargaEnd = menuLine.find('|', posRp);
                    string hargaStr = menuLine.substr(posRp + 3, posHargaEnd - (posRp + 3));
                    // Hilangkan spasi
                    hargaStr.erase(remove(hargaStr.begin(), hargaStr.end(), ' '), hargaStr.end());
                    harga = stoi(hargaStr);
                }
                break;
            }
        }
        idx++;
    }
    menuFile.close();

    if (harga == 0)
    {
        cout << "Menu tidak ditemukan atau format harga salah!" << endl;
        return;
    }

    int harga_total = harga * jumlahBeli;

    // Update saldo di akun.txt
    ifstream infile("akun.txt");
    ofstream outfile("akun_temp.txt");
    string line;
    bool updated = false;
    while (getline(infile, line))
    {
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');
        string file_user = line.substr(0, pos1);
        if (file_user == username)
        {
            int old_saldo = stoi(line.substr(pos2 + 1));
            if (old_saldo < harga_total)
            {
                cout << "Saldo tidak cukup untuk melakukan pembelian!" << endl;
                outfile << line << endl;
            }
            else
            {
                int new_saldo = old_saldo - harga_total;
                outfile << username << "," << line.substr(pos1 + 1, pos2 - pos1 - 1) << "," << new_saldo << endl;
                saldo = new_saldo;
                updated = true;
            }
        }
        else
        {
            outfile << line << endl;
        }
    }
    infile.close();
    outfile.close();
    remove("akun.txt");
    rename("akun_temp.txt", "akun.txt");

    if (updated)
    {
        cout << "Pembelian berhasil! Saldo sekarang: " << saldo << endl;
        // Simpan history ke dataAccount.txt
        ofstream histfile("dataAccount.txt", ios::app);
        if (histfile.is_open())
        {
            histfile << username << ",pengeluaran," << harga_total << endl;
            histfile.close();
        }
    }
    else
    {
        cout << "Gagal melakukan pembelian atau saldo tidak cukup!" << endl;
    }
}

int main()
{
    int pilihan;
    do
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(15) << " " << "MENU UTAMA" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Sign In" << endl;
        cout << "3. Keluar" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            signup();
            break;
        case 2:
            signin();
            break;
        case 3:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 3);

    return 0;
}
