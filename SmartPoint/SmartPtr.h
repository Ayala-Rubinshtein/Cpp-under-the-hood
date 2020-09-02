#ifndef __SmartPtr__
#define __SmartPtr__
#include "iostream"
template  <typename T>
class SmartPtr
{
public:
	explicit SmartPtr(T* ptr=NULL):m_ptr(ptr)
	{}
	
	~SmartPtr()
	{
		delete m_ptr;

	}
	
	T* operator->()const
	{
		return m_ptr;
	}
	
	T& operator*()const
	{
		return *m_ptr;
	}
	bool operator==(const SmartPtr<T>& other)const
	{
		return (m_ptr==other.m_ptr);//(*m_ptr!=*(other.m_ptr));
	}
	
	bool operator!=(const SmartPtr<T>& other)const
	{
		return  (m_ptr!=other.m_ptr);
	}
	
private:
	T * m_ptr;
};



#endif
