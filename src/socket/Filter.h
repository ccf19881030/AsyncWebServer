//
// Created by plter on 5/24/15.
//

#ifndef PROJECT_FILTER_H
#define PROJECT_FILTER_H


#include <memory>
#include "Socket.h"
#include "Message.h"

namespace aws {

    class Filter {

    public:
        virtual void onAccept(std::shared_ptr<aws::Socket> sock){};
        virtual void onReceive(std::shared_ptr<aws::Socket> sock,std::shared_ptr<aws::Message> msg){};
        virtual void onClose(std::shared_ptr<aws::Socket> sock){};

    public:
        inline void setNext(std::shared_ptr<aws::Filter> next){
            next_ = next;
        };
        inline void setPre(std::shared_ptr<aws::Filter> pre){
            pre_ = pre;
        };

    private:
        std::shared_ptr<aws::Filter> next_,pre_;
    };
}


#endif //PROJECT_FILTER_H
