cmake_minimum_required (VERSION 3.16)
project(TSTL VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(TSTL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TSTL_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")
set(TSTL_EXPORT_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/export_headers")

# add header files from headers directory

file(GLOB_RECURSE  TSTL_SOURCE_FILES
     "${TSTL_SOURCE_DIR}/*.cpp"
     "${TSTL_HEADER_DIR}/*.h"
      "${TSTL_EXPORT_HEADER_DIR}/*.h"
     "${TSTL_SOURCE_DIR}/*.c"
     )

add_subdirectory(TSTL_Library)
list(APPEND EXTRA_LIBS TSTL_Library)


add_executable(TSTL ${TSTL_SOURCE_FILES})
target_include_directories(TSTL PUBLIC ${TSTL_HEADER_DIR})
target_include_directories(TSTL PUBLIC ${TSTL_EXPORT_HEADER_DIR})
target_link_libraries(TSTL PUBLIC ${EXTRA_LIBS})
target_include_directories(TSTL PUBLIC ${PROJECT_BINARY_DIR}/headers)
target_include_directories(TSTL PUBLIC ${PROJECT_BINARY_DIR}/export_header)
