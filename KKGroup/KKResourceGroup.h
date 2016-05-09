#ifndef _KKRESOURCEGROUP_H
#define _KKRESOURCEGROUP_H

#include "KKObject.h"

namespace KKGroup
{
	class KKResourceObject : public KKObject
	{
	public:
		KKResourceObject(){}
		~KKResourceObject();
		inline int Size() const { return mNodeList.size(); }
		virtual bool IsCloseTo(const KKObject& other);
		virtual void InitializeByString(std::string data);

	private:
		void AppendToSet(INT_SET* intersection) const;
	private:
		std::string mKey;
		INT_LIST mNodeList;
	};

	class KKResourceObjects : public KKObjects<KKResourceObject>
	{
	public:
		KKResourceObjects();
		virtual ~KKResourceObjects();
		virtual void InitializeFromFile(const char* fileName);	
		virtual void Deserialize(const char* outPut)
		{
			// to do
		}

	protected:
		void InitializeFromContainer(const STR_LIST* sources);
	};

	class KKResourceDefalutObjects : public KKResourceObjects
	{
	public:
		virtual void InitializeFromFile(const char* fileName)
		{
			STR_LIST list;
			list.push_back("12345_1_2_3_4_5");
			list.push_back("135_1_3_5");
			list.push_back("246_2_4_6");
			list.push_back("147_1_4_7");
			InitializeFromContainer(&list);
			list.clear();
		}
	};
}

#endif