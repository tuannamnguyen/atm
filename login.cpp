#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void createAcc()
{
	ofstream id_out("id.txt", ios::app);
	ofstream pass_out("pass.txt", ios::app);

	string id, pass;
	cout << "Xin vui long nhap so ID mong muon: ";
	cin >> id;
	id_out << id << endl;
	cout << endl;

	cout << "Xin vui long nhap mat khau mong muon: ";
	cin >> pass;
	pass_out << pass << endl;
	cout << endl;
}
bool login()
{
	string id, id_from_file;
	string pass, pass_from_file;
	bool id_invalid = true;
	bool pass_invalid = true;

	ifstream id_fin("id.txt");
	ifstream pass_fin("pass.txt");
	vector<string> _id;
	map<string, string> pass_data;
	while (id_fin >> id_from_file)
	{
		_id.push_back(id_from_file);
		pass_fin >> pass_from_file;
		pass_data[id_from_file] = pass_from_file;
	}



	while (id_invalid)
	{
		cout << "Vui long nhap ID cua ban: ";
		cin >> id;
		if (find(_id.begin(), _id.end(), id) != _id.end()) id_invalid = false;
		else cout << "So ID khong hop le. Xin vui long thu lai." << endl;
	}

	int c = 0;
	while (pass_invalid)
	{
		cout << "Vui long nhap mat khau cua ban: ";
		cin >> pass;
		if (pass_data[id] == pass) pass_invalid = false;
		else
		{
			c++;
			if (c == 5)
			{
				cout << "Qua so lan nhap cho phep. The da bi khoa." << endl;
				return false;
			}
			cout << "Ban da nhap sai mat khau. Xin vui long thu lai. Ban con " << 5 - c << " lan thu." << endl;
		}
	}
	return true;
	
}