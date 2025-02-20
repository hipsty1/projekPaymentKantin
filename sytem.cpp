#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// deklarasi
int saldo = 0, pilihTopUp;
char pilih;
string username, password, passwordCheck;
bool check = false;
int kesempatannya = 3;

// data
// data nama stand
string kantin[5] = {"Dapur Mak'E - Depok", "Kentang Kletji", "Soto Seger Boyolali - Bu Retno", "Komunitas Kantin Puspita", "Kantin 21"};
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
int topUp[6] = {5000, 10000, 20000, 25000, 50000, 100000};

// prototype
void login();
void profile();
void tambahSaldo();
void menuKantin();
void exit();

int main()
{
    login();
    profile();
    return 0;
}

void login()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(17) << " " << "LOGIN" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "Masukkan Username : "; getline(cin, username);
    cout << "Masukkan Password : "; getline(cin, password);
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
}

void profile()
{
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "PROFILE" << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "NAME\t: " << username << endl;
    cout << "SALDO\t: " << saldo << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "1. TOP UP" << endl;
    cout << "2. BUY" << endl;
    cout << "3. LOG OUT" << endl;
    /*HEN DISINI AKU MAU NAMBAHIN SESUATU :)
    JADI NANTI KLO BISA LOGICNYA ITU NANTI BUAT KEK APLIKASI
    NANTI TAMBAHIN :
    4. SETTING
    DISINI TU BISA BUAT SESUATU KEK MAU UBAH NAMA, MAU UBAH PASS, 
    TAPI KEK MASUKIN PASS LAMA DULU KLO GABISA YA GABISA DIUBAH
    UDAH SIH GITUAJA EHE:) TAPI KU BUAT LOGIC UNTUK GINI DULU DI TOPUP
    */
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << "PILIH : ";
    cin >> pilih;
    cout << setfill('=') << setw(40) << "=" << endl;
    system("pause");
    switch (pilih)
    {
    case '1':
        tambahSaldo();
        break;

    case '2':
        menuKantin();
        break;

    case '3':
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
    while(check == false)
    {
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "Enter your Password : "; //NANTI DISINI MAU KU BIKIN JADI BINTANG KLO DIKETIK
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
    
    

    

    switch (pilihTopUp)
    {
    case 1:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "TOPUP SUCCESSED" << endl;
        cout << setfill(' ') << setw(20) << "Sebesar " << topUp[0] << endl;
        cout << endl
             << endl;
        saldo += 5000;
        cout << "\tSaldo saat ini\t: " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 2:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "TOPUP SUCCESSED" << endl;
        cout << setfill(' ') << setw(20) << "Sebesar " << topUp[1] << endl;
        cout << endl
             << endl;
        saldo += 10000;
        cout << "\tSaldo saat ini\t: " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 3:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "TOPUP SUCCESSED" << endl;
        cout << setfill(' ') << setw(20) << "Sebesar " << topUp[2] << endl;
        cout << endl
             << endl;
        saldo += 20000;
        cout << "\tSaldo saat ini\t: " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 4:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "TOPUP SUCCESSED" << endl;
        cout << setfill(' ') << setw(20) << "Sebesar " << topUp[3] << endl;
        cout << endl
             << endl;
        saldo += 25000;
        cout << "\tSaldo saat ini\t: " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 5:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "TOPUP SUCCESSED" << endl;
        cout << setfill(' ') << setw(20) << "Sebesar " << topUp[4] << endl;
        cout << endl
             << endl;
        saldo += 50000;
        cout << "\tSaldo saat ini\t: " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    case 6:
        system("cls");
        cout << setfill('=') << setw(40) << "=" << endl;
        cout << setfill(' ') << setw(13) << " " << "TOPUP SUCCESSED" << endl;
        cout << setfill(' ') << setw(20) << "Sebesar " << topUp[5] << endl;
        cout << endl
             << endl;
        saldo += 100000;
        cout << "\tSaldo saat ini\t: " << saldo << endl;
        cout << setfill('=') << setw(40) << "=" << endl;
        break;

    default:
        system("cls");
        cout << "salah blog" << endl;
        system("pause");
        tambahSaldo();
        break;
    }

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
        cout << "masukin yg bener blog" << endl;
        system("pause");
        tambahSaldo();
    }
}

void menuKantin()
{
    system("cls");
    // kantin1
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << kantin[0] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << kantin1[i].namaMkn << " " << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl
         << endl;
    // kantin2
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << kantin[1] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << kantin1[i].namaMkn << " " << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl
         << endl;
    // kantin3
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << kantin[2] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << kantin1[i].namaMkn << " " << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl
         << endl;
    // kantin4
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << kantin[3] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << kantin1[i].namaMkn << " " << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl
    << endl;
    // kantin5
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << kantin[4] << endl;
    cout << setfill('=') << setw(40) << "=" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << kantin1[i].namaMkn << " " << endl;
    }
    cout << setfill('=') << setw(40) << "=" << endl;
}


void exit(){
    system("cls");
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ') << setw(10) << "ANDA DIKELUARKAN" << endl; // PAKE B ING
    cout << setfill('=') << setw(40) << "=" << endl;
    exit(0);
    
}