//
// Created by plter on 5/21/15.
//


#include <iostream>
#include <vector>

class Value{

public:
    virtual ~Value(){
        std::cout<<"Delete value\n";
    }
};


int main(){

    std::vector<std::shared_ptr<Value>> vec;
    vec.push_back(std::shared_ptr<Value>(new Value()));
    vec.pop_back();

    std::cout<<"End\n";
    return 0;
}