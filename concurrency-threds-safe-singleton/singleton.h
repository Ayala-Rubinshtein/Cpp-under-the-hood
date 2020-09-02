//
// Created by mby on 06/08/2020.
//

#ifndef SIGNELTON_SINGLETON_H
#define SIGNELTON_SINGLETON_H

template < typename T >
class Singleton
{
public:
    static T& getInstance();

private:
    Singleton() { };
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator= (const Singleton);
    static T* m_instance;
};

template < typename T >
inline T& Singleton<T>::getInstance()
{
    if(!m_instance)
        m_instance = new T;
    return *m_instance;
}

template < typename T >
T* Singleton<T>::m_instance = nullptr;

template < typename T >
Singleton<T>::~Singleton(){
    delete m_instance;
    m_instance = nullptr;
}
#endif //SIGNELTON_SINGLETON_H
