#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <thread>

using namespace std;

void findPass(string pass, const string& hash)
{
		crypt_data *pCryptData = new crypt_data;
		size_t pos = hash.find_last_of('$');
		string hashHead = hash.substr(0,pos);
		do {
			string newHash = crypt_r(pass.data(),hashHead.data(),pCryptData);
			if (newHash == hash) {
				cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
				break;

			}
		} while (next_permutation( pass.begin(), pass.end() ) );
		delete pCryptData;
}

int main(int argc, char *argv[])
{
	for (int count=1; count < argc; ++count) {
		cout << count << " ";
		thread th_1 (findPass, "123456789", argv[count]);
		th_1.join();
	}
	return 0;
}
