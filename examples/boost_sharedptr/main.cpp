//
// Created by plter on 5/21/15.
//


#include <iostream>
#include <boost/smart_ptr.hpp>

class A{

public:

    A(int a):b(20){
        a_ = a;
    };

    void sayHello(){
        std::cout<<b<<" "<<a_<<" Hello World\n";
    }

    virtual ~A(){
        std::cout<<"Delete A\n";
    }

private:
    int a_;

public:
    int b;
};


class B{

public:
    B():ap_(A(1)){
        ap_.sayHello();
    };

private:
    A ap_;
};


int main(){


//    A* ap = new A();
//    boost::shared_ptr<A> a(ap);
//
////    boost::shared_ptr<A> b(a);
////    b->sayHello();
//
//    a.reset();
//
//    if (!a){
//        std::cout<<"a is null\n";
//    }
//
//    std::cout<<"End\n";

    B b;

    return 0;
}