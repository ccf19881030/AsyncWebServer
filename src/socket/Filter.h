//
// Created by plter on 5/24/15.
//

#ifndef PROJECT_FILTER_H
#define PROJECT_FILTER_H


#include <memory>
#include "Connection.h"

namespace aws {

    class Filter {

    public:
        virtual void onAccept(std::shared_ptr<aws::Connection> sock){};
        virtual void onReceive(std::shared_ptr<aws::Connection> sock,void* message){};
        virtual void onClose(std::shared_ptr<aws::Connection> sock){};

    public:
        inline void setNext(std::shared_ptr<aws::Filter> next){
            next_ = next;
        };
        inline std::shared_ptr<aws::Filter> getNext(){
            return next_;
        }
        inline void setPre(std::shared_ptr<aws::Filter> pre){
            pre_ = pre;
        };
        inline std::shared_ptr<aws::Filter> getPre(){
            return pre_;
        }

    private:
        std::shared_ptr<aws::Filter> next_,pre_;
    };
}


#endif //PROJECT_FILTER_H
