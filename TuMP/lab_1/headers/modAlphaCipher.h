#pragma once
#include <vector>
#include <string>
#include <codecvt>
#include <locale>
#include <map>

class modAlphaCipher
{
private:
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	std::map <wchar_t,int> alphaNum; 
	std::vector <int> key; 
	std::vector<int> convert(const std::wstring& ws); 
	std::string convert(const std::vector<int>& v); 
	std::wstring towstr(const std::string& s);
	std::string fromwstr(const std::wstring& ws);
public:
	modAlphaCipher()=delete;
	modAlphaCipher(const std::string& skey);
	std::string encrypt(const std::string& open_text);  
	std::string decrypt(const std::string& cipher_text);
};