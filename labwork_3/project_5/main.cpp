/* Функция для раcшифрования методом Цезаря
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

wstring decrypt(const wstring& text, const int key)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);

	wstring wtext;
	wtext = text;
	wstring arr = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	wstring arr2 = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";


	for (int i=0; i<text.size(); i++)
		if (!isalpha(wtext[i],loc)) {
			wtext = L"ОШИБКА";
			return wtext;
		}
	for (int i=0; i<wtext.size(); i++)
		for (int j = 0; j < 33; j++)

			if (isupper(wtext[i],loc)) {
				if (wtext[i] == arr[j]) {
					if (j-key < 0) {
						wtext[i] = arr[j - key + 33];
					} else
						wtext[i] = arr[j - key];
					break;
				}
			} else if (wtext[i] == arr2[j]) {
				if (j-key < 0) {
					wtext[i] = arr2[j - key + 33];
				} else
					wtext[i] = arr2[j - key];
				break;
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
	wcin >> ws;
	wcout << L"Введите ключ: " << endl;
	wcin >> key;
	wcout << decrypt(ws,key) << endl;

	return 0;
}
