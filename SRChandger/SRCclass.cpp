#include "SRCclass.h"

void SampleRateChandger::read (ifstream & file) // чтение файла
{
	file.read ((char*)&header, sizeof header);
	char r[4] = {'R','I','F','F'};
	char w[4] = {'W','A','V','E'};
	char f[4] = {'f','m','t',' '};
	char d[4] = {'d','a','t','a'};
	for (int i=0; i < 4; i++) {
		if (header.rID[i] != r[i])
			throw ErrorWav("Не RIFF формат");
		if (header.wID[i] != w[i])
			throw ErrorWav("Не WAVE формат");
		if (header.Fmt[i] != f[i])
			throw ErrorWav("Не fmt формат");
		if (header.dID[i] != d[i])
			throw ErrorWav("Не data формат");
	}
	if (header.Channels != 1)
		throw ErrorWav("Звук не одноканальный");
	if (header.SamplesPerSecond != 8000 && header.SamplesPerSecond != 16000 && header.SamplesPerSecond != 32000)
		throw ErrorWav("Недопустимая частота дискретизации");
	if (header.BitsPerSample != 16)
		throw ErrorWav("Недопустимая битность звука");

	int num_samples = header.dLen * 8 / header.BitsPerSample;
	if (num_samples % 2 != 0 ) { // если кол-во отсчетов нечетное, последний отбрасывается  
		num_samples = num_samples - 1;
		header.rLen = header.rLen - 2;
		header.dLen = header.dLen - 2;
	}
	value = new int16_t [num_samples];
	for (int i=0; i < num_samples; i++)
		file.read((char*)&value[i], 2);
}


void SampleRateChandger::decrease () // уменьшение кол-ва отсчетов в 2 раза
{
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	SampleRateChandger ret; // временный объект
	ret.value = new int16_t [num_samples/2]; 
	int j=0;
	for (int i=0; i < num_samples; i++)
		if (i%2 == 0) { // в новый массив записываются только стоящие на четных позициях сэмплы
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

void SampleRateChandger::increase () // увеличение кол-ва отсчетов в 2 раза
{
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	SampleRateChandger ret; // временный объект
	ret.value = new int16_t [num_samples*2-1];
	int i=0;
	for (int j=0; j < num_samples*2-1; j++) {
		if (j%2 == 0) { // старые сэмплы добавляются на четные позиции нового буфера
			ret.value[j] = value[i];
		} else { // на нечетных позициях нового буфера сэмплы добавляются с помощью линейной интерполяции
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


void SampleRateChandger::write (ofstream & file) // запись в файл
{
	file.write ((char*)&header, sizeof header);
	int num_samples = header.dLen * 8 / header.BitsPerSample;
	for (int i=0; i < num_samples; i++)
		file.write((char*)&value[i], 2);
	delete[] value;
}

int16_t * SampleRateChandger::getValueAdres () // возвращает указатель на массив сэмплов
{
	return value;
}
WavHeader * SampleRateChandger::getHeaderAdres () // возвращает указатель на WavHeader
{
	struct WavHeader * p;
	p = &header;
	return p;
}
