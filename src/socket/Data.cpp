//
// Created by plter on 5/22/15.
//

#include "Data.h"

std::shared_ptr<aws::Data> aws::Data::dataFromString(std::string str) {
    return std::shared_ptr<aws::Data>(new Data(str));
}

boost::asio::const_buffers_1 &aws::Data::getAsioBuffer() {
    return asio_buffer_;
}

aws::Data::Data(std::string &str):asio_buffer_(boost::asio::buffer(str)) {

}
