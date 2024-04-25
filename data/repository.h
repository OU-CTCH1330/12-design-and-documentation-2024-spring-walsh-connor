#pragma once

#include <string>
#include <sqlite3.h> 


namespace ctch1330::data
{
    class Repository
    {
        public:
            static int GetConnection(sqlite3** db);

            static int CloseConnection(sqlite3* db);

        private:

            static std::string filename;

    };

}
