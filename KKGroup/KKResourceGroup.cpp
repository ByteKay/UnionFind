#include "KKResourceGroup.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

namespace KKGroup
{
	bool KKResourceObject::IsCloseTo(const KKObject& other)
	{
		static float THRESHOLD = 0.85f;
		INT_SET intersection;
		intersection.clear();
		KKResourceObject* oth = (KKResourceObject*)(&other);
		this->AppendToSet(&intersection);
		oth->AppendToSet(&intersection);
		int size = intersection.size();
		int size1 = this->Size();
		int size2 = oth->Size();
		intersection.clear();
		bool flag = (size1 * 1.0f / size) > THRESHOLD && (size2 * 1.0f / size) > THRESHOLD;
		flag = (size1 == size) || (size2 == size);
		return flag;
	}

	void KKResourceObject::InitializeByString(std::string data)
	{
		int index = data.find_first_of("_");
		if (index == -1)
			return;
		mKey = data.substr(0, index);
		std::string temp = data.substr(index);
		const char* format = "%d";
		int number;
		index = temp.find_first_of("_");
		std::string temp1;
		while (index != -1)
		{
			temp = temp.substr(index + 1);
			index = temp.find_first_of("_");
			if (index != -1)
			{
				temp1 = temp.substr(0, index);
			}
			else
			{
				temp1 = temp.substr(0);
			}
			number = atoi(temp1.c_str());
			// sscanf(temp1.c_str(), format, number);
			mNodeList.push_back(number);	
					
		}
	}

	KKResourceObject::~KKResourceObject()
	{
		mNodeList.clear();
	}

	void KKResourceObject::AppendToSet(INT_SET* intersection) const
	{
		int size = this->Size();
		for (int i = 0; i < size; ++i)
		{
			intersection->insert(mNodeList[i]);
		}
	}

	KKResourceObjects::KKResourceObjects()
	{

	}

	KKResourceObjects::~KKResourceObjects()
	{
	}

	void KKResourceObjects::InitializeFromFile(const char* fileName)
	{
		FILE* file = fopen(fileName, "rb");
		if (file)
		{
			fclose(file);
			std::ifstream fin(fileName);
			std::string line;
			STR_LIST list;
			while (getline(fin, line))
			{
				list.push_back(line);
			}
			fin.close();
			InitializeFromContainer(&list);
			list.clear();
		}
		else
		{
			// error
			std::cout << fileName << " exception : it may be not exit, please check !" << std::endl;
		}

	}

	void KKResourceObjects::InitializeFromContainer(const STR_LIST* sources)
	{
		mObjects.clear();
		int size = sources->size();
		for (int i = 0; i < size; ++i)
		{
			KKResourceObject* object = new KKResourceObject;
			object->InitializeByString((*sources)[i]);
			mObjects.push_back(object);
		}
	}

}
