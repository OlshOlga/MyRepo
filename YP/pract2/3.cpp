/*Программа для определения времени заполнения векторов
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1 
 * */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int RandomGenerator()
{
	static mt19937 rnd(122); //(uint64_t)&rnd);
	uniform_int_distribution<int> d(-1000000000,1000000000);
	return d(rnd);
}

int main(int argc, char **argv)
{
	vector <int> v1; //просто добавляет в конец рандомное число

	mt19937 rnd(123);
	uniform_int_distribution<int> roll(-1000000000,1000000000);
	steady_clock::time_point tp1 = steady_clock::now();
	for (int i=0; i < 10000000; i++)
		v1.push_back(roll(rnd));
	steady_clock::time_point tp2 = steady_clock::now();
	duration<double> d = tp2 - tp1;
	cout << "v1 time: " << d.count() << endl;
	tp1 = steady_clock::now();
	vector<int> v2(10000000); // с помощью генератора
	generate(v2.begin(),v2.end(),RandomGenerator);
	tp2 = steady_clock::now();
	d = tp2 - tp1;
	cout << "v2 time: " << d.count() << endl;
	tp2 = steady_clock::now();
	vector<int> v3(v2);
	d = tp2 - tp1;
	cout << "v3 time: " << d.count() << endl;
	return 0;
}