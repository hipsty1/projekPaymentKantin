#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// deklarasi global
int pilihKantin, pilihmenu; // menyimpan suatu alamat nilaiinput pilih untuk dijadikan histoey
int total = 0;              // total harga awal sebelum user membeli menu
int harga;                  // deklarasi untuk fungsi pembayaran
int saldo = 0;              // saldo awal user
string nama_now, pass_now;  // menyimpan data nama dan pass user

struct Account
{
    string username;
    string password;
    int saldo;
};
Account account[10] = {
    {"Hendri", "123240066"},
    {"Restu", "123240050"},
    {"Zen", "123240061"},
    {"Deva", "123240080"}};

Account akun[1000];
struct menu
{
    string namaMkn;
    int harga;
};
menu kantin1[8] = {{"Nasi Ayam Penyet", 13000}, {"Nasi Ayam Crispy", 13000}, {"Nasi Lele", 11000}, {"Nasi Telur", 8000}, {"Nasi Tempe Tahu", 7000}, {"Nasi Ati Ampela", 10000}, {"Nasi Kulit", 12000}, {"Jus Buah", 8000}};
menu kantin2[5] = {{"Dimsum Rame-rame", 30000}, {"Dimsum keju", 20000}, {"Dimsum Original", 15000}, {"Tori Katsu Chiizu Rice", 23000}, {"Dimsum Mayo", 20000}};
menu kantin3[7] = {{"Nasi Soto Ayam", 7000}, {"Lontong Opor Ayam", 13000}, {"Nasi Rames Telur", 11000}, {"Nasi Pecel Lele", 11000}, {"Nasi Rames Lele", 11000}, {"Es Teh", 3000}, {"Es Lemon Tea", 4000}};
menu kantin4[6] = {{"Indomie Telur", 10000}, {"Nasi Rawon", 16000}, {"Nasi Ayam Geprek", 12000}, {"Rice Bowl", 11000}, {"Es Kuwut", 5000}, {"Cola", 6000}};
menu kantin5[8] = {{"Indomie Goreng Kornet", 10000}, {"Indomie rebus Kornet", 10000}, {"Indomie Goreng Kornet Telur", 13000}, {"Indomie Rebus Kornet", 13000}, {"Indomie Goreng Kornet Sosis", 9000}, {"Indomie Rebus Kornet", 9000}, {"Es Jeruk", 3000}, {"Es Nutrisari", 4000}};
// data menu history
struct history
{
    bool riwayat; // 0 topup, 1 transaksi
    int keuangan; // nominalnya
};
int j = 0;
int batas = 0;
const int N = 1000;   // konstanta untuk menetapkan jumlah history yang ditampung
history transaksi[N]; // data untuk menyimpan history transaksi

// data nama stand
string kantin[5] = {
    "     Dapur Mak'E - Depok      ",
    "        Kentang Kletji        ",
    "     Soto Seger Boyolali      ",
    "   Komunitas Kantin Puspita   ",
    "           Kantin 21          "};
// data menu top up
int topUp[6] = {5000, 10000, 20000, 25000, 50000, 100000};

// prototype
void homePage();
void signup();
void signin();
void profile();
void tambahSaldo();
void buy();
void detailHistory();
int bayar(int a, int b);
int totalHarga(int a, int b);
bool konfirmasiPassword();
void sortingAsc(int first, int last);
void banyakAcc();
void lowerCase(string &kata);
int banyak_acc = 0;
int indeks = 0;

void banyakAcc()
{
    string username, pass;
    int saldo;
    banyak_acc = 0;
    ifstream data("Acc.txt");
    if (data.is_open())
    {
        while (data >> username >> pass >> saldo)
        {
            akun[banyak_acc].username = username;
            akun[banyak_acc].password = pass;
            akun[banyak_acc].saldo = saldo;
            banyak_acc++;
        }
        data.close();
    }
    else
    {
        cout << "File error" << endl;
    }
}

int main()
{
    homePage();
    return 0;
}

void homePage()
{
    int pilihmenuawal;

    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(15) << " " << "MENU AWAL" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Sign Up" << endl
         << "2. Sign In" << endl
         << "3. Out" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih : ";
    cin >> pilihmenuawal;
    system("pause");
    system("cls");
    switch (pilihmenuawal)
    {
    case 1:
        banyakAcc();
        signup();
        break;
    case 2:
        banyakAcc();
        signin();
        break;
    case 3:
        exit(0);
        break;
    default:
        homePage();
    }
}

