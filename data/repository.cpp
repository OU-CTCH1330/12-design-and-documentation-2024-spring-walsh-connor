#include "repository.h"
#include <stdexcept>

namespace ctch1330::data
{
    std::string Repository::filename = "bin/lms.db";

    int Repository::GetConnection(sqlite3** db_connection)
    {
        int connection_result = sqlite3_open(filename.c_str(), db_connection);
        if( connection_result == SQLITE_OK ){ return 0; }
        throw std::runtime_error( "Database connection could not be initiated" );
    }

    int Repository::CloseConnection(sqlite3* db_connection)
    {
        return sqlite3_close(db_connection);
    }

}