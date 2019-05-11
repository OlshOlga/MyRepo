/*Шаблонная функция сортировки
 *Язык программирования: С++
 *Автор: Ольшевск4ая О.И., гр. 18ПИ1*/ 
#include <iostream>
using namespace std;

template <typename T> void sort (T * arr, int size) //cортировка по возрастанию
{
	for (int i=size - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (arr[j] > arr[j + 1]) {
				T t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
}

int main ()
{
	double b[] = {3.8, 67.09, 0.005};
	int a[] = {0, -8, 78, 10, -100, 1001, -1001};
	cout << "Массив до сортировки: ";
	for (int i = 0; i< 7; i++)
		cout<< a[i]<<" ";
	sort <int> (a, 7);
	cout << "\nМассив после сортировки: ";
	for (int i = 0; i < 7; i++)
		cout<< a[i]<<" ";
	cout << "\n----------\n";
	
	cout << "Массив до сортировки: ";
	for (int i = 0; i< 3; i++)
		cout<< b[i]<<" ";
	sort <double> (b, 3);
	cout << "\nМассив до сортировки: ";	
	for (int i = 0; i< 3; i++)
		cout<< b[i]<<" ";
	return 0;
}
