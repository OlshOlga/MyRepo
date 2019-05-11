/* Программа для подсчта количества цифр, букв и прочих символов.
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{

	int i, j, l, len = 0, tz = 0, byk= 0, sim = 0;
	string  s[] = {"deb http://mirror.mephi.ru/debian/ stretch main contrib non-free", "deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free", "deb http://security.debian.org/ stretch/updates main contrib non-free","deb-src http://security.debian.org/ stretch/updates main contrib non-free","deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free","deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free","deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free", "deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free"};

	for (i=0; i < 8; i++) {
		l = s[i].size();
		for (j=0; j<l; j++) {
			if (isdigit(s[i][j])) {
				tz = tz +1;
			} else if (isalpha(s[i][j])) {
				byk = byk +1;
			} else if (ispunct(s[i][j])) {
				sim = sim +1;
			}
		}
		len = len + tz;
	}

	cout << "Длина текста: " << len << endl;
	cout << "Кол-во цифр: " << tz << endl;
	cout << "Кол-во букв: " << byk << endl;
	cout << "Кол-во символов: " << sim << endl;

	return 0;
}
