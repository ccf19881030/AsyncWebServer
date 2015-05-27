//
// Created by plter on 5/24/15.
//

#include "DataInputMessage.h"


aws::DataInputMessage::DataInputMessage(aws::InputDataBuffer &buffer, std::size_t bytes_transferred_) {
    buffer_ = buffer;
    bytes_transferred = bytes_transferred_;
}
