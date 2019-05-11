/*Программа с функцией для нормировки значений в новом массиве чисел с плавающей точкой от 0 до 1
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1
*/
#include <iostream>
#include <limits>

using namespace std;

double * norm (int const size, double * mas)
{
	double max = numeric_limits<double>::min(), min = numeric_limits<double>::max();
	double * nmas = new double [size];

	for (int i=0; i<size; i++) {
		nmas[i]=mas[i];
		if (max < nmas[i])
			max = nmas[i];
		else if (min > nmas[i])
			min = nmas[i];
	}

	for (int i=size - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (nmas[j] > nmas[j + 1]) {
				double t = nmas[j];
				nmas[j] = nmas[j + 1];
				nmas[j + 1] = t;
			}
		}
	for (int i=0; i<size; i++) {
		nmas[i]=(nmas[i]- min)/(max-min);
	}

	return nmas;
}

void del(double * mas)
{
	delete[] mas;
}

int main()
{
	int size;
	double * p;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	double * mas = new double [size];
	cout << "Заполните массив: " << endl;
	for (int i=0; i<size; i++)
		cin >> mas[i];
	p = norm(size, mas);
	for (int i=0; i<size; i++)
		cout << *(p + i) << " ";
	del(p);
	delete[] mas;
	return 0;

}
