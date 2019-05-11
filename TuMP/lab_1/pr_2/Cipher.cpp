/*Модуль шифра табличной перестановки
 *Язык программирования: С++
 *Автор: Ольшевская О.И., гр. 18ПИ1*/
#include "Cipher.h"

Cipher::Cipher(int key, const string& s)
{
	n = key;
	m = ((s.size() - 1)/n + 1);
	value = new char * [m];
	for (int i = 0; i < m; i++) {
		value[i] = new char [n];
	}
}
string Cipher::encrypt(const string& open_text)
{
//заполнение таблицы " "
	for (int i=0; i < m; i++)
		for (int j=0; j < n; j++)
			value[i][j] = '*';
//заполнение таблицы текстом
	for (int i = 0; i < open_text.size(); i ++)
		value[i/n][i%n] = open_text[i];
//вывод таблицы в строку
	string cipher_text;
	for (int i = n - 1; i >= 0; i --)
		for (int j = 0; j < m; j++)
			cipher_text = cipher_text + value[j][i];
	return cipher_text;
}
string Cipher::decrypt(const string& cipher_text)
{
//заполнение таблицы "*"
	for (int i=0; i < m; i++)
		for (int j=0; j < n; j++)
			value[i][j] = '*';
//заполнение таблицы текстом
	for (int i = 0; i < cipher_text.size(); i ++)
		value[i%m][i/m] = cipher_text[i];
//вывод таблицы в строку
	string open_text;
	for (int i = 0; i < m; i ++)
		for (int j = n - 1; j >= 0; j--)
			open_text = open_text + value[i][j];
	return open_text;
}

Cipher::~Cipher()
{
	for (int i = 0; i < m; i++) {
		delete [] value[i];
	}
	delete [] value;
}
