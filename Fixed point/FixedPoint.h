#ifndef FIXED_POINT2_FIXEDPOINT_H
#define FIXED_POINT2_FIXEDPOINT_H
#include <iostream>
#include <cstdlib>
#include <math.h>
template <unsigned int SIZE,typename T> class Price;
template< unsigned int SIZE,typename T=int>
class Price {
private:
    T m_dollar;
    int m_cent;
    bool m_sign;
    unsigned int m_size;
    unsigned int m_size_pow;
public:
     Price();
     Price(T dollar);
     Price(T dollar,int cent);
    T getDollar()const ;
    int getcent()const ;
    int getSign()const ;
    int getFirstDigits(int size)const;
    unsigned int getSize()const ;
    unsigned int getSizePow()const ;
    Price<SIZE,T>&  operator +=(const Price<SIZE,T>& price1);
    Price<SIZE,T>&  operator +=(T);
    Price<SIZE,T>&  operator -=(const Price<SIZE,T>& price1);
    Price<SIZE,T>&  operator -=(T);
    Price<SIZE,T>&  operator *=(const Price<SIZE,T>& price1);
    Price<SIZE,T>&  operator *=(T);
    Price<SIZE,T>&  operator /=(const Price<SIZE,T>& price1);
    Price<SIZE,T>&  operator /=(T);
    Price<SIZE,T>&  operator %=(const Price<SIZE,T>& price1);
     Price<SIZE,T>&  operator %=(T);
    Price<SIZE,T>&  operator =(T);
    Price<SIZE,T>& operator++();
    Price<SIZE,T> operator++(int);
    Price<SIZE,T>& operator--();
    Price<SIZE,T> operator--(int);
    operator double ();


};
template< unsigned int SIZE,typename T> Price<SIZE,T>   operator +(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator +(const Price<SIZE,T>& ,T num);
template< unsigned int SIZE,typename T> Price<SIZE,T>   operator -(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T>Price<SIZE,T>  operator -(const Price<SIZE,T>& ,T num);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator *(const Price<SIZE,T>&,const Price<SIZE,T>&);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator *(const Price<SIZE,T>&,T);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator /(const Price<SIZE,T>&,const Price<SIZE,T>&);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator /(const Price<SIZE,T>&,T);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator %(const Price<SIZE,T>&,const Price<SIZE,T>&);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator %(const Price<SIZE,T>&,T);
template< unsigned int SIZE,typename T> Price<SIZE,T>  operator-(const Price<SIZE,T>& price);
template< unsigned int SIZE,typename T> bool operator==(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T> bool operator!=(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T> bool operator<(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T> bool operator>(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T> bool operator<=(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);
template< unsigned int SIZE,typename T> bool operator>=(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2);





template< unsigned int SIZE,typename T> inline std::ostream& operator<<(std::ostream &os,Price<SIZE,T> &price)
{
    if(price.getSign()==-1)
        os<<"-";
    os<<price.getDollar()<<".";
    if(price.getcent()<10)
        os<<0;
    os<<price.getcent()<<std::endl;
    return os;
}

template< unsigned int SIZE,typename T>
inline Price<SIZE,T>::Price():m_dollar(0),m_cent(0),m_sign(false),m_size(SIZE),m_size_pow(std::pow(10,SIZE))
{}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>::Price(T dollar):m_dollar(unsigned(dollar)),m_cent(0),m_sign(false),m_size(SIZE),m_size_pow(std::pow(10,SIZE))
{
	if(dollar<0)
		m_sign=true;
}

template< unsigned int SIZE,typename T>
inline Price<SIZE,T>::Price(T dollar,int cent):m_dollar(unsigned(dollar)),m_cent(unsigned(cent)),m_sign(false),m_size(SIZE),m_size_pow(std::pow(10,SIZE))
{
	if(dollar<0 || cent<0)
		m_sign=true;
	while(m_cent>=m_size_pow)
	{
		m_cent-=m_size_pow;
		m_dollar+=1;
	}
}

template< unsigned int SIZE,typename T> inline T Price<SIZE,T>::getDollar()const
{
    return m_dollar;
}

template< unsigned int SIZE,typename T> inline int Price<SIZE,T>::getcent()const
{
    return   m_cent ;
}

template< unsigned int SIZE,typename T> inline  int Price<SIZE,T>::getSign()const
{
    return m_sign ? -1 : 1;
}

template< unsigned int SIZE,typename T> inline  unsigned int Price<SIZE,T>::getSize()const
{
    return m_size;
}

template< unsigned int SIZE,typename T> inline  unsigned int Price<SIZE,T>::getSizePow()const
{
    return m_size_pow;
}

template< unsigned int SIZE,typename T> inline int Price<SIZE,T>::getFirstDigits(int size)const
{
	return int(m_cent)/int(pow(10,m_size-size));
}

template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator +=(const Price<SIZE,T>& price1){
    *this=*this+price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator +=(T price1){
    *this=*this+price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>  operator +(const Price<SIZE,T>&num1,const Price<SIZE,T>& num2){
    if (num1.getSign()==-1)
    {
        return num2-(-num1);  
    }
    if (num2.getSign()==-1)
    {
        return num1-(-num2);
    }
    T before= num1.getDollar()+num2.getDollar();
    if((before<num1.getDollar())||(before<num2.getDollar()))
    throw("overflow");
        unsigned int after=num1.getcent()+num2.getcent();
        if((after<num1.getcent())||(after<num2.getcent()))
        	 throw("overflow");
        return Price<SIZE,T>(before,after);
}


template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator +(const Price<SIZE,T>& price1,T num)
{
	Price<SIZE,T> price(num);
	return price1 + price;
}

template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator *(const Price<SIZE,T>& price1,T num)
{
	Price<SIZE,T> price(num);
	return price1 * price;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator %(const Price<SIZE,T>& price1,T num)
{
	Price<SIZE,T> price(num);
	return price1 % price;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator /(const Price<SIZE,T>& price1,T num)
{
	Price<SIZE,T> price(num);
	return price1 / price;
}


template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator-(const Price<SIZE,T> & p1,const Price<SIZE,T> & p2)
{
	if (p1.getSign()==1&&p2.getSign()==1)
	{
		if (p1.getcent() < p2.getcent() && p1.getDollar()>p2.getDollar())
		{
			return Price<SIZE,T>((p1.getDollar()-p2.getDollar()-1),(100+(p1.getcent()-p2.getcent())));
		}
        return Price<SIZE,T>((p1.getDollar()-p2.getDollar()),(p1.getcent()-p2.getcent()));
	}
	if (p1.getSign()==-1&&p2.getSign()==-1)
	{
		return (-p2)+(-p1);
	}
	if (p1.getSign()==1&&p2.getSign()==-1)
	{
		return p1+(-p2);
	}
	return -((-p1)+p2);
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>  operator -(const Price<SIZE,T>& price1,T num)
{
	Price<SIZE,T> price(num);
	return price1 - price;
}

template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator -=(const Price<SIZE,T>& price1){
    *this=*this-price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator -=(T price1){
    *this=*this-price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator *=(const Price<SIZE,T>& price1){
    *this=*this*price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator *=(T price1){
    *this=*this*price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator /=(const Price<SIZE,T>& price1){
    *this=*this/price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator /=(T price1){
    *this=*this/price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator %=(const Price<SIZE,T>& price1){
    *this=*this%price1;
    return *this;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>:: operator %=(T price1){
    *this=*this%price1;
    return *this;
}

template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator-(const Price<SIZE,T>& price){
    return Price<SIZE,T>(price.getDollar()*price.getSign()*-1, price.getcent()*price.getSign()*-1);
}


template< unsigned int SIZE,typename T>
Price<SIZE,T>& Price<SIZE,T>::operator++(){
    *this += Price<SIZE,T>(1);
    return *this;
}

template< unsigned int SIZE,typename T>
Price<SIZE,T> Price<SIZE,T>::operator++(int){
    Price<SIZE,T> res(*this);
    *this += Price<SIZE,T>(1);
    return res;
}
template< unsigned int SIZE,typename T>
Price<SIZE,T>& Price<SIZE,T>::operator--(){
    *this -= Price<SIZE,T>(1);
    return *this;
}
template< unsigned int SIZE,typename T>
Price<SIZE,T> Price<SIZE,T>::operator--(int){
    Price<SIZE,T> res(*this);
    *this-=Price<SIZE,T>(1);
    return res;
}

template< unsigned int SIZE,typename T>
inline bool operator==(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2)
{
     return (price1.getDollar()==price2.getDollar())&&(price1.getcent()==price2.getcent())&&(price1.getSign()==price2.getSign());
}

template< unsigned int SIZE,typename T>
inline bool operator!=(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2)
{
    return !((price1.getDollar()==price2.getDollar())&&(price1.getcent()==price2.getcent())&&(price1.getSign()==price2.getSign()));
}
template< unsigned int SIZE,typename T>
inline bool operator<(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2)
{
    if(price1.getSign()<price2.getSign())
        return true;
    if(price1.getSign()>price2.getSign())
        return false;
    if(price1.getSign()==1)
        return (price1.getDollar()<price2.getDollar())&&(price1.getcent()<price2.getcent());
    return (price1.getDollar()>price2.getDollar())&&(price1.getcent()>price2.getcent());
}
template< unsigned int SIZE,typename T>
inline bool operator>(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2)
{
    if(price1.getSign()>price2.getSign())
        return true;
    if(price1.getSign()>price2.getSign())
        return false;
    if(price1.getSign()==-1)
        return (price1.getDollar()<price2.getDollar())&&(price1.getcent()<price2.getcent());
    return (price1.getDollar()>price2.getDollar())&&(price1.getcent()>price2.getcent());
}

template< unsigned int SIZE,typename T>
inline bool operator<=(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2){
     if(price1==price2)
         return true;
     return price1<price2;
 }
template< unsigned int SIZE,typename T>
inline bool operator>=(const Price<SIZE,T>& price1,const Price<SIZE,T>& price2){
    if(price1==price2)
        return true;
    return price1>price2;
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T>& Price<SIZE,T>::  operator =(T price ){
    m_dollar=unsigned(price) ;
    m_cent=0;
    m_sign= false;
    if(price<0)
        m_sign= true;
    return *this;
 }
template< unsigned int SIZE,typename T>
 inline Price<SIZE,T>::operator double() {
     double x=(double)getDollar()*getSign()+((double)getcent()*getSign())/100;
    return x;
 }
template< unsigned int SIZE,typename T>
Price<SIZE,T> operator*(const Price<SIZE,T>& p1, const Price<SIZE,T>& p2)
{
	int cents1 = p1.getDollar()*100+p1.getFirstDigits(2);
	int cents2 = p2.getDollar()*100+p2.getFirstDigits(2);
	cents1 *= cents2;
	if(p1.getSign()==p2.getSign())
	{
		return Price<2,T>(cents1/10000,(cents1%10000)/100);
	}
	return Price<2,T>((-1)*cents1/10000,(cents1%10000)/100);
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator/(const Price<SIZE,T>& p1, const Price<SIZE,T>& p2)
{
	int cents1 = (p1.getDollar()*100+p1.getFirstDigits(2));
	int cents2 = p2.getDollar()*100+p2.getFirstDigits(2);
	cents1 /= cents2;
	if(p1.getSign()==p2.getSign())
	{
		return Price<2,T>(cents1/100,cents1%100);
	}
	return Price<2,T>((-1)*cents1/100,cents1%100);
}
template< unsigned int SIZE,typename T>
inline Price<SIZE,T> operator%(const Price<SIZE,T>& p1, const Price<SIZE,T>& p2)
{
	int cents1 = (p1.getDollar()*100+p1.getFirstDigits(2));
	int cents2 = p2.getDollar()*100+p2.getFirstDigits(2);
	cents1 %= cents2;
	if(p1.getSign()==p2.getSign())
	{
		return Price<2,T>(cents1/100,cents1%100);
	}
	return Price<2,T>((-1)*cents1/100,cents1%100);
}
#endif //FIXED_POINT2_FIXEDPOINT_H
