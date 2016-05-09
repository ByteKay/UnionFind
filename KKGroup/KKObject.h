#ifndef _KK_GROUP_H
#define _KK_GROUP_H

#include "KKType.h"

namespace KKGroup
{
	class KKObject
	{
	public:
		KKObject(){}
		virtual ~KKObject(){}
		virtual bool IsCloseTo(const KKObject& other) = 0;
	};

	template<typename T>
	class KKObjects
	{
	public:
		KKObjects();
		virtual ~KKObjects();
		virtual void InitializeFromFile(const char* fileName) = 0;
		virtual void Deserialize(const char* outPut) = 0;
		// clear, free memory
		void Clear();
		// get size
		inline int Size(){ return mObjects.size(); }
		// make pair if two objects are in condition
		void GeneratePairs(std::vector<KKPair>* pairs);

	protected:
		std::vector<T*> mObjects;
	};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	void KKObjects<T>::Clear()
	{
		int size = mObjects.size();
		for (int i = 0; i < size; ++i)
		{
			delete mObjects[i];
			mObjects[i] = 0;
		}
		mObjects.clear();
	}

	template<typename T>
	KKObjects<T>::~KKObjects()
	{
		Clear();
	}

	template<typename T>
	KKObjects<T>::KKObjects()
	{

	}

	template<typename T>
	void KKObjects<T>::GeneratePairs(std::vector<KKPair>* pairs)
	{
		pairs->clear();
		int size = mObjects.size();
		for (int i = 0; i < size - 1; ++i)
		{
			T* objectI = mObjects[i];
			for (int j = i + 1; j < size; ++j)
			{
				if (objectI->IsCloseTo(*mObjects[j]))
				{
					pairs->push_back(KKPair(i, j));
				}
			}
		}
	}
}

#endif

