#include "vector.h"
int main()
{
	Vector<int> v1(10,5);
	std::cout<<v1;
	Vector<int> v2=v1;
	std::cout<<v2;
	Vector<int> v3;
	v3=v1;
	std::cout<<v3;
	std::cout<<v3.size()<<std::endl;
	v3.resize(15,3);
	std::cout<<v3;
	Vector<int> v4;
	std::cout<<v4.empty()<<std::endl;
	v3.reserve(20);
	std::cout<<v3;
	v3.reserve(5);
	std::cout<<v3;
	std::cout<<v3[10]<<std::endl;
	v3[10]=7;
	std::cout<<v3;
	//v3.at(500); throw error
	std::cout<<v3.front()<<std::endl;
	std::cout<<v3.back()<<std::endl;
	*v3.data()=1;
	std::cout<<v3;
	v3.assign(25,4);
	std::cout<<v3;
	v3.assign(6,8);
	std::cout<<v3;
	v3.push_back(6);
	std::cout<<v3;
	v3.pop_back();
	std::cout<<v3;
	v3.insert(5);
	std::cout<<v3;
	v3.swap(v2);
	std::cout<<v3;
	v3.erase(5);
	std::cout<<v3;
	v3.clear();
	std::cout<<v3;
	v3+=v2;
	std::cout<<v3;
	v3=v1+v2;
	std::cout<<v3;
	return 0;
}
