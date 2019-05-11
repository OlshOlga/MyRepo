/*Программа для вычисления ср. арифметического для чисел из файла
 *Язык программирования: С++
 *Автор: Ольшевская О.И., гр.18ПИ1
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
	double sum = 0;
	double i = 0;
	string s;
	cout << "Введите путь к файлу: ";
	cin >> s;
	ifstream f(s, ios::in);
	while (!f.eof()) {
		double x = 0;
		f >> x;
		if (x != 0) {
			sum = sum + x;
			i++;
		}
	}
	cout << sum/i << endl;
	f.close();
	return 0;
}
