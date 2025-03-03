#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// deklarasi
int saldo = 0;
string namaUser, passUser;

// data
// data user
struct Account
{
    string username;
    string password;
};
Account account[10] = {
    {"Hendri", "123240066"},
    {"Restu", "123240050"},
    {"Zen", "123240061"},
    {"Deva", "123240080"}};

// data menu kantin
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
// data menu top up

// data nama stand
string kantin[5] = {"     Dapur Mak'E - Depok      ", "        Kentang Kletji        ", "     Soto Seger Boyolali      ", "   Komunitas Kantin Puspita   ", "           Kantin 21          "};

int topUp[6] = {5000, 10000, 20000, 25000, 50000, 100000};

// prototype
void firstMenu();
void signup();
void signin();
void profile();
void tambahSaldo();
void buy();
int bayar(int a, int b);
int totalHarga(int a, int b);
bool konfirmasiPassword();

int main()
{
    firstMenu();
    return 0;
}

void firstMenu()
{
    int pilihmenuawal;
    // tampilan awal
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
        signup();
        break;

    case 2:
        signin();
        break;

    case 3:
        exit(0);
        break;

    default:
        firstMenu();
    }
}

// menu sig in (daftar account)
void signup()
{
    Account newAccount;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGNUP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username (tanpa spasi) : ";
    cin >> newAccount.username;
    cout << "Masukkan Password (gunakan NIM) : ";
    cin >> newAccount.password;

    // Cek apakah username sudah ada
    for (int i = 0; i < 10; i++)
    {
        if (account[i].username == newAccount.username)
        {
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << "Username sudah digunakan. Coba lagi." << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            system("pause");
            return signup();
        }
    }

    // Menyimpan akun baru ke dalam array jika masih ada slot kosong
    for (int i = 0; i < 10; i++)
    {
        if (account[i].username.empty())
        {
            account[i] = newAccount;
            namaUser = newAccount.username;
            passUser = newAccount.password;
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << "Akun berhasil dibuat!" << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            system("pause");
            profile();
            return;
        }
    }
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pendaftaran gagal! Kapasitas akun penuh." << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    firstMenu();
}

// menu signin
void signin()
{
    string username, password;
    bool cek = false; // Menyimpan status login berhasil/gagal

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGN IN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username : ";
    cin >> username;
    cout << "Masukkan Password : ";
    cin >> password;
    cout << setfill('=') << setw(40) << "=" << endl;

    // Perbaikan: Cek hanya dalam batas jumlah akun yang tersedia
    int jumlahAkun = sizeof(account) / sizeof(account[0]);

    for (int i = 0; i < jumlahAkun; i++)
    {
        if (account[i].username == username && account[i].password == password)
        {
            cek = true;
            break; // Keluar dari loop jika sudah ditemukan akun yang cocok
        }
    }

    if (cek)
    {
        namaUser = username;
        passUser = password;
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(14) << " " << "SIGN IN SUCCESS" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        profile(); // Masuk ke menu profile setelah login berhasil
    }
    else
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(14) << " " << "SIGN IN FAILED" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        signin(); // Meminta user login kembali jika gagal
    }
}

