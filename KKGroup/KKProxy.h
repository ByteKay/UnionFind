#ifndef _KKPROXY_H
#define  _KKPROXY_H

#include "KKObject.h"
#include "KKUnion.h"

namespace KKGroup
{
	template<typename T>
	class KKProxy
	{
	public:
		KKProxy();
		KKProxy(const KKObjects<T>* objects);
		virtual ~KKProxy();
		void Objects(KKObjects<T>* objects);
		void Init(const char* fileName);
		void Group();
		inline KKUnion* Union() { return &mUnion; }

	private:
		KKUnion mUnion;
		KKObjects<T>* mObjects;
	};


	template<typename T>
	KKProxy<T>::KKProxy() : mObjects(0)
	{
	}

	template<typename T>
	KKProxy<T>::KKProxy(const KKObjects<T>* objects) : mObjects(objects)
	{
	}

	template<typename T>
	KKProxy<T>::~KKProxy()
	{
		mObjects = 0;
	}

	template<typename T>
	void KKProxy<T>::Objects(KKObjects<T>* objects)
	{
		mObjects = objects;
	}

	template<typename T>
	void KKProxy<T>::Init(const char* fileName)
	{
		mObjects->InitializeFromFile(fileName);
		mUnion.Init(mObjects->Size());
	}

	template<typename T>
	void KKProxy<T>::Group()
	{
		std::vector<KKPair> pairs;
		mObjects->GeneratePairs(&pairs);
		int size = pairs.size();
		for (int i = 0; i < size; ++i)
		{
			mUnion.Unite(pairs[i].mI, pairs[i].mJ);
		}
		pairs.clear();
		mUnion.Group();
	}
}

#endif