/*Программа для заполнения 3х векторов
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1 
 * */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int RandomGenerator()
{
	static mt19937 rnd(122); //(uint64_t)&rnd);
	uniform_int_distribution<int> d(-1000000000,1000000000);
	return d(rnd);
}

int main(int argc, char **argv)
{
	vector <int> v1;
	vector<int> v2(10000000);

	mt19937 rnd(123);
	uniform_int_distribution<int> roll(-1000000000,1000000000);
	for (int i=0; i < 10000000; i++)
		v1.push_back(roll(rnd));
	
	generate(v2.begin(),v2.end(),RandomGenerator);
	vector<int> v3(v2);
	return 0;
}
