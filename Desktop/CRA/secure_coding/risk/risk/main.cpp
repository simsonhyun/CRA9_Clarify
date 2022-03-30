#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
string name = "NO NAME";
string fileName;
void printStatus() {
	cout << "\n\n";
	cout << "=========================\n";
	cout << "   NAME : " << name << "\n";
	cout << "=========================\n";
	cout << "\n";
	cout << "1. Change Name\n";
	cout << "2. Save Name To File\n";
	cout << "3. Load Name To File\n";
	cout << "\n";
}
void saveName() {
	ofstream fout(fileName);
	fout << name;
	fout.close();
}
void loadName() {
	ifstream fin(fileName);
	if (fin.fail()) {
		cout << "ERROR :: THERE's NO FILE\n";
		return;
	}
	getline(fin, name);
	fin.close();
}
int isValid(string str) {
	if (str.find("\\") != -1) return 0;
	if (str.find("/") != -1) return 0;
	//�հ�
	return 1;
}
int main()
{
	while (1) {
		printStatus();
		int n;
		cout << "CMD : ";
		cin >> n;
		cin.ignore();
		if (n == 1) {
			cout << "NEW NAME : ";
			getline(cin, name);
		}
		else if (n == 2) {
			cout << "SAVE FILE NAME : ";
			cin >> fileName;
			if (isValid(fileName)) {
				if (fileName.length() >= 30) {
					cout << "LOAD.ERROR : ���� �̸��� 30���� �̻� �ɼ�����\n";
				}
				else {
					saveName();
				}
			}
			else {
				cout << "SAVE�õ�. ERROR :: File Name�� ��ȿ���� ���� ���� ����ֽ��ϴ�.";
			}
		}
		else if (n == 3) {
			cout << "LOAD FILE NAME : ";
			cin >> fileName;

			if (isValid(fileName)) {
				if (fileName.length() >= 30) {
					cout << "LOAD.ERROR : ���� �̸��� 30���� �̻� �ɼ�����\n";
				}
				else {
					loadName();
				}
			}
			else {
				cout << "Load�õ�. ERROR :: File Name�� ��ȿ���� ���� ���� ����ֽ��ϴ�.";
			}
		}
	}
	return 0;
}