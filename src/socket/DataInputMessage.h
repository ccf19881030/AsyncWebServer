//
// Created by plter on 5/24/15.
//

#ifndef PROJECT_DATAMESSAGE_H
#define PROJECT_DATAMESSAGE_H


#include <memory>
#include "DataOutput.h"
#include "Message.h"
#include "Buffer.h"

namespace aws {
    class DataInputMessage: public aws::Message {
    public:
        DataInputMessage(aws::Buffer & buffer);

    public:
        inline aws::Buffer getBuffer(){
            return buffer_;
        }

    private:
        aws::Buffer buffer_;
    };
}


#endif //PROJECT_DATAMESSAGE_H