// bool checkAcc(string newUsername)
// {
//     bool check = false;
//     ifstream file("Acc.txt");
//     if (file.is_open())
//     {
//         while (file >> nama_now >> pass_now)
//         {
//             if (nama_now == newUsername)
//             {
//                 check = true;
//             }
//         }
//     }
//     else
//     {
//         check = false;
//     }
//     return check;
// }
// void inputData(string username, string password, int saldo){

// }

void signup()
{
    string username, pass;
    bool found = false;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGNUP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username (tanpa spasi) : ";
    cin >> username;
    lowerCase(username);
    cout << "Masukkan Password (gunakan NIM) : ";
    cin >> pass;

    for (int i = 0; i < banyak_acc; i++)
    {
        if (akun[i].username == username)
        {
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << "Username sudah digunakan. Coba lagi" << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            system("pause");
            found = true;
            return homePage();
        }
    }
    // Menyimpan akun baru ke dalam array jika masih ada slot kosong
    if (!found)
    {
        akun[banyak_acc].username = username;
        akun[banyak_acc].password = pass;
        akun[banyak_acc].saldo = 0;
        banyak_acc++;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Akun berhasil dibuat!" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        ofstream file("Acc.txt", ios::app);
        if (file.is_open())
        {
            file << username << " " << pass << " " << akun[banyak_acc].saldo << endl;
            file.close();
        }
        system("pause");
        homePage();
    }
    // // jika slot akun penuh
    // cout << setfill('=') << setw(40) << "=" << endl;
    // cout << "Pendaftaran gagal! Kapasitas akun penuh." << endl;
    // cout << setfill('=') << setw(40) << "=" << endl;
    homePage();
}

void lowerCase(string &kata)
{
    if (kata.length() == 0)
    {
        return;
    }
    for (int i = 0; i < kata.length(); i++)
    {
        if (kata[i] >= 'A' && kata[i] <= 'Z')
        {
            kata[i] = kata[i] + 32;
        }
    }
}
// menu sign in
void signin()
{
    string username, password;
    bool cek = false; // Menyimpan status login berhasil/gagal
    // tampilan awal menu sign in
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGN IN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username : ";
    cin >> username;
    lowerCase(username);
    cout << "Masukkan Password : ";
    cin >> password;
    cout << setfill('=') << setw(40) << "=" << endl;
    // cek apakah user terdaftar
    for (int i = 0; i < banyak_acc; i++)
    {
        if (akun[i].username == username && akun[i].password == password)
        {
            cek = true;
            nama_now = username; // mengoper pass agar bisa digunakan secara global
            pass_now = password; // mengoper nama agar bisa digunakan secara global
            indeks = i;
            break; // Keluar dari loop jika sudah ditemukan akun yang cocok
        }
    }
    // tampilan menu setelah cek apakah akun tersedia atau tidak
    if (cek)
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(14) << "SIGN IN SUCCESS" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        profile(); // Masuk ke menu profile setelah login berhasil
    }
    else
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(14) << "SIGN IN FAILED" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        homePage(); // Meminta user kembali ke homepage jika gagal
    }
}
// menu profile user
void profile()
{
    char pilihmenuprofile;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "PROFILE" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Nama   : " << nama_now << endl;
    cout << "Saldo  : " << akun[indeks].saldo << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. TOP UP" << endl;
    cout << "2. BUY" << endl;
    cout << "3. HISTORY TRANSAKSI" << endl;
    cout << "4. LOG OUT" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih : ";
    cin >> pilihmenuprofile;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    // kondisi ketika input menu
    switch (pilihmenuprofile)
    {
    case '1':
        tambahSaldo();
        break;
    case '2':
        buy();
        break;
    case '3':
        detailHistory();
        break;
    case '4':
        exit(0);
        break;
    default:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "INVALID MENU" << endl
             << setw(12) << " " << "PLEASE TRY AGAIN" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        profile();
    }
}
// fungsi konfirmasi password ketika membeli
bool konfirmasiPassword(int kesempatan)
{
    string passwordCheck;
    if (kesempatan <= 0)
    {
        cout << "Batas percobaan habis" << endl;
        return false;
    }
    else
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(9) << " " << "KONFIRMASI PEMBAYARAN" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Masukkan password (Sisa " << kesempatan << " kesempatan): ";
        cin >> passwordCheck;
        cout << setfill('=') << setw(40) << "=" << endl;
    }
    // cek password yang diinput dengan password user
    if (passwordCheck == pass_now)
    {
        return true;
    }
    else
    {
        cout << "Password salah!" << endl;
        system("pause");
        return konfirmasiPassword(kesempatan - 1);
    }
}

