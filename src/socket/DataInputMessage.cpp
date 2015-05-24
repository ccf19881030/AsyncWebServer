//
// Created by plter on 5/24/15.
//

#include "DataInputMessage.h"


aws::DataInputMessage::DataInputMessage(std::array<char, 1024> &buffer) {
    buffer_ = buffer;
}
