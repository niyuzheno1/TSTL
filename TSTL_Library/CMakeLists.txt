cmake_minimum_required (VERSION 3.16)
project(TSTL_Library VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include(FetchContent)

FetchContent_Declare(
    MMS
    GIT_REPOSITORY https://github.com/niyuzheno1/MMS.git
    GIT_TAG        33be400f59ff706e45f35d381063cbd20392344b  # release-1.0.0
)

FetchContent_MakeAvailable(MMS)
list(APPEND EXTRA_LIBS MMS_Library)
list(APPEND EXTRA_HEADER_DIRS ${MMS_SOURCE_DIR}/export_headers)



file(GLOB_RECURSE  TSTL_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.c
     )
    



add_library(TSTL_Library ${TSTL_SOURCE_FILES})
target_include_directories(TSTL_Library  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_include_directories(TSTL_Library  PUBLIC ${EXTRA_HEADER_DIRS})
target_link_libraries(TSTL_Library ${EXTRA_LIBS})

# install(TARGETS TSTL_Library DESTINATION lib)
# install(FILES ???.h DESTINATION include)