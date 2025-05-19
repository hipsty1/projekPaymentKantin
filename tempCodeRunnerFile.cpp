 cin >> pilihan;
    cout << "| No  | Nama Menu                     | Harga    |" << endl;
    switch (pilihan) {
        case 1: {
            ifstream menuFile("menu.txt");
            if (menuFile.is_open()) {
                string menuLine;
                int idx = 1;
                while (getline(menuFile, menuLine)) {
                    if (idx >= 2 && idx <= 10) {
                        cout << menuLine << endl;
                    }
                    if (idx > 10) break;
                    idx++;
                }
                cout << "Pilih menu (2-10): "; cin >> indexMenu;
                cout << "Jumlah beli: "; cin >> jumlahBeli;
                perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
                menuFile.close();
            } else {
                cout << "Gagal membuka file menu.txt!" << endl;
            }
            break;
        }
        case 2: {
            ifstream menuFile("menu.txt");
            if (menuFile.is_open()) {
                string menuLine;
                int idx = 1;
                while (getline(menuFile, menuLine)) {
                    if (idx >= 12 && idx <= 16) {
                        cout << menuLine << endl;
                    }
                    if (idx > 16) break;
                    idx++;
                }
                cout << "Pilih menu (12-16): "; cin >> indexMenu;
                cout << "Jumlah beli: "; cin >> jumlahBeli;
                perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
                menuFile.close();
            } else {
                cout << "Gagal membuka file menu.txt!" << endl;
            }
            break;
        }
        case 3: {
            ifstream menuFile("menu.txt");
            if (menuFile.is_open()) {
                string menuLine;
                int idx = 1;
                while (getline(menuFile, menuLine)) {
                    if (idx >= 18 && idx <= 24) {
                        cout << menuLine << endl;
                    }
                    if (idx > 24) break;
                    idx++;
                }
                cout << "Pilih menu (18-24): "; cin >> indexMenu;
                cout << "Jumlah beli: "; cin >> jumlahBeli;
                perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
                menuFile.close();
            } else {
                cout << "Gagal membuka file menu.txt!" << endl;
            }
            break;
        }
        case 4: {
            ifstream menuFile("menu.txt");
            if (menuFile.is_open()) {
                string menuLine;
                int idx = 1;
                while (getline(menuFile, menuLine)) {
                    if (idx >= 26 && idx <= 31) {
                        cout << menuLine << endl;
                    }
                    if (idx > 31) break;
                    idx++;
                }
                cout << "Pilih menu (26-31): "; cin >> indexMenu;
                cout << "Jumlah beli: "; cin >> jumlahBeli;
                perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
                menuFile.close();
            } else {
                cout << "Gagal membuka file menu.txt!" << endl;
            }
            break;
        }
        case 5: {
            ifstream menuFile("menu.txt");
            if (menuFile.is_open()) {
                string menuLine;
                int idx = 1;
                while (getline(menuFile, menuLine)) {
                    if (idx >= 33 && idx <= 38) {
                        cout << menuLine << endl;
                    }
                    if (idx > 38) break;
                    idx++;
                }
                cout << "Pilih menu (33-38): "; cin >> indexMenu;
                cout << "Jumlah beli: "; cin >> jumlahBeli;
                perhitunganHarga(username, saldo, indexMenu, jumlahBeli);
                menuFile.close();
            } else {
                cout << "Gagal membuka file menu.txt!" << endl;
            }
            break;
        }
        default: {
            cout << "Pilihan tidak valid!" << endl;
