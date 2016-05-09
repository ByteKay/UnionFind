#include "KKUnion.h"

namespace KKGroup
{
	KKUnion::KKUnion(){}

	KKUnion::~KKUnion()
	{
		mIndexTable.clear();
		GROUPSItr begin = mGroups.begin();
		GROUPSItr end = mGroups.end();
		while (begin != end)
		{
			begin->second.clear();
			++begin;
		}
		mGroups.clear();
	}

	void KKUnion::Init(int size)
	{
		for (int i = 0; i < size; ++i)
		{
			mIndexTable.push_back(i);
		}
	}

	unsigned int KKUnion::Find(int x)
	{
		while (mIndexTable[x] != x)
		{
			int id = mIndexTable[mIndexTable[x]];
			mIndexTable[x] = id;
			x = id;
		}
		return x;
	}

	void KKUnion::Unite(int i, int j)
	{
		unsigned int ii = Find(i);
		unsigned int jj = Find(j);
		if (ii != jj)
		{
			mIndexTable[ii] = jj;
		}
	}

	void KKUnion::Group()
	{
		int size = Size();
		for (int i = 0; i < size; ++i)
		{
			int groupId = Find(i);
			if (mGroups.find(groupId) == mGroups.end())
			{
				mGroups.insert(std::make_pair(groupId, INT_LIST()));
			}
			mGroups[groupId].push_back(i);
		}
	}

	void KKUnion::PrintTest()
	{
		GROUPSItr begin = mGroups.begin();
		GROUPSItr end = mGroups.end();
		while (begin != end)
		{
			int size = begin->second.size();
			for (int i = 0; i < size; ++i)
			{
				int id = begin->second[i];
				printf("%d ", id);
			}
			printf("\n");
			++begin;
		}
	}
}
