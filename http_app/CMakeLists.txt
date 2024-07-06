set(ENV{SPDLOG_LEVEL} debug)
find_package(oatpp REQUIRED)
find_package(oatpp-swagger REQUIRED)
find_package(oatpp-sqlite REQUIRED)
include_directories(
    ${CMAKE_SOURCE_DIR}/lib 
    ${OpenMP_CXX_INCLUDE} 
    ${oatpp_INCLUDE_DIRS}
    ${oatpp_swagger_INCLUDE_DIRS}
    ${oatpp_sqlite_INCLUDE_DIRS}
)
add_library(
    http_lib
    src/AppComponent.hpp
    src/dto/PageDto.hpp
    src/dto/UserDto.hpp
    src/dto/StatusDto.hpp
    src/ErrorHandler.cc
    src/ErrorHandler.hpp
    src/controller/StaticController.hpp
    src/service/UserService.cpp
    src/service/UserService.hpp
    src/controller/UserController.hpp
)
option(DOATPP_SQLITE_AMALGAMATION ON)
target_include_directories(http_lib PUBLIC src)
find_package(SQLite3 REQUIRED)

target_link_libraries(http_lib
       PUBLIC SQLite::SQLite3
)
target_link_libraries(
    http_lib
    PUBLIC oatpp::oatpp
    PUBLIC oatpp::oatpp-swagger
    PUBLIC oatpp::oatpp-sqlite
)

add_definitions(
        ## define path to swagger-ui static resources folder
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        ## SQLite database file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"
        ## SQLite database test file
        -DTESTDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/test-db.sqlite"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(http_lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()
# set(CMAKE_CXX_FLAGS "-framework Cocoa")
add_executable(http_app 
    src/App.cc
)
target_link_libraries(http_app  http_lib utility core curl spdlog::spdlog )