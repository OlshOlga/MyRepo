/*Программа для форматированного вывода чисел
 *Язык программирования: С++
 *Автор: Ольшевская О.И., гр.18ПИ1
*/ 
#include <iostream>
using namespace std;

int main()
{
	int arr[10];
	for (int i=0; i<10; i++)
		cin >> arr[i];
	for (int i=0; i< 10; i++)
		cout << oct << arr[i] << '\t' << dec << arr[i] << '\t' << hex << arr[i] << endl;
	return 0;
}
