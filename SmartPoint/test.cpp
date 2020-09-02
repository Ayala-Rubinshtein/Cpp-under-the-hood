#include "SmartPtr.h"
#include "SharedPtr.h"
#include "UniquePtr.h"
#include "test.h"
class A{};
class B:public A{};
void test()
{

	SmartPtr<int> smp1(new int(5));
	std::cout<<*smp1<<std::endl;
	SmartPtr<int> smp2(new int(5));
	std::cout<<(smp1==smp2)<<std::endl;
	std::cout<<(smp1!=smp2)<<std::endl;
	SharedPtr<int>shp1(new int(5));
	SharedPtr<int>shp2(shp1);
	std::cout<<(shp1==shp2)<<std::endl;
	std::cout<<(shp1!=shp2)<<std::endl;
	std::cout<<*shp2<<std::endl;
	SharedPtr<int>shp3;
	std::cout<<"bool"<<std::endl;
	shp3?(std::cout<<"true"<<std::endl):(std::cout<<"false"<<std::endl);
	shp3=shp2;
	std::cout<<*shp3<<std::endl;
	UniquePtr<int> up1(new int(5));
	UniquePtr<int> up2(new int(6));
	std::cout<<*up1<<std::endl;
	std::cout<<*up2<<std::endl;
	std::cout<<"bool"<<std::endl;
	shp3?(std::cout<<"true"<<std::endl):(std::cout<<"false"<<std::endl);
	//compilation error
	//up1=up2;
	
	SharedPtr<B>shp5(new B);
	SharedPtr<A>shp4=shp5;
}
