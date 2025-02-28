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