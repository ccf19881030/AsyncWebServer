//
// Created by plter on 5/24/15.
//

#ifndef PROJECT_DATAMESSAGE_H
#define PROJECT_DATAMESSAGE_H


#include <memory>
#include "Buffer.h"

namespace aws {
    class InputBufferMessage {
    public:
        InputBufferMessage(aws::InputBuffer & buffer,std::size_t bytes_transferred);

    public:
        inline aws::InputBuffer & getBuffer(){
            return buffer_;
        }
        inline std::size_t getBytesTransferred(){
            return bytes_transferred;
        }


    private:
        aws::InputBuffer buffer_;
        std::size_t bytes_transferred;
    };
}


#endif //PROJECT_DATAMESSAGE_H
