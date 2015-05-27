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
        DataInputMessage(aws::InputDataBuffer & buffer,std::size_t bytes_transferred);

    public:
        inline aws::InputDataBuffer getBuffer(){
            return buffer_;
        }
        inline std::size_t getBytesTransferred(){
            return bytes_transferred;
        }


    private:
        aws::InputDataBuffer buffer_;
        std::size_t bytes_transferred;
    };
}


#endif //PROJECT_DATAMESSAGE_H
