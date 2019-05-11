/*Программа для записи содержимого файла в конец другого файла
 *Язык программирования: С++
 *Автор: Ольшевская О.И., гр.18ПИ1
*/ 
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string s;
	cout << "Введите путь к файлу: ";
	cin >> s;
	ifstream f(s, ios::in);
	f.seekg(0,ios::end);
	int fsize = f.tellg();
	f.seekg(0,ios::beg);
	char* buf = new char[fsize];
	f.read(buf,fsize);
	f.close();
	cout << "Введите путь к файлу: ";
	cin >> s;
	ofstream fs(s, ios::app);
	fs.write(buf,fsize);
	fs.close();
	delete[] buf; 
	return 0;
}
