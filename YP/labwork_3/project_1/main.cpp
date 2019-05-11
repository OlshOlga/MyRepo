/* Программа, запрашивающая у пользователя целое число в диапазоне от 1 до 100,
 * а затем выводящая фразу «В караване было X верблюдов» с корректными падежными окончаниями, где вместо X введенное число.
 * Язык программирования: С++
 * Автор: Ольшевская О.И.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	int x;
	wcout << L"Введите x: ";
	wcin >> x;
	wstring ws = L"В караване было x верблюдов";

	if (x>0 and x<101) {

		if (x%10 > 4 or x%10 == 0 or x > 10 and x < 15) {
			ws.replace(ws.find(L"x"),1,to_wstring(x));
		} else if (x%10 > 1 && x%10 < 5) {
			ws.replace(ws.find(L"верблюдов")+7,2,L"а");
			ws.replace(ws.find(L"x"),1,to_wstring(x));
		}

		else {
			ws.erase(ws.find(L"верблюдов")+7,2);
			ws.erase(ws.find(L"было")+3,1);
			ws.replace(ws.find(L"x"),1,to_wstring(x));
		}
		wcout<<ws<<endl;
	}
	return 0;
}
