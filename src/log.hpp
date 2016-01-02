#ifndef LOG_H
#define LOG_H

#include <string>
#include <list>

class Log {
    public:
        std::list<std::string> log;
        void write(std::string s);
};

#endif
