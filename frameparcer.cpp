#include "frameparcer.h"
#include <iostream>
#include <boost/regex.hpp>

bool FrameParcer::put_data(std::vector<char> data)
{
    using strmatch = boost::match_results<std::deque<char>::iterator>;
    strmatch match;
//    boost::smatch match;
    for(auto it = data.begin(); it != data.end(); ++it)
    {
        buf_.push_back(*it);

    }
    string_ += std::string(data.begin(), data.end());
    std::cout << string_.end() - string_.begin() << std::endl;
    boost::match_results<std::deque<char>::iterator> what;
    if(boost::regex_search(buf_.begin(), buf_.end(), what, regex_, boost::regex_constants::match_any ))
    {
        std::cout << "find" << std::endl;
//        for (auto it1 = what.begin(); it1!=what.end(); ++it1)
        {
            std::cout << buf_.begin() - what[5].first << std::endl;
            std::cout << buf_.begin() - what[5].second << std::endl;
            std::cout << buf_.begin() - what[6].first << std::endl;
            std::cout << buf_.begin() - what[6].second << std::endl;
            std::cout << buf_.begin() - what[0].first << std::endl;
            std::cout << buf_.begin() - what[0].second << std::endl;
//            std::cout << +(*it1->second) << std::endl;
//            std::cout << it1->matched << std::endl;
//            std::cout << what.suffix().length() << std::endl;
//            std::cout << what.prefix().length() << std::endl;
        }
//        for (auto it1 = buf_.begin(); it1!=match[0].second; ++it1)
//        {
//            buf_.pop_front();
//        }
//        for (auto it1 = buf_.begin(); it1!=buf_.end(); ++it1)
//        {
//            std::cout << ' ' << +*it1;
//        }
//        std::cout << std::endl;
        return true;
    }
    return false;
}

//bool FrameParcer::put_data(std::vector<char> data)
//{
//    std::smatch match;
//    std::stringstream stream;
//    for(auto it = data.begin(); it != data.end(); ++it)
//    {
//        char hex_string[20];
//        buf_.push_back(*it);
//        sprintf(hex_string, "%X", *it);
//        string_ += hex_string;
//    }
//    std::cout << string_ << std::endl;
//    if(std::regex_search(string_, match, regex_))
//    {
//        std::cout << "find" << std::endl;
//        for (auto it1 = match.begin(); it1!=match.end(); ++it1)
//        {
//            std::cout << +(*it1->first) << std::endl;
//            std::cout << +(*it1->second) << std::endl;
//            std::cout << it1->matched << std::endl;
//        }
//        string_.erase(match[0].first, match[0].second);
//        std::cout << string_ << std::endl;
//        return true;
//    }
//    return false;
//}
