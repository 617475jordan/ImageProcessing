#include "GetPathFiles.h"
#include<vector>
#include<string>
#include<io.h>
#include<iostream>



GetPathFiles::GetPathFiles()
{
}


GetPathFiles::~GetPathFiles()
{
}

void GetPathFiles::getFiles(std::string path, std::map<std::string,std::string>& files)
{
	std::string m_path = path + "//*.net.xml";
	__int64  Handle;
#if X86
	long hFile = 0;
#else
	intptr_t hFile;
#endif
#if _WIN64
	struct __finddata64_t  FileInfo;

	if ((Handle = _findfirst64(m_path.c_str(), &FileInfo)) == -1L)
	{
		return;
	}
		//printf("没有找到匹配的项目\n");
	else
	{
		files.insert(std::pair<std::string,std::string>(path + "//" + FileInfo.name, FileInfo.name));
		printf("%s\n", FileInfo.name);
		while (_findnext64(Handle, &FileInfo) == 0) {
			m_lIndex++;
			files.insert(std::pair<std::string, std::string>(path + "//" + FileInfo.name, FileInfo.name));
		}
		_findclose(Handle);
	}

#elif _WIN32
		//文件句柄  
		long   hFile = 0;
		//文件信息  
		struct _finddata_t fileinfo;
		string p;
		if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
		{
			do
			{
				//如果是目录,迭代之  
				//如果不是,加入列表  
				if ((fileinfo.attrib &  _A_SUBDIR))
				{
					if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
						getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
				}
				else
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					files.insert(std::pair<std::string, std::string>(path + "//" + fileinfo.name, fileinfo.name));
				}
			} while (_findnext(hFile, &fileinfo) == 0);
			_findclose(hFile);
		}
#endif
	m_path.clear();
}
