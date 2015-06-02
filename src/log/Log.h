//
// Created by plter on 6/2/15.
//

#ifndef PROJECT_LOG_H
#define PROJECT_LOG_H


#include <iosfwd>
#include <string>

namespace aws {
    class Log {

    public:
        static void info(std::string msg);

        static bool on;
    };
}


#endif //PROJECT_LOG_H
