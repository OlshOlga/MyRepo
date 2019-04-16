/*Программа для вычисления суммы положительных членов последовательности
 * Язык программирования: С++
 * Автор: О.И. Ольшевская
*/
#include <iostream>
using namespace std;
int main()
{
	int x, s=0;
	do {
		cout << "Введите x: ";
		cin >> x;
		if (x > 0) {
			s = s+x;
		}
	} while (x!=0);
	cout << "sum = " << s << endl;
	return 0;
}
