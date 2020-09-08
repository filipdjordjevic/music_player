#include "Song.hpp"

namespace player
{

    Song::Song(const std::string &path)
    {
        this->path_ = path;
        char name[255]; // max filename
        _splitpath(path.c_str(), NULL, NULL, name, NULL);
        this->name_ = name;
    }

    std::string Song::path() const
    {
        return this->path_;
    }

    std::string Song::name() const
    {
        return this->name_;
    }

} // namespace player