//
// Created by plter on 5/21/15.
//

#ifndef PROJECT_AIOSOCKETACCEPTOR_H
#define PROJECT_AIOSOCKETACCEPTOR_H

#include <memory>
#include "Filter.h"
#include "ServerSocket.h"

namespace aws {
    class SocketAcceptor {

    public:
        SocketAcceptor(int port);

    public:
        void addFilter(std::shared_ptr<Filter> filter);
        void start();

    private:
        std::shared_ptr<aws::Filter> first_filter_,last_filter_;
        std::shared_ptr<aws::ServerSocket> server_;
    };
}


#endif //PROJECT_AIOSOCKETACCEPTOR_H
