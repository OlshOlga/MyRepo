/*Шаблонный класс Array
 *Язык программирования: С++
 *Автор: Ольшевская. О.И., гр. 18ПИ1*/
#include <iostream>
using namespace std;

template <typename T, int size> class Array
{
	T arr[size];
public:
	Array() {};
	Array(T x) {
		for (int i =0; i < size; i++)
			arr[i] = x;
	}
	Array(T * buf, int buf_size) {
		for (int i =0; i < buf_size; i++)
			arr[i] = buf[i];
	}
	T & operator [](const int index) {
		return arr[index];
	}
};


int main ()
{
	double buf_1[5] = {2.1, 43.2, 0.008, 9, -100.1};
	Array <double,5> arr_1(buf_1, 5);
	cout << arr_1[0] << " " << arr_1[1] << " ";
	arr_1[0] = 0.89;
	arr_1[2] = buf_1[4]; 
	cout << "\nПроверка оператора []: ";
	for (int i = 0; i < 5; i++)
		cout << arr_1[i] << " ";
	Array <int,3> arr_2(5);
	arr_2[2] = 6;
	int buf_2[2] = {1, 76};
	arr_2[1]=buf_2[1];
	cout << "\nПроверка оператора []: ";
	for (int i = 0; i < 3; i++)
		cout << arr_2[i] << " ";

	return 0;
}
