#pragma once

#include <string>
#include <vector>

#include "sqlite/sqlite3.h"

namespace data
{
    class SongTable
    {
        static const std::string table_;
        std::string name_;
        std::string path_;

        sqlite3 *db;
        sqlite3_stmt *stmt;

    public:
        SongTable();
        SongTable(const std::string &name, const std::string &path);
        void init();
        void insert(const std::string &name, const std::string &path);
        void deleteRow(const std::string &path);
        std::vector<SongTable> getAll();
        std::string name() const;
        std::string path() const;
    };
} // namespace data