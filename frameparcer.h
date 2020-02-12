#ifndef FRAMEPARCER_H
#define FRAMEPARCER_H


#include <boost/regex.hpp>
#include <deque>
class ParcedData
{
public:
    ParcedData(std::vector<int32_t> data, int32_t time): data_(data), time_(time){}
private:
    std::vector<int32_t> data_;
    int32_t time_;
};

class FrameParcer
{
public:
    FrameParcer(boost::regex regex, std::size_t buf_size): regex_(regex), buf_size_(buf_size){}
    virtual ~FrameParcer(){}
    bool put_data(std::vector<char> data);
    std::vector<ParcedData> get_parced_data();
    uint8_t* get_pnt();

private:
    boost::regex regex_;
    std::deque<char> buf_;
    std::string string_;
    std::vector<ParcedData> parced_data_;
    std::size_t buf_size_;
};

#endif // FRAMEPARCER_H
