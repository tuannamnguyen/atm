#include <iostream>
using namespace std;
string id = "12345678";
string pass = "87654321";

bool login() {
    string id_in;
    string pass_in;
    bool id_invalid = true;
    bool pass_invalid = true;

    cout << "Xin chao!" << endl;

    while (id_invalid) {
        cout << "Vui long nhap ID cua ban: ";
        cin >> id_in;
        if (id_in == id)
            id_invalid = false;
        else
            cout << "So ID khong hop le. Xin vui long thu lai." << endl;
    }

    int c = 0;
    while (pass_invalid) {
        cout << "Vui long nhap mat khau cua ban: ";
        cin >> pass_in;
        if (pass_in == pass)
            pass_invalid = false;
        else {
            c++;
            if (c == 5) {
                cout << "Qua so lan nhap cho phep. The da bi khoa." << endl;
                return false;
            }
            cout << "Ban da nhap sai mat khau. Xin vui long thu lai. Ban con "
                 << 5 - c << " lan thu." << endl;
        }
    }
    return 1;
}
