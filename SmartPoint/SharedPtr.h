#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__
#include "SmartPtr.h"
template  <typename T>
class SharedPtr
{
public:
	explicit SharedPtr(T* ptr=NULL):m_ptr(ptr),m_count(new size_t(1))
	{}
	
	~SharedPtr();
	
	SharedPtr(const SharedPtr<T>& other);
	template  <typename U>
	SharedPtr(const SharedPtr<U>& other);
	template  <typename U>
	SharedPtr& operator=(const SharedPtr<U>& other);
	SharedPtr& operator=(const SharedPtr<T>& other);
	T* operator->()const;
	
	T& operator*()const;
	T* getPtr()const;
	operator bool();
	size_t * getCount()const;
private:
	T * m_ptr;
	size_t *m_count; //shared. shallow copied
	void dec_count();
	void inc_count();
	void LastPointer();
	bool BiggerOfOne();
};

template <typename  T>
inline SharedPtr<T>::~SharedPtr()
{
		LastPointer();
}


template  <typename T,typename U>
inline bool operator==(const SharedPtr<T>& one,const SharedPtr<U>& other)
{
	return (one.getPtr()==other.getPtr());
}

template  <typename T,typename U>	
inline bool operator!=(const SharedPtr<T>& one,const SharedPtr<U>& other)
{
	return (!(one==other));
}
	
template <typename  T>
inline void SharedPtr<T>::LastPointer()
{
    if (BiggerOfOne())
    {
        dec_count();
    }
    else
    {
        delete m_count;
        delete m_ptr;
    }
}

template <typename  T>
inline bool SharedPtr<T>::BiggerOfOne()
{
	return *m_count>1;
}

template <typename  T>
inline SharedPtr<T>::operator bool()
{
	return getPtr()!=NULL;
}


template <typename  T>
template  <typename U>
inline SharedPtr<T>::SharedPtr(const SharedPtr<U>& other) : m_ptr(other.getPtr()), m_count(other.getCount())
{
    inc_count();
}

template <typename  T>
inline SharedPtr<T>::SharedPtr(const SharedPtr<T>& other) : m_ptr(other.getPtr()), m_count(other.getCount())
{
    inc_count();
}

template <typename T>
template <typename U>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<U>& other)
{
	if(*this!=other)
	{
		LastPointer();
		m_ptr = other.getPtr();
		m_count = other.getCount();
		inc_count();
	}
	return *this;
}

template <typename T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if(*this!=other)
	{
		LastPointer();
		m_ptr = other.getPtr();
		m_count = other.getCount();
		inc_count();
	}
	return *this;
}

template <typename  T>
inline T* SharedPtr<T>::operator->()const
{
		return m_ptr;
}
template <typename  T>
inline	T& SharedPtr<T>::operator*()const
{
		return *m_ptr;
}
template <typename  T>
inline T* SharedPtr<T>::getPtr()const
{
		return m_ptr;
}
template <typename  T>
inline void SharedPtr<T>:: dec_count() 
{
	(*m_count)--;
}
template <typename  T>
inline void SharedPtr<T>::inc_count() 	
{
	(*m_count)++;
}
template <typename  T>
inline size_t * SharedPtr<T>::getCount()const
{
    return m_count;
}
#endif