void profile()
{
    char pilihmenuprofile;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "PROFILE" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "NAME\t: " << namaUser << endl;
    cout << "SALDO\t: " << saldo << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. TOP UP" << endl;
    cout << "2. BUY" << endl;
    cout << "3. SETTING" << endl;
    cout << "4. HISTORY TRANSAKSI" << endl;
    cout << "5. LOG OUT" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "PILIH : ";
    cin >> pilihmenuprofile;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    switch (pilihmenuprofile)
    {
    case '1':
        tambahSaldo();
        break;

    case '2':
        buy();
        break;

    case '3':
        // setting();
        break;
    case '4':
        // historyTransaksi();
        break;

    case '5':
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

bool konfirmasiPassword(int kesempatan){
    if (kesempatan <= 0) {
        cout << "Batas percobaan habis" << endl;
        return false;
    }
    
    string passwordCheck;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan password Anda (Sisa" << kesempatan << " kesempatan): ";
    cin >> passwordCheck;
    cout << setfill('=') << setw(40) << "=" << endl;
    
    if (passwordCheck == passUser) {
        return true;
    }
    
    cout << "Password salah!" << endl;
    system("pause");
    return konfirmasiPassword(kesempatan - 1);
}

void tambahSaldo()
{
    char pilih;
    int pilihTopUp, nominal = topUp[pilihTopUp - 1], kesempatan = 3;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "TOP UP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << ". " << topUp[i] << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih Jumlah TopUp : ";
    cin >> pilihTopUp;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    system("cls");
    if (1 <= pilihTopUp && pilihTopUp <= 6)
    {
        if (!konfirmasiPassword(kesempatan)) //password salah   
        {
            tambahSaldo();
        }
        else
        {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(12) << " " << "TOPUP SUCCESSED" << endl;

        saldo += nominal;
        cout << "Nominal        : " << nominal << endl;
        cout << "Saldo saat ini : " << saldo << endl;
        }
    }
    else
    {
        system("cls");
        cout << setfill('=') << setw(40) << " " << endl;
        cout << setfill(' ') << setw(9) << " " << "PILIHAN TIDAK TERSEDIA" << endl;
        cout << setfill(' ') << setw(5) << " " << "Nominal : -" << endl;
    }
    cout << setfill('=') << setw(40) << " " << endl;

    system("pause");

    // konfirmasi top up lagi
    cout << setfill('=') << setw(40) << " " << endl;
    cout << "Apakah anda ingin TopUp? (y/n) : ";
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

int pilihmenu;
void buy()
{
    int pilihkantin, qty;
    char ulang;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "PILIH KANTIN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "|  " << i + 1 << "  |" << setfill(' ') << setw(30) << kantin[i] << "  |" << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih Kantin   : ";
    cin.ignore();
    cin >> pilihkantin;

    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(5) << " " << kantin[pilihkantin - 1] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;

    switch (pilihkantin)
    {
    case 1:
        for (int i = 0; i < 8; i++)
        {
            cout << i + 1 << ". " << kantin1[i].namaMkn << " - Rp." << kantin1[i].harga << endl;
        }
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihmenu;
        cout << "banyaknya : ";
        cin >> qty;
        cout << setfill('=') << setw(40) << "=" << endl;
        totalHarga(pilihmenu, qty);
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 2:
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << kantin2[i].namaMkn << " - Rp." << kantin2[i].harga << endl;
        }
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihmenu;
        cout << "banyaknya : ";
        cin >> qty;
        cout << setfill('=') << setw(40) << "=" << endl;
        totalHarga(pilihmenu, qty);
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 3:
        for (int i = 0; i < 7; i++)
        {
            cout << i + 1 << ". " << kantin3[i].namaMkn << " - Rp." << kantin3[i].harga << endl;
        }
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihmenu;
        cout << "banyaknya : ";
        cin >> qty;
        cout << setfill('=') << setw(40) << "=" << endl;
        totalHarga(pilihmenu, qty);
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 4:
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << ". " << kantin4[i].namaMkn << " - Rp." << kantin4[i].harga << endl;
        }
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihmenu;
        cout << "banyaknya : ";
        cin >> qty;
        cout << setfill('=') << setw(40) << "=" << endl;
        totalHarga(pilihmenu, qty);
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 5:
        for (int i = 0; i < 8; i++)
        {
            cout << i + 1 << ". " << kantin5[i].namaMkn << " - Rp." << kantin5[i].harga << endl;
        }
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihmenu;
        cout << "banyaknya : ";
        cin >> qty;
        cout << setfill('=') << setw(40) << "=" << endl;
        totalHarga(pilihmenu, qty);
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    default:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Pilihan tidak tersedia" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        break;
    }
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

int total = 0;
int totalHarga(int a, int b)
{
    int harga;
    switch (pilihmenu)
    {
    case 1:
        harga = kantin1[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << harga << endl;
        cout << "Total harga : " << total << endl;
        break;
    case 2:
        harga = kantin1[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << total << endl;
        cout << "Total harga : " << harga << endl;
        break;
    case 3:
        harga = kantin1[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << total << endl;
        cout << "Total harga : " << harga << endl;
        break;
    case 4:
        harga = kantin1[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << total << endl;
        cout << "Total harga : " << harga << endl;
        break;
    case 5:
        harga = kantin1[a - 1].harga * b;
        total += harga;
        cout << "Subtotal    : " << total << endl;
        cout << "Total harga : " << harga << endl;
        break;
    }
    return total;
}

int bayar(int a, int b)
{
    int harga;
    if (saldo < harga)
    {
        cout << "Saldo anda tidak cukup";
        return 0;
    }
    else
    {
        char konfirmasi;
        cout << "Konfirmasi pembayaran? (y/n) : ";
        cin >> konfirmasi;
        if (konfirmasi == 'y' || konfirmasi == 'Y')
        {
            saldo -= harga;
            cout << "Pembayaran berhasil" << endl;
            return harga;
        }
        else
        {
            cout << "Pembayaran dibatalkan" << endl;
        }
    }

}