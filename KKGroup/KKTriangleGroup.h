#ifndef _KKTRIANGLEGROUP_H
#define _KKTRIANGLEGROUP_H

#include "KKObject.h"

namespace KKGroup
{
	class KKVertex
	{
	public:
		KKVertex();
		~KKVertex();

	};

	class KKEdge
	{
	public:
		KKEdge();
		~KKEdge();

	};

	class KKFace
	{
	public:
		KKFace();
		~KKFace();
	private:

	};

	class KKTriangleObject : public KKObject
	{
	public:
		virtual bool IsCloseTo(const KKObject& other);
	private:
		KKFace mTriangle;
	};


	class KKTriangleObjects : public KKObjects<KKTriangleObject>
	{
	public:
		virtual void InitializeFromFile(const char* fileName);
		virtual void Deserialize(const char* outPut);
	public:

	};

}

#endif