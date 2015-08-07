#ifndef _DATA_H_
#define _DATA_H_

#include <rapidjson/document.h>

class Data
{
public:
	static rapidjson::Document document;

public:
	static void LoadData();
	static void SaveData();

	static void ShowData();

	static void OpenDataFile();
private:
	Data();
	Data(const Data&);
	~Data();

	static void InitData();
};

#endif