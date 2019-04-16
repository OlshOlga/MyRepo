/*Программа для нахождения простых чисел в последовательности
 * Язык программирования: С++
 * Автор: О.И. Ольшевская, гр. 18ПИ1
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, i=2;

	do {
		cout << "Введите x ";
		cin >> x;

		while(i <= sqrt(x)) {
			if (x%i==0 && i!=x) {
				i=0;
				break;
			}

			if (x%i!=0 || x%i==0 && x==i) {
				i++;
			}
		}
		if (i!=0 && x!=0) {
			cout << "Простое " << endl;
		}
		i=2;



	} while (x!=0);

	return 0;
}
