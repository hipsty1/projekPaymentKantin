#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// deklarasi
int saldo = 0;
string namaUser, passUser;
//int pilihTopUp;
//string passwordCheck;

// data
// data user
struct Account { 
    string username;
    string password;
};
Account account [10] = {
    {"Hendri","123240066"},
    {"Restu","123240050"},
    {"Zen","123240061"},
    {"Deva","123240080"}};

/*
// data nama stand
string kantin[5] = {"Dapur Mak'E - Depok", "Kentang Kletji", "Soto Seger Boyolali - Bu Retno", "Komunitas Kantin Puspita", "Kantin 21"};
// data menu kantin
struct menu{
    string namaMkn;
    int harga;
};
menu kantin1[8] = {{"Nasi Ayam Penyet", 13000}, {"Nasi Ayam Crispy", 13000}, {"Nasi Lele", 11000}, {"Nasi Telur", 8000}, {"Nasi Tempe Tahu", 7000}, {"Nasi Ati Ampela", 10000}, {"Nasi Kulit", 12000}, {"Jus Buah", 8000}};
menu kantin2[5] = {{"Dimsum Rame-rame", 30000}, {"Dimsum keju", 20000}, {"Dimsum Original", 15000}, {"Tori Katsu Chiizu Rice", 23000}, {"Dimsum Mayo", 20000}};
menu kantin3[7] = {{"Nasi Soto Ayam", 7000}, {"Lontong Opor Ayam", 13000}, {"Nasi Rames Telur", 11000}, {"Nasi Pecel Lele", 11000}, {"Nasi Rames Lele", 11000}, {"Es Teh", 3000}, {"Es Lemon Tea", 4000}};
menu kantin4[6] = {{"Indomie Telur", 10000}, {"Nasi Rawon", 16000}, {"Nasi Ayam Geprek", 12000}, {"Rice Bowl", 11000}, {"Es Kuwut", 5000}, {"Cola", 6000}};
menu kantin5[8] = {{"Indomie Goreng Kornet", 10000}, {"Indomie rebus Kornet", 10000}, {"Indomie Goreng Kornet Telur", 13000}, {"Indomie Rebus Kornet", 13000}, {"Indomie Goreng Kornet Sosis", 9000}, {"Indomie Rebus Kornet", 9000}, {"Es Jeruk", 3000}, {"Es Nutrisari", 4000}};
// data menu top up
int topUp[6] = {5000, 10000, 20000, 25000, 50000, 100000};
*/
// prototype
void firstMenu();
void signup();
void signin();
void profile();
// void tambahSaldo();
// void buy();
// void exit();

int main(){
    firstMenu();
    return 0;
}

