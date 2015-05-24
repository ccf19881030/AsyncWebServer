//
// Created by plter on 5/21/15.
//


#include <iostream>
#include <vector>

class A{

};


class B:public A{

public:

    void sayB(){
        std::cout<<"Hello B\n";
    }
};

int main(){
    std::shared_ptr<A> b(new B());
    std::shared_ptr<B> r_b = std::static_pointer_cast<B>(b);

    r_b->sayB();
    std::cout<<"End\n";
    return 0;
}