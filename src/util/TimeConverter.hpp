#pragma once

#include <string>

namespace util
{
    class TimeConverter
    {
    public:
        TimeConverter();
        static std::string msToMinSec(const long &ms);
    };

} // namespace util