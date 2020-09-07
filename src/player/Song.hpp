#pragma once

#include <string>

namespace player
{

    class Song
    {
        std::string name_;
        std::string path_;

    public:
        Song(const std::string &path);

        std::string name() const;
        std::string path() const;
    };

} // namespace player