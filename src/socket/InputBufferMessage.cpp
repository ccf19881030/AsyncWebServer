//
// Created by plter on 5/24/15.
//

#include "InputBufferMessage.h"


aws::InputBufferMessage::InputBufferMessage(aws::InputBuffer &buffer, std::size_t bytes_transferred_) {
    buffer_ = buffer;
    bytes_transferred = bytes_transferred_;
}
