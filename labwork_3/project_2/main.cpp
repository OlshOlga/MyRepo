/*Программа, заменяющая слово mephi на слово yandex
 * Язык программирования: С++
 * Автор: Ольшевская О.И, гр. 18ПИ1 */

#include <iostream>
#include <string>

int main()
{
	int i;
	std::string  s[] = {"deb http://mirror.mephi.ru/debian/ stretch main contrib non-free", "deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free", "deb http://security.debian.org/ stretch/updates main contrib non-free","deb-src http://security.debian.org/ stretch/updates main contrib non-free","deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free","deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free","deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free", "deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free"};
	for (i=0; i < 8; i++) {
		if (s[i].find("mephi")!= std::string::npos) {
			s[i].replace(s[i].find("mephi"),5,"yandex");
		}
		std::cout << s[i] << std::endl;
	}
	return 0;
}