// fungsi menambahkan saldo
void tambahSaldo()
{
    string username, pass;
    char pilih;
    int pilihTopUp, nominal, kesempatan = 3;
    // menampilkan menu top up
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "TOP UP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 6; i++)
        cout << i + 1 << ". " << topUp[i] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih Jumlah TopUp : ";
    cin >> pilihTopUp;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    // operasi dan konfirmasi top up
    system("cls");
    if (1 <= pilihTopUp && pilihTopUp <= 6)
    {
        if (!konfirmasiPassword(kesempatan))
        {
            tambahSaldo();
        }
        else
        {
            system("cls");
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << setfill(' ') << setw(12) << " " << "TOPUP SUCCESSED" << endl;
            if (indeks != -1)
            {
                nominal = topUp[pilihTopUp - 1];
                akun[indeks].saldo += nominal;

                transaksi[j].riwayat = 0;
                transaksi[j].keuangan = nominal;
                j++;
            }
            ofstream file("Acc.txt"); // Buka file dalam mode tulis (overwrite, BUKAN append)
            if (file.is_open())
            {
                for (int k = 0; k < banyak_acc; ++k)
                {
                    file << akun[k].username << " " << akun[k].password << " " << akun[k].saldo << endl;
                }
                file.close();
                cout << "Nominal        : " << nominal << endl;
                cout << "Saldo saat ini : " << akun[indeks].saldo << endl; // Tampilkan saldo yang benar
            }
            else
            {
                cout << "Error: Gagal membuka file Acc.txt untuk menyimpan perubahan saldo." << endl;
                akun[indeks].saldo -= nominal;
            }
        }
    }
    else
    {
        system("cls");
        cout << setfill('=') << setw(40) << " " << endl;
        cout << setfill(' ') << setw(9) << " " << "PILIHAN TIDAK TERSEDIA" << endl;
        cout << setfill(' ') << setw(5) << " " << "Nominal : -" << endl;
    }

    // konfirmasi untuk top up berulang
    cout << setfill('=') << setw(40) << " " << endl;
    cout << "Ingin TopUp kembali? (y/n) : ";
    cin >> pilih;
    if (pilih == 'y' || pilih == 'Y')
    {
        tambahSaldo();
    }
    else if (pilih == 'n' || pilih == 'N')
    {
        profile();
    }
    else
    {
        cout << "INPUT SALAH" << endl;
        system("pause");
        tambahSaldo();
    }
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
}
// fungsi menu pembelian
string gantiUnderscore(string kata)
{
    for (int i = 0; i < kata.length(); i++)
    {
        if (kata[i] == '_')
        {
            kata[i] = ' ';
        }
    }
    return kata;
}


void menuData(string namaFile)
{
    int no, harga;
    string nama;
    ifstream file(namaFile);
    if (file.is_open())
    {
        while (file >> no >> nama >> harga)
        {
            cout << no << ". " << setfill(' ')
                 << setw(28) << left << gantiUnderscore(nama) << "Rp"
                 << setw(6) << right << harga << endl;
        }
    }
}


