#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class getFiles
{
public:
	getFiles();
	~getFiles();
	vector<string> getAllFiles(string path);
private:
	std::wstring s2ws(const std::string& s);
	char* WcharToChar(const wchar_t* wp);
};

