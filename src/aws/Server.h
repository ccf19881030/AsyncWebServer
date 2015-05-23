//
// Created by plter on 5/23/15.
//

#ifndef PROJECT_APPLICATION_H
#define PROJECT_APPLICATION_H


#include <socket/ServerSocket.h>
#include "LuaLoader.h"

namespace aws {

    class Server {

    public:
        Server();

    public:
        void exit(int code);
        bool loadConfig(char * config_file_name);
        int getServerPort();
        void start();

    private:
        aws::LuaLoader luaLoader_;
        std::shared_ptr<aws::ServerSocket> serverSocket_;
        bool config_file_loaded_;
    };


}

#endif //PROJECT_APPLICATION_H
