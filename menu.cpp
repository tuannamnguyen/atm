#pragma warning(disable : 4996)
#include<iostream>
#include<map>
#include<chrono>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;
int guiTien(map<int, int>& soTo, int loai[])
{
	int menh_gia, so;
	cout << "Cac menh gia tien hop le: 10000, 20000, 50000, 100000, 200000, 500000" << endl;
	bool to_continue = 1;
	int c = 0; //tong so tien da gui vao
	while (to_continue == true)
	{
		cout << "Nhap menh gia ban muon gui: ";
		do
		{
			cin >> menh_gia;
			if (menh_gia != 10000 && menh_gia != 20000 && menh_gia != 50000 && menh_gia != 100000 && menh_gia != 200000 && menh_gia != 500000) cout << "Menh gia khong hop le. Xin vui long chon menh gia khac: ";
		} while (menh_gia != 10000 && menh_gia != 20000 && menh_gia != 50000 && menh_gia != 100000 && menh_gia != 200000 && menh_gia != 500000);

		cout << "Nhap so luong to ban muon gui: ";
		cin >> so;
		soTo[menh_gia] += so;

		c += menh_gia * so;
		cout << "Ban da gui vao " << menh_gia * so << endl;

		ofstream history_out("history.txt", ios::app);
		auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); // get current time
		history_out << "Ban da gui " << menh_gia * so << " vao " << ctime(&timenow) << endl;

		cout << "Ban co muon tiep tuc gui tien khong? Nhan 1 neu muon tiep tuc. Nhan 0 neu muon thoat. ";
		cin >> to_continue;
		cout << "\n\n";
	}
	return c;
}
int rutTien(map<int, int>& soTo, int loai[], unsigned long long int balance)
{

	bool to_continue = 1;
	int c = 0; // tong so tien sau cac lan rut
	while (to_continue)
	{

		bool check = false;
		for (int i = 0; i < 6; i++)
		{
			if (soTo[loai[i]] != 0)
			{
				check = true;
				break;
			}
		}

		if (check == false)
		{
			cout << "May chua co tien. Vui long gui tien vao. ";
			return 0;
		}


		cout << "So tien muon rut phai la boi cua 10000." << endl;
		int withdraw;
		cout << "Vui long nhap so tien muon rut: ";
		while (cin >> withdraw)
		{
			if (balance <= 0)
			{
				cout << "Tai khoan cua ban khong con tien. Xin vui long gui tien vao. " << endl;
				return 0;
			}
			if (withdraw > balance) cout << "So tien ban muon rut lon hon so du cua ban. Xin vui long chon so tien khac. ";
			else if (withdraw % 10000 != 0) cout << "So tien ban nhap khong phai boi cua 10000. Xin vui long nhap lai. ";
			else break;
		}


		balance -= withdraw;
		map<int, int> out;
		for (int i = 0; i < 6; i++)
		{
			int t = withdraw / loai[i]; //so to se lay ra cua menh gia loai[i]
			if (t > soTo[loai[i]]) t = soTo[loai[i]];
			out[loai[i]] = t;
			soTo[loai[i]] -= t;
			withdraw = withdraw - t * loai[i];
			c += t * loai[i];
		}
		if (withdraw != 0)
		{
			cout << "Giao dich khong thanh cong. May khong du tien de tra cho ban." << endl;
			return 0;
		}

		ofstream history_out("history.txt", ios::app);
		auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); // get current time
		history_out << "Ban da rut " << c << " vao " << ctime(&timenow) << endl;

		for (int i = 0; i < 6; i++)
		{
			if (out[loai[i]] == 0) continue;
			else cout << "Ban da nhan duoc " << out[loai[i]] << " to " << loai[i] << endl;
		}
		cout << "Ban co muon tiep tuc rut tien khong? Nhan 1 neu muon tiep tuc. Nhan 0 neu muon thoat. ";
		cin >> to_continue;
		cout << "\n\n";

	}
	return c;
}
void vanTin(const unsigned long long int& balance)
{
	ifstream history_in("history.txt");

	if (balance == 0) cout << "Tai khoan cua ban hien khong co tien." << endl;
	else
	{
		string history;
		cout << "Tai khoan cua ban con: " << balance << endl;
		while (getline(history_in, history)) cout << history << endl;
	}

}