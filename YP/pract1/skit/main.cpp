/*Программа для зашифрования и расшифрования шифром Скитала
 * Язык программирования: С++
 * Автор: Ольшевская О.И.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string zashifr(int const key, string s) //ф-ция зашифрования
{
	string s1;

	for (int i =0; i < s.size(); i++) {
		if (!isalpha(s[i]) || !isupper(s[i])) {
			s1 = "Не корректный текст";
			return s1;
		} else if (key > (s.size()/2) || key < 0) {
			s1 = "Не корректный ключ";
			return s1;
		}
	}

	int n = ((s.size() - 1)/key + 1);
	char **skit = new char * [n];
	for (int i = 0; i < n; i++) {
		skit[i] = new char [key];
	}

	for (int i=0; i < n; i++)
		for (int j=0; j < key; j++)
			skit[i][j] = '*';

	for (int i = 0; i < s.size(); i++) {
		skit[i%n][i/n] = s[i];
	}

	for (int i=0; i < n; i++)
		for (int j=0; j < key; j++)
			s1 = s1 + skit[i][j] ;

	for (int i = 0; i < n; i++) {
		delete [] skit[i];
	}
	delete [] skit;

	return s1;
}

string rasshifr(int const key, string s) //ф-ция расшифрования
{
	string s1;

	for (int i =0; i < s.size(); i++) {
		if (!isalpha(s[i]) || !isupper(s[i])) {
			s1 = "Не корректный текст";
			return s1;
		} else if (key > (s.size()/2) || key < 0) {
			s1 = "Не корректный ключ";
			return s1;
		}
	}

	int n = ((s.size() - 1)/key + 1);

	char **skit = new char * [key];
	for (int i = 0; i < key; i++) {
		skit[i] = new char [n];
	}

	for (int i=0; i < key; i++)
		for (int j=0; j < n; j++)
			skit[i][j] = '*';

	for (int i = 0; i < s.size(); i++) {
		skit[i%key][i/key] = s[i];
	}

	for (int i=0; i < key; i++)
		for (int j=0; j < n; j++)
			s1 = s1 + skit[i][j];

	for (int i = 0; i < key; i++) {
		delete [] skit[i];
	}
	delete [] skit;

	return s1;
}

int main()
{
	string s;
	int key, ans;
	cout << "Введите текст: " << endl;
	getline(cin,s);
	cout << "Зашифровать: 0" << endl << "Расшифровать: 1" << endl;
	cin >> ans;
	cout << "Введите ключ: " << endl;
	cin >> key;
	if (ans == 0)
		cout << zashifr(key,s) << endl;
	else
		cout << rasshifr(key,s) << endl;

	return 0;
}
