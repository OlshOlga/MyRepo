#include <iostream>
#include <fstream>
#include <string>
#include "SRCclass.h"
using namespace std;

int main()
{

	string s;
	cout << "Ведите путь к изменяемому файлу: ";
	cin >> s;
	//открытие файла
	ifstream f(s, ios::binary);
	if(!f.is_open()) {
		cout << "Файл не был открыт\n";
		return 1;
	}

	cout << "Введите путь к создаваемому файлу: ";
	cin >> s;
	ofstream fs(s, ios::out | ios::binary);
	if(!fs.is_open()) {
		cout << "Файл не был открыт\n";
		return 1;
	}

	SampleRateChandger(samples);
	int answ;
	struct WavHeader *p;
	p = samples.getHeaderAdres();
	
	try {
		samples.read(f);
	} catch (ErrorWav & msg) {
		cerr << msg.getError() << endl;
		return 1;
	}
	f.close();


	if (p->SamplesPerSecond == 8000) {
		cout << "ЧД: 8 кГц. Возможно только увеличение.\n" << "Вы хотите увеличить ЧД?\n" << "Да: 0\t" << "Нет: 1\n";
		cin >> answ;
		if (answ == 0)
			samples.increase();
	} else if (p->SamplesPerSecond == 32000) {
		cout << "ЧД: 32 кГц. Возможно только уменьшение.\n" << "Вы хотите уменьшить ЧД?\n" << "Да: 0\t" << "Нет: 1\n";
		cin >> answ;
		if (answ == 0)
			samples.decrease();
	} else {
		cout << "ЧД: 16 кГц.\n" << "Вы хотите уменьшить или увеличить ЧД?\n" << "Уменьшить: 0\t" << "Увеличить: 1\n";
		cin >> answ;
		if (answ == 0)
			samples.decrease();
		else samples.increase();
	}

	samples.write (fs);

	fs.close();


	return 0;
}
