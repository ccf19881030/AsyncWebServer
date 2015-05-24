//
// Created by plter on 5/24/15.
//


#include <stdio.h>
#include <functional>

template <typename T>
T max(T a,T b){
    return a>b?a:b;
}

int main(){

    printf("Max value is %d",max(3,6));

    return 0;
}