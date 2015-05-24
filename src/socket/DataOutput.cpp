//
// Created by plter on 5/22/15.
//

#include <iostream>
#include "DataOutput.h"

std::shared_ptr<aws::DataOutput> aws::DataOutput::dataFromString(std::string str) {
    return std::shared_ptr<aws::DataOutput>(new DataOutput(str));
}

boost::asio::const_buffers_1 &aws::DataOutput::getAsioBuffer() {
    return asio_buffer_;
}

aws::DataOutput::DataOutput(std::string &str):asio_buffer_(boost::asio::buffer(str)) {

}

aws::DataOutput::~DataOutput() {
}
