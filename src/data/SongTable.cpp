#include "SongTable.hpp"

#include <sstream>

namespace data
{
#define db_name "data.db"

    const std::string SongTable::table_ = "song";

    SongTable::SongTable() {}

    SongTable::SongTable(const std::string &name, const std::string &path)
    {
        name_ = name;
        path_ = path;
    }

    void SongTable::init()
    {
        sqlite3_open(db_name, &db);
        std::stringstream command;
        command << "CREATE TABLE IF NOT EXISTS " << SongTable::table_ << "(name varchar(255), path varchar(260));";
        sqlite3_exec(db, command.str().c_str(), NULL, NULL, NULL);
        sqlite3_close(db);
    }

    void SongTable::insert(const std::string &name, const std::string &path)
    {
        sqlite3_open(db_name, &db);
        std::stringstream command;
        command << "INSERT INTO " << SongTable::table_ << "(name, path) VALUES('" << name << "', '" << path << "');";
        sqlite3_exec(db, command.str().c_str(), NULL, NULL, NULL);
        sqlite3_close(db);
    }

    void SongTable::deleteRow(const std::string &path)
    {
        sqlite3_open(db_name, &db);
        std::stringstream command;
        command << "DELETE FROM " << SongTable::table_ << " WHERE path = '" << path << "';";
        sqlite3_exec(db, command.str().c_str(), NULL, NULL, NULL);
        sqlite3_close(db);
    }

    std::vector<SongTable> SongTable::getAll()
    {
        sqlite3_open(db_name, &db);
        std::stringstream command;
        command << "SELECT * FROM " << SongTable::table_ << ";";
        sqlite3_prepare(db, command.str().c_str(), -1, &stmt, NULL);
        std::vector<SongTable> result;
        while (sqlite3_step(stmt) != SQLITE_DONE)
        {
            result.push_back(
                SongTable(
                    std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0))),
                    std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)))));
        }
        sqlite3_finalize(stmt);
        sqlite3_close(db);

        return result;
    }

    std::string SongTable::name() const
    {
        return name_;
    }

    std::string SongTable::path() const
    {
        return path_;
    }

} // namespace data