//
// Created by plter on 5/22/15.
//

#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H

#include <memory>
#include <string>
#include <boost/asio/buffer.hpp>

namespace aws {
    class Data{
    friend class Socket;
    public:
        Data(std::string & str);
        virtual ~Data();
        static std::shared_ptr<aws::Data> dataFromString(std::string str);

    private:
        boost::asio::const_buffers_1 & getAsioBuffer();

    private:
        boost::asio::const_buffers_1 asio_buffer_;
    };
}

#endif //PROJECT_DATA_H
