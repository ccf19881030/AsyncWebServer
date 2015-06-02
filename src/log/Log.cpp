//
// Created by plter on 6/2/15.
//

#include <iostream>
#include "Log.h"


bool aws::Log::on = true;

void aws::Log::info(std::string msg) {
    if (Log::on) {
        std::cout << msg << "\n";
    }
}
