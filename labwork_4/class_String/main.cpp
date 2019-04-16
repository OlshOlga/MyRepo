/*Класс String с конструкторами по умолчанию, копирования, деструктором, перегруженным оператором для вывода строки в поток
 * Язык программирования: С++
 * Автор: Ольшевская О.И. гр. 18ПИ1*/
#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char * value;
	int len;
public:
	String():value(new char[1] {}),len(0) {}; // конструктор по умолчанию
	String(const String& s) { // конструктор копирования
		len=s.len;
		value = new char[len+1];
		for (int i=0; i<=len; i++)
			value[i]=s.value[i];
	}
	String(const char * s) {
		len=strlen(s);
		value = new char[len+1];
		for(int i =0; i<len; i++)
			value[i]=s[i];
		value[len] = 0;
	}
	~String() {
		delete[] value;
		cout << "Деструктор сработал" << endl;
	}
	friend ostream& operator<< (ostream& o, const String & s);
	friend istream& operator>> (istream& o, String & s);
	String& operator=(const String& other);
	String operator-() const;
	String operator+(const String& other);
};

ostream& operator<< (ostream& outputStream, const String & s)
{
	return outputStream << s.value;
}

istream& operator>> (istream& inputStream, String & s)
{
	char tmp[80];
	for (int i=0; s.value[i] != 0; i++)
		tmp[i] = s.value[i];
	delete[] s.value;
	s.len = strlen(tmp);
	s.value = new char [s.len + 1];
	for (int i=0; i<s.len; i++)
		s.value[i] = tmp[i];
	s.value[s.len] = 0;
	return inputStream >> s.value;
}

String& String::operator=(const String& other)
{
	if (this != &other) {
// игнорировать присваивания вида a = a
		delete[] value;
// удаляем старое значение
		len=other.len;
// длина строки
		value = new char[len+1];     // выделить память под новый буфер
		for (int i=0; i<=len; i++) { // скопировать строку в новый буфер
			value[i]=other.value[i];
		}
	}
	return *this;
}


String String::operator-() const
{
	String ret;
//временный объект
	ret.len = len;
//длина строки
	delete[] ret.value;
//освободить старый буфер
	ret.value = new char[len+1];
//буфер под строку
	for (int i=0; i<len; i++) {
//копируем в обратном порядке
		ret.value[i] = value[len-i-1];
	}
	ret.value[len] = 0;
//нулевое окончание строки
	return ret;
//возвращаем временный объект
}

String String::operator+(const String& other)
{
	String newS;
	int thislen = strlen(value);
	int otherlen = strlen(other.value);
	newS.len = thislen+otherlen;
	newS.value = new char [thislen+otherlen+1];
	int i;
	for (i=0; i<thislen; i++)
		newS.value[i] = value[i];
	for (int j=0; j<otherlen; j++) {
		newS.value[i]=other.value[j];
		i++;
	}
	newS.value[thislen+otherlen] = 0;
	return newS;
}

int main ()
{
	String s1, s4;
	cin >> s1;
	String s2("hello");	
	String s3(s1);
	cout << s3 << endl;
	s4 = s1+s2;
	cout << -s4 << endl;
	return 0;
}
