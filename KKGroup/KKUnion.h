#ifndef _KKUNION_H
#define _KKUNION_H

#include "KKType.h"

namespace KKGroup
{
	// union the same group
	class KKUnion
	{
	public:
		KKUnion();
		~KKUnion();
		// initialize capacity
		void Init(int size);
		// find the next until the index is equal to the value
		unsigned int Find(int x);
		// mark i and j that they are in the same group
		void Unite(int i, int j);
		// finally, make all items in the same group to a chain
		void Group();
		// just for debug
		void PrintTest();
		// size
		inline int Size(){ return mIndexTable.size(); }
		// value by index
		inline int Element(int index){ return mIndexTable[index]; }

	private:
		// store all groups
		GROUPS mGroups;
		// store the group indexes
		INT_LIST mIndexTable;
	};
}



#endif