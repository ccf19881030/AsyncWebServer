//
// Created by plter on 5/27/15.
//

#ifndef PROJECT_HTTPFILTER_H
#define PROJECT_HTTPFILTER_H

#include "Filter.h"

namespace aws {
    class HttpFilter: public aws::Filter {

    public:
        virtual void onAccept(std::shared_ptr<aws::Connection> sock) override;

        virtual void onReceive(std::shared_ptr<aws::Connection> sock, void * msg) override;

        virtual void onClose(std::shared_ptr<aws::Connection> sock) override;
    };
}


#endif //PROJECT_HTTPFILTER_H
