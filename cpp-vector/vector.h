#include <cstdio>
#include <cmath>
#include <exception>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <exception>

template <typename T>
class Vector{
public:
    explicit Vector();
    explicit Vector(size_t size,T value=T());
    Vector(Vector& v);
    ~Vector();
    Vector& operator=(const Vector& v);
    size_t size() const;
    static size_t max_size();
    void resize(size_t new_size,T value=T());
    size_t capacity() const;
    bool empty() const;
    void reserve(size_t new_n);
    T&operator[](size_t index);
    const T&operator[](size_t index)const;
    T& at(size_t index);
    const T& at(size_t index) const ;
    T& front() ;
    const T& front()const;
    T& back() ;
    const T& back()const;
    T* data() noexcept;
    const T* data()const noexcept;
    void assign(size_t n, T val=T());
    void push_back(T val=T());
    void pop_back();
    void insert(size_t index,T val=T());
    void swap(Vector<T> &x);
    void erase(size_t index);
    void clear();
    Vector<T>& operator+=(Vector& other);
private:
    Vector& init(Vector & v,size_t size);
    T* m_vec;
    size_t m_size;
    size_t m_capacity;

};
template <typename T>
Vector<T>::Vector():m_size(0),m_capacity(0),m_vec(NULL){
}
template <typename T>
Vector<T>::Vector(size_t size, T value):m_vec(NULL) ,m_size(size),m_capacity(size) {
    m_vec=new T[m_size];
    for (int i = 0; i <size ; ++i) {
        m_vec[i] = value;
    }
}
template <typename T>
Vector<T>& Vector<T>::init(Vector<T> &v, size_t size) {
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
}
template <typename T>
Vector<T>::Vector(Vector<T> &v):m_vec(NULL),m_size(v.size()),m_capacity(v.capacity()) {
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
}
template <typename T>
Vector<T>::~Vector() {
    delete [] m_vec;
    m_vec=NULL;
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v) {
    m_capacity=v.capacity();
    m_size=v.size();
    T* orig = m_vec;
    m_vec =new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_vec[i]=v[i];
    }
    delete orig;
    return *this;
}

template <typename T>
size_t Vector<T>::size() const {
    return m_size;
}
template <typename T>
size_t Vector<T>::max_size() {
    return (pow(2, sizeof(T)))-1;
}
template <typename T>
size_t Vector<T>::capacity() const {
    return m_capacity;
}
template <typename T>
void Vector<T>::resize(size_t new_size ,T value) {
	reserve(new_size);
	size_t len=m_size;
	if(new_size<m_size){
		for(size_t i=0;i<len-new_size;i++){
			pop_back();
		}
	}
	else{
		for(size_t i=0;i<new_size-len;i++){
			push_back(value);
		}

	}
	m_size=new_size;
}
template <typename T>
bool Vector<T>::empty() const {
    return (m_size==0);
}

template <typename T>
void Vector<T>::reserve(size_t new_n) {
    size_t i=0;
	if(new_n>m_capacity)
	{
		T* new_vec = new T[new_n];
		if(new_vec)
        {
            for (; i <m_size ; ++i) {
                new_vec[i]=m_vec[i];
            }
            for(;i<new_n;i++)
            {
                new_vec[i]=T(0);
            }
            delete[] m_vec;
            m_vec = new_vec;
            m_capacity=new_n;
        }
	}
}
template <typename T>
T& Vector<T>::operator[](size_t index) {
    return m_vec[index];
}
template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return m_vec[index];
}
template <typename T>
const T& Vector<T>::at(size_t index) const {
    if(index>m_size){
        throw std::out_of_range("sorry");
    }
    return m_vec[index];
}
template <typename T>
T& Vector<T>::at(size_t index) {
    if(index>m_size){

        throw std::out_of_range("sorry");
    }
    return m_vec[index];
}
template <typename T>
T& Vector<T>::front() {
    return m_vec[0];
}
template <typename T>
const T& Vector<T>::front() const {
    return m_vec[0];
}

