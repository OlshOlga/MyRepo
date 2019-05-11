/*Программа с функцией для нормировки значений массива чисел с плавающей точкой от 0 до 1
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1
*/
#include <iostream>
#include <limits>

using namespace std;

void norm (int const size, double * mas)
{
	double max = numeric_limits<double>::min(), min = numeric_limits<double>::max();
	for (int i=0; i<size; i++) {

		if (max < mas[i])
			max = mas[i];
		else if (min > mas[i])
			min = mas[i];
	}
	for (int i=size - 1; i>=1; i--)
		for (int j = 0; j<i; j++) {
			if (mas[j] > mas[j + 1]) {
				double t = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = t;
			}
		}
	for (int i=0; i<size; i++) {
		mas[i]=(mas[i]- min)/(max-min);
	}
}



int main()
{
	int size;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	double * mas = new double [size];
	cout << "Заполните массив: " << endl;
	for (int i=0; i<size; i++)
		cin >> mas[i];
	norm (size, mas);
	for (int i=0; i<size; i++) {
		cout << mas[i] << " ";
	}
	delete[] mas;
	return 0;

}
