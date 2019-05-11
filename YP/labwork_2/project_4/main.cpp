/* Программа для определения, является ли число простым
Язык программирования: С++
Автор: О.И. Ольшевская, гр. 18ПИ1
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, i=2;
	cout << "Введите x ";
	cin >> x;
	while (i <= sqrt(x)) {
		if (x%i==0 && i!=x) {
			cout << "Нет" << endl;
			i=0;
			break;
		}

		if (x%i!=0 || x%i==0 && x==i) {
			i++;
		}
	}
	if (i != 0) {
		cout << "Да" << endl;
	}
	return 0;

}
