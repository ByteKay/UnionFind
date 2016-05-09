#include "KKProxy.h"
#include "KKResourceGroup.h"
void test()
{
	KKGroup::KKProxy<KKGroup::KKResourceObject> proxy;
	KKGroup::KKResourceObjects objects;

	proxy.Objects(&objects);
	proxy.Init("group.txt");
	proxy.Group();

	KKGroup::KKUnion* _union = proxy.Union();
	_union->PrintTest();
}

int main()
{
	test();
	printf("done");
	getchar();
}