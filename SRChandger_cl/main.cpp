#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
using namespace std;

#pragma pack (1)

struct WavHeader {

	char rID[4] = {0}; // "RIFF"
	uint32_t rLen; // длина файла без этого заголовка
	char wID[4] = {0}; // "WAVE" - заголовок WAV
	char Fmt[4] = {0}; // "fmt " - thunk формата
	uint32_t Len; // длинна этого thunka
	uint16_t Format; // формат
	uint16_t Channels; // число каналов (1)
	uint32_t SamplesPerSecond; // отсчетов/сек
	uint32_t AvgBytesPerSecond; // байтов/сек
	uint16_t BlockAlign; // выравнивание блоков
	uint16_t BitsPerSample; // битов на отсчет
	char dID[4] = {0}; // "data"
	uint32_t dLen; // длина этого thunkа
};

class SampleRateChandger
{
protected:
	int16_t * value;
	WavHeader header;
public:
	int read (ifstream & file);
	void ErrorWav ();		
	void decrease ();
	void increase ();
	void write (ofstream & file);
};

int SampleRateChandger::read (ifstream & file)
{
	file.read ((char*)&header, sizeof header);
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	if (num_samples % 2 != 0 ) {
		num_samples = num_samples - 1;
		header.rLen = header.rLen - 2;
		header.dLen = header.dLen - 2;
	}
	value = new int16_t [num_samples];
	for (int i=0; i < num_samples; i++)
		file.read((char*)&value[i], 2);
	return header.SamplesPerSecond;
}

void SampleRateChandger::ErrorWav ()
{
	char r[4] = {'R','I','F','F'};
	char w[4] = {'W','A','V','E'};
	char f[4] = {'f','m','t',' '};
	char d[4] = {'d','a','t','a'};
	for (int i=0; i < 4; i++) {
		if (header.rID[i] != r[i])
			throw "Не RIFF формат";
		if (header.wID[i] != w[i])
			throw "Не WAVE формат";
		if (header.Fmt[i] != f[i])
			throw "Не fmt формат";
		if (header.dID[i] != d[i])
			throw "Не data формат";
	}
	if (header.Format != 1)
		throw "Не PCM формат";
	if (header.Channels != 1)
		throw "Звук не одноканальный";
	if (header.SamplesPerSecond != 8000 && header.SamplesPerSecond != 16000 && header.SamplesPerSecond != 32000)
		throw "Недопустимая частота дискретизации";
	if (header.BitsPerSample != 16)
		throw "Недопустимая битность звука";
}

void SampleRateChandger::decrease ()
{
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	SampleRateChandger ret;
	ret.value = new int16_t [num_samples/2];
	int j=0;
	for (int i=0; i < num_samples; i++)
		if (i%2 == 0) {
			ret.value[j] = value[i];
			j++;
		}
	delete[] value;
	value = new int16_t [num_samples/2];
	for (int i = 0; i < num_samples/2; i++)
		value[i] = ret.value[i];
	delete[] ret.value;
	header.rLen = header.rLen - header.dLen/2;
	header.SamplesPerSecond = header.SamplesPerSecond/2;
	header.dLen = header.dLen/2;
}

void SampleRateChandger::increase ()
{
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	SampleRateChandger ret;
	ret.value = new int16_t [num_samples*2-1];
	int i=0;
	for (int j=0; j < num_samples*2-1; j++) {
		if (j%2 == 0) {
			ret.value[j] = value[i];
		} else {
			ret.value[j] = (value[i]+value[i+1])/2;
			i++;
		}
	}
	delete[] value;
	value = new int16_t [num_samples*2-1];
	for (int i = 0; i < num_samples*2-1; i++)
		value[i] = ret.value[i];
	delete[] ret.value;
	header.rLen = header.rLen + header.dLen - 2;
	header.SamplesPerSecond = header.SamplesPerSecond*2;
	header.dLen = header.dLen*2 - 2;
}


void SampleRateChandger::write (ofstream & file)
{
	file.write ((char*)&header, sizeof    header);
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	for (int i=0; i < num_samples; i++)
		file.write((char*)&value[i], 2);
	delete[] value;
}

int main()
{

	string s;
	cout << "Ведите путь к изменяемому файлу: ";
	cin >> s;
	//открытие файла
	ifstream f(s, ios::binary);
	if(!f.is_open()) {
		cout << "Файл не был открыт";
		return 1;
	}
	SampleRateChandger samples;
	int SR, answ;
	SR = samples.read(f);
	try {
		samples.ErrorWav();
	} catch (const char* msg) {
		cerr << msg << endl;
		return 1;
	}
	f.close();

	if (SR == 8000) {
		cout << "ЧД: 8 кГц. Возможно только увеличение.\n" << "Вы хотите увеличить ЧД?\n" << "Да: 0\t" << "Нет: 1\n";
		cin >> answ;
		if (answ == 0)
			samples.increase();
	} else if (SR == 32000) {
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

	cout << "Введите путь к создаваемому файлу: ";
	cin >> s;
	ofstream fs(s, ios::out | ios::binary);
	samples.write (fs);

	fs.close();


	return 0;
}
