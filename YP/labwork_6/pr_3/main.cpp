/*Шаблонный класс DoubleBox
 *Язык программирования: С++
 *Автор: Ольшевская. О.И., гр. 18ПИ1*/
#include <iostream>
using namespace std;
template <typename T1,typename T2> class DoubleBox
{
private:
	T1 a = T1();
	T2 b = T2();
public:
	DoubleBox() {};
	DoubleBox(const T1 x, const T2 y):a(x),b(y) {};
	void set(const T1 x, const T2 y) {
		a = x;
		b = y;
	}
	void get(T1 &x, T2 &y) {
		x = a;
		y = b;
	}
};



int main(int argc, char **argv)
{
	int value_1;
	double value_2;
	DoubleBox <double,int> value(0.001,5);
	value.get(value_2,value_1);
	cout << value_1 << " " << value_2 << endl;
	value.set(34.9, 3);
	value.get(value_2,value_1);
	cout << value_1 << " " << value_2 << endl;
	return 0;
}

