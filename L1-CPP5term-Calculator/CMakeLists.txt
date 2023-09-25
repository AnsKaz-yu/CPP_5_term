cmake_minimum_required(VERSION 3.26)
project(L1-CPP5term-Calculator)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS Calculator.h PluginsLoader.h)
add_executable(L1-CPP5term-Calculator ${PROJECT_SOURCE_DIR}/ main.cpp Calculator.cpp PluginsLoader.cpp)
add_library(sin SHARED ./plugins/sin.cpp "plugins/sin.cpp")
add_library(cos SHARED ./plugins/cos.cpp "plugins/cos.cpp")
add_library(tg SHARED ./plugins/tg.cpp "plugins/tg.cpp")
add_library(sqrt SHARED ./plugins/sqrt.cpp "plugins/sqrt.cpp")
add_library(ln SHARED ./plugins/ln.cpp "plugins/ln.cpp")
#target_link_libraries(L1-CPP5term-Calculator sin cos tg ctg sqrt ln)