/*Функция для вывода таблицы умножения в восьмиричной,
 *десятичной, шестнадцатеричной СС
 *Язык программирования: С++
 *Автор: Ольшевская О.И., гр.18ПИ1
*/
#include <iostream>
#include <iomanip>
using namespace std;

void tbl(int osn)
{

	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	if (osn == 16)
		for (int i = 0 ; i< 15; i++) {
			for (int j = 0; j<15; j++)
				cout << setw(5) << hex << arr[i]*arr[j];
			cout << endl;
		}
	else if (osn == 8)
		for (int i = 0 ; i< 7; i++) {
			for (int j = 0; j<7; j++)
				cout << setw(5) << oct << arr[i]*arr[j];
			cout << endl;
		}

	else for (int i = 0 ; i< 9; i++) {
			for (int j = 0; j<9; j++)
				cout << setw(5) << dec << arr[i]*arr[j];
			cout << endl;
		}

}

int main()
{
	int osn;
	cout << "Введите основание системы счисления\n";
	cin >> osn;
	if (osn != 16 && osn != 10 && osn != 8) {
		cout << "Неподдерживаемая система счисления!\n";
		return 1;
	}
	tbl(osn);
	return 0;
}
