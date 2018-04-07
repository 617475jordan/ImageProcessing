#include "getFiles.h"


getFiles::getFiles()
{
}


getFiles::~getFiles()
{
}

std::vector<std::string> getFiles::getAllFiles(string path)
{
	std::wstring stemp = s2ws(path + "\\*.*");
	LPCTSTR lpFileName = stemp.c_str();
	HANDLE hFile;
	WIN32_FIND_DATA pNextInfo;  //搜索得到的文件信息将储存在pNextInfo中;
	hFile = FindFirstFile(lpFileName, &pNextInfo);//请注意是 &pNextInfo , 不是 pNextInfo;
	if (hFile == INVALID_HANDLE_VALUE)
	{
		//搜索失败
		exit(-1);
	}
	//wcout<<pNextInfo.cFileName<<endl;
	//printf("%s\n", WcharToChar(pNextInfo.cFileName));
	string m_strFileName;
	vector<string> m_strAllFileNames;
	while (FindNextFile(hFile, &pNextInfo))
	{
		if (pNextInfo.cFileName[0] == '.')//过滤.和..
			continue;
		//wcout<<pNextInfo.cFileName<<endl;
		m_strFileName = WcharToChar(pNextInfo.cFileName);
		m_strAllFileNames.push_back(m_strFileName);

		//cout << m_strFileName << endl;
		m_strFileName.clear();
		//printf("%s\n", WcharToChar(pNextInfo.cFileName));
	}
	return m_strAllFileNames;
	getchar();
}

std::wstring getFiles::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;

	return r.c_str();
}

char* getFiles::WcharToChar(const wchar_t* wp)
{
	char *m_char;
	int len = WideCharToMultiByte(CP_ACP, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
	m_char = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	return m_char;
}
