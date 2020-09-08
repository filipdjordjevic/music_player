#include "TimeConverter.hpp"

#include <sstream>
#include <iomanip>

namespace util
{
    TimeConverter::TimeConverter() {}

    std::string TimeConverter::msToMinSec(const long &ms)
    {
        int m = ms / 60000;
        int s = (ms - 60000 * m) / 1000;
        std::stringstream ss;
        ss << m << ":" << std::setw(2) << std::setfill('0') << s;
        return ss.str();
    }
} // namespace util