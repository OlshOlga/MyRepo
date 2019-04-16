/* Функция для зашифрования методом Цезаря
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

wstring encrypt(const wstring& text,const int key)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);

	wstring wtext;
	wtext = text;
	wstring arr = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

	for (int i=0; i<text.size(); i++) {
		if (!isalpha(wtext[i],loc)) {
			wtext = wtext.erase(i,1);
			continue;
		}
		wtext[i] = toupper(wtext[i],loc);
	}

	for (int i=0; i<wtext.size(); i++)
		for (int j = 0; j < 33; j++) {
			if (wtext[i] == arr[j]) {
				if (j+key > 32) {
					wtext[i] = arr[j + key - 33];
				} else
					wtext[i] = arr[j + key];
				break;
			}
		}

	return wtext;
}


int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);

	wstring ws;
	int key;
	wcout << L"Введите текст: " << endl;
	wcin >> ws ;
	wcout << L"Введите ключ: " << endl;
	wcin >> key;
	ws = encrypt(ws,key);
	wcout << ws << endl;


	return 0;
}
