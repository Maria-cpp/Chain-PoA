cmake_minimum_required(VERSION 3.16)
project(chain-PoA)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_LIST_DIR}/*.h)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(chainpoalib STATIC ${headers} ${sources})
target_link_libraries(chainpoalib spdlog protocollib)
target_include_directories(chainpoalib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
