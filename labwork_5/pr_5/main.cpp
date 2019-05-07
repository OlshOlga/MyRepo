/*Программа для записи в файл чисел, обратных числам другого файла
 *Язык программирования: С++
 *Автор: Ольшевская О.И., гр.18ПИ1
*/ 
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ifstream f("1.bin", ios::in | ios::binary);
	f.seekg(0,ios::end);
	int fsize = f.tellg()/sizeof(double);
	f.seekg(0,ios::beg);
	double* buf = new double[fsize];
	for (int i=0; i < fsize; i++)
		f.read((char*)&buf[i], sizeof(double));
	f.close();
	float * bufl = new float[fsize];
	for (int i=0; i < fsize; i++)
		bufl[i] = 1/buf[i];
	delete [] buf;
	ofstream fs("2.bin",ios::out | ios::binary);
	for (int i=0; i < fsize; i++)
		fs.write((char*)&bufl[i], sizeof(float));
	fs.close();
	delete [] bufl;
	return 0;
}
