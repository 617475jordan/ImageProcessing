#pragma once
#include <stdio.h>
#include<iostream>
#include<map>
#include <Windows.h>
#include <fstream>  
#include <iterator>
#include <string>
using namespace std;

class GetPathFiles
{
public:
	GetPathFiles();
	~GetPathFiles();

	void getFiles(std::string path, std::map<std::string,std::string>& files);
private:


};

