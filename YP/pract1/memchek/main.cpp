#include <iostream>
using namespace std;
// раскомментируй в зависимости от твеой группы
#define PI1
//#define PT1
//#define PT2
// вместо нуля поставь последние три цифры из номера зачетки
#define NUM 119
#define SIZE (NUM*100)
int main()
{
#if NUM==0
#error NUM not properly defined
#endif
#ifdef PI1
	typedef char T;
#elif defined PT1
	typedef int T;
#elif defined PT2
	typedef double T;
#else
#error Group not selected
#endif
	T * pT = new T [SIZE];
	T * pT2 = new T [100];
	pT[SIZE-1] = 65 + SIZE % 26;//индексация в массиве начинается с 0
	pT2[10] = 65 + NUM /10.0;
	cout<<pT[SIZE-1]<<endl;//индексация в массиве начинается с 0
	cout<<pT2[10]<<endl;
	delete[] pT2;//слишком рано освободили память
	delete[] pT;//не освободили память
	return 0;
}