void buy()
{
    string namaFile1 = "kantin1.txt";
    string namaFile2 = "kantin2.txt";
    string namaFile3 = "kantin3.txt";
    string namaFile4 = "kantin4.txt";
    string namaFile5 = "kantin5.txt";
    int qty;
    char ulang;
    // tampilan daftar kantin
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "PILIH KANTIN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 5; i++)
        cout << "|  " << i + 1 << "  |" << setfill(' ') << setw(30) << kantin[i] << "  |" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih Kantin   : ";
    cin.ignore();
    cin >> pilihKantin;
    // menu masing masing kantin
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(5) << " " << kantin[pilihKantin - 1] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    switch (pilihKantin)
    {
    case 1:
        menuData(namaFile1);
        break;
    case 2:
        menuData(namaFile2);
        break;
    case 3:
        menuData(namaFile3);
        break;

    case 4:
        menuData(namaFile4);
        break;

    case 5:
        menuData(namaFile5);
        break;

    default:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilihan tidak tersedia" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        break;
    }
    // memilih menu yang akan dibeli
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih Menu : ";
    cin >> pilihmenu;
    cout << "banyaknya : ";
    cin >> qty;
    cout << setfill('=') << setw(40) << "=" << endl;
    totalHarga(pilihmenu, qty);
    cout << setfill('=') << setw(40) << "=" << endl;
    // konfirmasi tambah pesanan
    cout << "ingin menambahkan lagi? (y/n) : ";
    cin >> ulang;

    if (ulang == 'y' || ulang == 'Y')
    {
        buy();
    }
    else
    {
        bayar(pilihmenu, qty);
    }
}
// fungsi menghitung jumlah harga yang harus dibayar
int totalHarga(int a, int b)
{
    // operasi tiap tiap kantin
    switch (pilihKantin)
    {
    case 1:
        harga = kantin1[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << harga << endl;
        cout << "Total harga : " << total << endl;
        break;
    case 2:
        harga = kantin2[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << harga << endl;
        cout << "Total harga : " << total << endl;
        break;
    case 3:
        harga = kantin3[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << harga << endl;
        cout << "Total harga : " << total << endl;
        break;
    case 4:
        harga = kantin4[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << harga << endl;
        cout << "Total harga : " << total << endl;
        break;
    case 5:
        harga = kantin5[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << harga << endl;
        cout << "Total harga : " << total << endl;
        break;
    }
    return total;
}
// fungsi untuk pembayaran user
int bayar(int a, int b)
{
    // cek sisa saldo dan harga yang harus dibayar user
    if (saldo < total)
    {
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Saldo anda tidak cukup" << endl
             << "Lakukan Top Up terlebih dahulu" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
    }
    else
    {
        // konfirmasi pembayaran user menggunakan password
        if (!konfirmasiPassword(3))
        {
            system("cls");
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << setfill('=') << setw(11) << " " << "PAYMENT CANCELED" << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            system("pause");
        }
        else
        {
            system("cls");
            saldo -= total;
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << setfill(' ') << setw(11) << " " << "PAYMENT SUCCESED" << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << "Total harga : " << total << endl;
            cout << "Sisa Saldo  : " << saldo << endl
                 << endl;
            transaksi[j].riwayat = 1;
            transaksi[j].keuangan = total;
            j++;
            cout << setfill(' ') << setw(5) << " " << "Terimakasih telah berbelanja" << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            system("pause");
        }
    }
    // mengembalikan nilai total dan harga agar dapat digunakan lagi (set default)
    total = 0;
    harga = 0;
    profile();
}
// menu history top up dan pembayaran user
void detailHistory()
{
    int a, b;
    char pilihHistory;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(11) << " " << "HISTORI TRANSAKSI\n";
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Seluruh History \n";
    cout << "2. History Nominal (Terkecil)\n";
    cout << "3. History Nominal (Terbesar)\n";
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih urutan: ";
    cin >> pilihHistory;
    cout << setfill('=') << setw(40) << "=" << endl;

    switch (pilihHistory)
    {
    case '1':
        if (j == 0)
            cout << endl
                 << "   Anda belum melakukan transaksi" << endl
                 << endl;
        for (int k = 0; k < j; k++)
        {
            if (transaksi[k].riwayat == 0)
                cout << "|" << endl
                     << "o  \033[32mPemasukan          +" << transaksi[k].keuangan << "\033[0m" << endl;
            if (transaksi[k].riwayat == 1)
                cout << "|" << endl
                     << "o  \033[31mPengeluaran        -" << transaksi[k].keuangan << "\033[0m" << endl;
        }
        break;
    case '2':
        a = 0;
        b = j;
        sortingAsc(a, b);
        for (int k = 0; k < j; k++)
        {
            if (transaksi[k].riwayat == 0)
                cout << "|" << endl
                     << "o  \033[32mPemasukan          +" << transaksi[k].keuangan << "\033[0m" << endl;
            if (transaksi[k].riwayat == 1)
                cout << "|" << endl
                     << "o  \033[31mPengeluaran        -" << transaksi[k].keuangan << "\033[0m" << endl;
        }
        break;

    default:
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }

    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    profile();
};
// urut kecil ke besar
void sortingAsc(int first, int last)
{

    int low, high, mid, temp;
    low = first;
    high = last;
    mid = transaksi[(first + last) / 2].keuangan;

    do
    {
        while (transaksi[low].keuangan < mid)
            low++;
        while (transaksi[high].keuangan > mid)
            high--;

        if (low <= high)
        {
            temp = transaksi[low].keuangan;
            transaksi[low].keuangan = transaksi[high].keuangan;
            transaksi[high].keuangan = temp;
            low++;
            high--;
        }
    } while (low <= high);

    if (first < high)
        sortingAsc(first, high);
    if (low < last)
        sortingAsc(low, last);
}