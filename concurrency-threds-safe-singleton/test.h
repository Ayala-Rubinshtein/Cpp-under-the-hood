//
// Created by mby on 06/08/2020.
//

#ifndef SIGNELTON_TEST_H
#define SIGNELTON_TEST_H

#include "singleton.h"
#include <iostream>

/*namespace using std::cout;
namespace std::endl;*/

class Test{

public:
    Test();

};

inline Test::Test()
{
    std::cout<<"function test"<<std::endl;
}

inline void testSingleton()
{
    Test t1 = Singleton<Test>::getInstance();
    Test t2 = Singleton<Test>::getInstance();
    Test t3 = Singleton<Test>::getInstance();
    Test t4 = Singleton<Test>::getInstance();
    Singleton<int>::getInstance();
}

#endif //SIGNELTON_TEST_H
