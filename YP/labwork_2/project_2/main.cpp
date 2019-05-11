/*Программа для поиска заданного числа в последовательности чисел
 * Язык программирования: С++
 * Автор: О.И. Ольшевская, гр. 18ПИ1
*/
# include <iostream>
using namespace std;
int main()
{
	int x, y, i=0;
	cout << "Введите x: ";
	cin >> x;
	do {
		cout << "Введите y: ";
		cin >> y;
		if (x==y) {
			i++;
		}

	} while (y!=0);
	if (i!=0) {
		cout << "Найдено " << x << endl;
	} else {
		cout << "Не найдено " << endl;
	}
	return 0;
}
