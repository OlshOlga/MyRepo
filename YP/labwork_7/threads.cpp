#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

void findPass(string pass, const string& hash)
{
	static mutex mtx;
	
		mtx.lock();
		crypt_data *pCryptData = new crypt_data;
		size_t pos = hash.find_last_of('$');
		string hashHead = hash.substr(0,pos);
		mtx.unlock();
		do {
			mtx.lock();
			string newHash = crypt_r(pass.data(),hashHead.data(),pCryptData);
			mtx.unlock();
			if (newHash == hash) {
				mtx.lock();
				cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
				mtx.unlock();
				break;

			}
		} while (next_permutation( pass.begin(), pass.end() ) );
		mtx.lock();
		delete pCryptData;
		mtx.unlock();
}

int main(int argc, char *argv[])
{
	vector<thread> threads;
	for (int count = 1; count < argc; ++count) {
		threads.push_back(thread(findPass, "123456789", argv[count]));
	}
	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	return 0;
}
