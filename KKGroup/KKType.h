#ifndef _KKTYPE_H
#define _KKTYPE_H

#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <set>

typedef std::vector<int> INT_LIST;
typedef std::set<int> INT_SET;
typedef std::vector<std::string> STR_LIST;
typedef std::map< int, INT_LIST> GROUPS;
typedef GROUPS::iterator GROUPSItr;

namespace KKGroup
{
	class KKVertex;
	class KKEdge;
	class KKFace;
	typedef std::vector<KKVertex*> VERTEX_LIST;
	typedef std::vector<KKEdge*> EDGE_LIST;
	typedef std::vector<KKFace*> Face_LIST;

	struct KKPair
	{
		int mI;
		int mJ;
		KKPair(int i, int j) : mI(i), mJ(j) {}
	};
}

#endif