#include <iostream>
#include "FixedPoint.h"
int main() {
	Price<2,int>num1(5,303);
	std::cout<<num1;
	 Price<2,int>num2(5,303);
	 Price<2,int>num3;
	 num3=num1*num2;
	std::cout<<num3;
    num3%=64;
	num3+=5;
	std::cout<<num3;
	num3-=num1;
	std::cout<<num3;
    std::cout<<num1;
    std::cout<<num2;

    num3=num1*num2;
	std::cout<<"num3 " <<num3;
	num3%=3;
	std::cout<<num3;
    return 0;
}