void firstMenu(){
    int pilih;
    // tampilan awal
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(15) << " " << "MENU AWAL" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. Sign Up" << endl << "2. Sign In" << endl << "3. Out" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Pilih : "; cin >> pilih;
    system("pause");

    system("cls");
    switch(pilih){
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

//menu sig in (daftar account)
void signup(){
    Account newAccount;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGNUP" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username (tanpa spasi) : "; cin >> newAccount.username;
    cout << "Masukkan Password (gunakan NIM) : "; cin >> newAccount.password;

    // Cek apakah username sudah ada
    for(int i = 0; i < 10; i++) {
        if(account[i].username == newAccount.username) {
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << "Username sudah digunakan. Coba lagi." << endl;
            cout << setfill('=') << setw(40) << "=" << endl;
            system("pause");
            return signup();
        }
    }

    // Menyimpan akun baru ke dalam array jika masih ada slot kosong
    for(int i = 0; i < 10; i++) {
        if(account[i].username.empty()) {  
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
void signin() {
    string username, password;
    bool cek = false; // Menyimpan status login berhasil/gagal

    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "SIGN IN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username : "; cin >> username;
    cout << "Masukkan Password : "; cin >> password;
    cout << setfill('=') << setw(40) << "=" << endl;

    // Perbaikan: Cek hanya dalam batas jumlah akun yang tersedia
    int jumlahAkun = sizeof(account) / sizeof(account[0]);
    
    for (int i = 0; i < jumlahAkun; i++) {
        if (account[i].username == username && account[i].password == password) {
            cek = true;
            break; // Keluar dari loop jika sudah ditemukan akun yang cocok
        }
    }

    if (cek) {
        namaUser = username;
        passUser = password;
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(14) << " " << "SIGN IN SUCCESS" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        profile(); // Masuk ke menu profile setelah login berhasil
    } else {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(14) << " " << "SIGN IN FAILED" << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        system("pause");
        signin(); // Meminta user login kembali jika gagal
    }
}


void profile(){
    char pilih;
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "PROFILE" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "NAME\t: " << namaUser << endl;
    cout << "SALDO\t: " << saldo << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. TOP UP" << endl;
    cout << "2. BUY" << endl;
    cout << "3. LOG OUT" << endl;
    cout << "4. HISTORY TRANSAKSI" << endl;
    cout << "5. SETTING" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "PILIH : ";
    cin >> pilih;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    switch (pilih){
    case '1':
        // tambahSaldo();
        break;

    case '2':
        // buy();
        break;

    case '3':
        // exit(0);
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

/*

void tambahSaldo()
{
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
    if(1<= pilihTopUp && pilihTopUp <= 6) {
        //confirmasi password
        bool check = false;
        int kesempatannya = 3;
        while(check == false){
            system("cls");
            cout << setfill('=') << setw(40) << "=" << endl;
            cout << "Enter your Password : ";
            cin >> passwordCheck;
            cout << setfill('=') << setw(40) << "=" << endl;
            if(passwordCheck==password){
                check = true;
            }else if(passwordCheck != password && kesempatannya > 1){
                kesempatannya--;
            }else if(passwordCheck != password && kesempatannya <= 1){
                exit();
            }
            system("pause");
        };
    }

    //top op succes
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(12) << " " << "TOPUP SUCCESSED" << endl;
    switch (pilihTopUp)
    {
    case 1:
        saldo += 5000;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : " << topUp[pilihTopUp-1] << endl;
        break;

    case 2:
        saldo += 10000;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : " << topUp[pilihTopUp-1] << endl;
        break;

    case 3:
        saldo += 20000;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : " << topUp[pilihTopUp-1] << endl;
        break;

    case 4:
        saldo += 25000;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : " << topUp[pilihTopUp-1] << endl;
        break;

    case 5:
        saldo += 50000;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : " << topUp[pilihTopUp-1] << endl;
        break;

    case 6:
        saldo += 100000;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : " << topUp[pilihTopUp-1] << endl;
        break;

    default:
        system("cls");
        cout << setfill('=') << setw(40) << " " << endl;
        cout << setfill(' ') << setw(9) << " " << "PILIHAN TIDAK TERSEDIA" << endl;
        cout << setfill(' ') << setw(5) << " " << "Sebesar : -" << endl;
        break;
    }
    cout << setfill(' ') << setw(5) << " " << "Saldo saat ini : " << saldo << endl;
    cout << setfill('=') << setw(40) << " " << endl;
    system("pause");

    //konfirmasi top up lagi
    cout << setfill('=') << setw(40) << " " << endl;
    cout << "Apakah anda ingin TopUp? (y/n) : ";
    cin >> pilih;
    if (pilih == 'y' || pilih == 'Y'){
        tambahSaldo();
    }else if (pilih == 'n' || pilih == 'N'){
        profile();
    }else{
        cout << "INPUT SALAH" << endl;
        system("pause");
        tambahSaldo();
    }
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
}

void buy(){
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(13) << " " << "TAMPILAN MENU" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
}

void exit(){
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << "ANDA DIKELUARKAN" << endl; // PAKE B ING
    cout << setfill('=') << setw(40) << "=" << endl;
    exit(0);
    
}
*/