template <typename T>
inline T& Vector<T>::back()
{
	return m_vec[m_size-1];
}

template <typename T>
inline const T& Vector<T>::back()const
{
	return m_vec[m_size-1];
}

template <typename T>
inline T* Vector<T>::data()noexcept
{
	return m_vec;
}

template <typename T>
inline const T* Vector<T>::data()const noexcept
{
	return m_vec;
}	

template <typename T>
inline void Vector<T>::assign(size_t n, T val)
{
	if(n<=m_capacity)
	{
		for(size_t i=0;i<n;i++)
			m_vec[i]=val;
		for(size_t i=n;i<m_size;i++)
			m_vec[i].~T();
		m_size=n;
		return;
	}
	delete[] m_vec;
	m_vec=new T[n];
	for(size_t i=0;i<n;i++)
		m_vec[i]=val;
	m_size=n;
	m_capacity=n;	
}


template <typename T>
inline void Vector<T>::push_back(T val)	
{
	if(m_capacity>m_size)
		m_vec[m_size]=val;
	else
	{
		reserve(m_capacity*2);
		m_vec[m_size]=val;
	}
	m_size++;
}

template <typename T>
inline void Vector<T>::pop_back()	
{
	if(!empty())
	{
		m_vec[m_size-1].~T();
		m_size--;
	}	
}


template <typename T>
inline void Vector<T>::insert(size_t index,T val)
{
	if (index > m_size)
	{
		throw std::out_of_range("sorry");
	}
	if(m_capacity == m_size)
	{
		T* tmp=m_vec;
		m_vec=new T[m_capacity*2];
		m_capacity*=2;
		for(size_t i=0;i<m_size;i++)
		m_vec[i]=tmp[i];
		delete[]tmp;
	}
	if (m_size < index + 1)
	{
		m_vec[index] = val;
		m_size = index + 1;
	}
	else
	{
		size_t i = m_size;
		while (i >= index)
		{
			m_vec[i] = m_vec[i - 1];
			i--;
		}
		m_vec[index] = val;
		m_size++;
	}
}

template <typename T>
inline void Vector<T>::swap(Vector<T> &x)
{
	Vector<T> tmp = x;
	x=(*this);
	(*this) = tmp;
}

template <typename T>
inline void Vector<T>::erase(size_t index)
{
    for(size_t i=index;i<m_size;i++)
    {
        m_vec[i]=m_vec[i+1];
    }
    m_vec[m_size].~T();
    m_size--;
}
template <typename T>
inline void Vector<T>::clear()
{
	size_t n=m_size;
	for(size_t i=0;i<n;i++)
	{
		pop_back();
	}
}

template <typename T>
Vector<T> operator+(Vector<T>& v1,Vector<T>& v2)
{
    size_t size_v1=v1.size();
    size_t size_v2=v2.size();
   T* tmp=new T[v1.size()+v2.size()];
    if(tmp)
    {
        for(size_t i=0;i<size_v1;i++)
            tmp[i]=v1[i];

        for(size_t i=0;i<size_v2;i++)
            tmp[v1.size()+i]=v2[i];
    }
    Vector<T> new_vec;
    new_vec.reserve(size_v1+size_v2);
    new_vec.resize(size_v1+size_v2);
    for(size_t i=0;i<size_v1+size_v2;i++)
        new_vec[i]=tmp[i];
    return new_vec;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(Vector& other)
{
    size_t capacity=m_capacity;
    while(m_capacity>capacity)
    {
        capacity*=2;
    }
    reserve(capacity);
    *this=*this+other;
    return *this;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Vector<T>& vec)
{
    std::cout << "The capacity: " << vec.capacity() << std::endl;
    std::cout << "The Size: " << vec.size() << std::endl;
    std::cout << "The Values: " << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " , ";
    }
    std::cout << std::endl;
    return std::cout;
}
