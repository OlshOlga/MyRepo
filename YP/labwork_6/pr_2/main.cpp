/*Класс Rectangle
 * Язык программирования: С++
 * Автор: Ольшевская. О.И., гр. 18ПИ1*/
#include <iostream>
using namespace std;

template <typename T> void sort (T * arr, int len)
{
	for (int i=len - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (arr[j] > arr[j + 1]) {
				T t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
}


template <typename T> class Rectangle
{
	T a = T();
	T b = T();
public:
	Rectangle() {};
	Rectangle(T x, T y) {
		a = x;
		b = y;
	}

	bool operator >(const Rectangle x) {
		return (a*b>x.a*x.b);

	}

	friend ostream& operator <<(ostream& outputStream, Rectangle x) {
		return outputStream << x.a*x.b;
	}
};



int main ()
{
	int x = 3, y = 2;
	double a = 6.65, b = 1.0877;
	Rectangle <int> arr[3];
	Rectangle <double> buf[3];
	for (int i=0; i< 3; i++) {
		Rectangle <int> r(x-i,y);
		arr[i] = r;
		Rectangle <double> f(a-i,b);
		buf[i] = f;
	}
	cout << "Массив до сортировки для значений 3 и 2: ";
	for (int i = 0; i< 3; i++)
		cout<< arr[i]<<" ";
	sort (arr, 3);
	cout << "\nМассив после сортировки: ";
	for (int i=0; i< 3; i++)
		cout << arr[i] << " ";
	cout << "\n----------\n";

	cout << "Массив до сортировки для значений 6.65 и 1.0877: ";
	for (int i = 0; i< 3; i++)
		cout<< buf[i]<<" ";
	sort (buf, 3);
	cout << "\nМассив после сортировки: ";
	for (int i = 0; i< 3; i++)
		cout<< buf[i]<<" ";

	return 0;
}
