//
// Created by plter on 5/21/15.
//


#include <iostream>
#include <boost/smart_ptr.hpp>

class A{

public:

    void sayHello(){
        std::cout<<"Hello World\n";
    }

    virtual ~A(){
        std::cout<<"Delete A\n";
    }
};


int main(){


    A* ap = new A();
    boost::shared_ptr<A> a(ap);

//    boost::shared_ptr<A> b(a);
//    b->sayHello();

    a.reset();

    if (!a){
        std::cout<<"a is null\n";
    }

    std::cout<<"End\n";

    return 0;
}