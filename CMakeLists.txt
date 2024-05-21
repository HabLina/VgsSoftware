cmake_minimum_required(VERSION 3.24)
project(eksamenSoftwareV2024)

set(CMAKE_CXX_STANDARD 17)

#sQLite Library
add_library(sqlite3 sqlite3/sqlite3.c)
target_include_directories(sqlite3 PUBLIC sqlite3)

if (UNIX)
    target_link_libraries(sqlite3 pthread dl)
endif (UNIX)


# SQLiteCpp library
add_library(sqlitecpp
        sqlitecpp/src/Backup.cpp
        sqlitecpp/src/Column.cpp
        sqlitecpp/src/Database.cpp
        sqlitecpp/src/Exception.cpp
        sqlitecpp/src/Statement.cpp
        sqlitecpp/src/Transaction.cpp
        )

target_include_directories(sqlitecpp PUBLIC sqlitecpp/include)
target_link_libraries(sqlitecpp sqlite3)

# Program executable
add_executable(eksamenSoftwareV2024 main.cpp
        controllers/car.cpp
        controllers/customer.cpp
        controllers/customer.cpp)
target_link_libraries(eksamenSoftwareV2024 sqlite3 sqlitecpp) #her skal vi definere alle mappene vi skal bruke etterhvert