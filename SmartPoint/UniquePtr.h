#ifndef __UniquePtr__
#define __UniquePtr__
#include "SmartPtr.h"
template  <typename T>
class UniquePtr:public SmartPtr<T>
{
public:
	explicit UniquePtr(T* ptr=NULL):SmartPtr<T>(ptr)
	{}
private:
	UniquePtr(const UniquePtr<T>& other);
	UniquePtr<T>& operator=(const UniquePtr<T>& other) ;
};





#endif
