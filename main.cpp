#include<iostream>
#include<map>
#include<fstream>
#include "menu.h"
#include "login.h"
using namespace std;
int main()
{
	int loai[] = { 500000, 200000, 100000, 50000, 20000, 10000 }, menh_gia, soto;
	map<int, int> soTo;
	ifstream fin("data.txt");
	while (fin >> menh_gia >> soto) soTo[menh_gia] = soto;

	

	if (login())
	{
		unsigned long long int balance = 0;
		ifstream balance_in("balance.txt");
		balance_in >> balance;

		cout << "=================MENU================\n";
		cout << "1. Gui tien\n";
		cout << "2. Rut tien\n";
		cout << "3. Van tin so du\n";
		cout << "4. Thoat\n";
		cout << "Xin vui long lua chon hanh dong muon thuc hien: ";

		int option;
		while (cin >> option)
		{
			cout << "\n\n";
			if (option == 1)
			{
				balance += guiTien(soTo, loai);
				cout << endl;
				cout << "1. Gui tien\n";
				cout << "2. Rut tien\n";
				cout << "3. Van tin so du\n";
				cout << "4. Thoat\n";
				cout << "Vui long thuc hien hanh dong muon lam tiep theo." << endl;
			}
			else if (option == 2)
			{
				balance -= rutTien(soTo, loai, balance);
				if (balance <= 0) balance = 0;
				cout << endl;
				cout << "1. Gui tien\n";
				cout << "2. Rut tien\n";
				cout << "3. Van tin so du\n";
				cout << "4. Thoat\n";
				cout << "Vui long thuc hien hanh dong muon lam tiep theo." << endl;
			}
			else if (option == 3)
			{
				vanTin(balance);
				cout << endl;
				cout << "1. Gui tien\n";
				cout << "2. Rut tien\n";
				cout << "3. Van tin so du\n";
				cout << "4. Thoat\n";
				cout << "Vui long thuc hien hanh dong muon lam tiep theo." << endl;
			}
			else if (option == 4)
			{
				ofstream fout("data.txt");
				for (int i = 0; i < 6; i++)
				{
					fout << loai[i] << " " << soTo[loai[i]] << endl;
				}

				ofstream balance_out("balance.txt");
				balance_out << balance;
				cout << "Xin cam on quy khach da su dung dich vu ATM!";
				return 0;
			}
				else cout << "Lua chon khong hop le. Xin vui long chon lai. ";
		}
	}
		else return 0;
	return -1;
}