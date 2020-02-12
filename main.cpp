#include <QCoreApplication>
#include <regex>
#include <iostream>
#include "frameparcer.h"
#include <boost/regex.hpp>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    //\x0c\x00\x00\xff\xff\xbd\x00
//    std::regex exp("\x07e\x00\x00\xff\xff\xbd\x00");
    boost::regex exp("\x7e\x00\xff\xff\xbd");

//    uint8_t test_data[] = {0xde,0xdd,0xee,0xff,0xbd,0xed};
    uint8_t test_data1[] = {0x7e,0x00,0x00,0xff,0xff,0xbd,0x00,0x01};
    std::vector<char> data_vec(test_data1, test_data1+sizeof(test_data1));
    FrameParcer parcer(exp, 1000);
    if(!parcer.put_data(data_vec))
        std::cout << "nope" << std::endl;
    return a.exec();
}
