/*Программа, заменяющая слово mephi на слово yandex
 * Язык программирования: С++
 * Автор: Ольшевская О.И, гр. 18ПИ1 */

#include <iostream>
#include <string>

int main()
{
	int i;
	std::string  s[8];
	std::cout << "Введите текст: " << std::endl ;
	for (i=0; i<8; i++) {
		getline(std::cin,s[i]);
	}
	std::cout << "Преобразованный текст: " << std::endl ;
	for (i=0; i<8; i++) {
		if (s[i].find("mephi")!= std::string::npos) {
			s[i].replace(s[i].find("mephi"),5,"yandex");
		}
		std::cout << s[i] << std::endl;
	}
	return 0;
}
