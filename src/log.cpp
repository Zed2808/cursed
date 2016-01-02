#include <string>
#include <list>
#include "log.hpp"

void Log::write(std::string s) {
    if(log.size() >= 10) {
        log.pop_back();
    }
    log.push_front(s);
}
