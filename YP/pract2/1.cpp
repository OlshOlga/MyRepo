/*Программа для вывода текущего времени на русском языке
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1 
 * */
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
	std::locale loc("ru_RU.UTF-8");
	std::locale::global(loc);
	time_t t = time(NULL);
	tm * ptm;
	ptm = localtime(&t);
	char buf[80];
	strftime(buf, 80, "%c", ptm);
	cout << buf << endl;
	return 0;
}
