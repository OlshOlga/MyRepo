/* Программа для нахождения среднего арифметического
   Яззык программирования: С++
   Автор: О.И. Ольшевская, гр. 18ПИ1
*/
#include <iostream>
using namespace std;
int main()
{
	int N, m;
	double s=0, x;
	cout << "Введите N: " ;
	cin >> N;
	m = N;
	while (m!=0) {
		cout << "Введите x: " ;
		cin >> x;
		s = s+x;
		m--;
	}
	x = s/N;
	cout << "x = " << x << endl;
	return 0;
}
