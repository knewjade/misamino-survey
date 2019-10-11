cmake_minimum_required (VERSION 3.8)

include(../../vars/misamino.cmake)
include(../../vars/misamino_survey_src.cmake)
include(../../vars/misamino_survey_test.cmake)

project(misamino_survey_test_win64)

# Compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-m64 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")  # -march=native -s
#set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -march=native -DNDEBUG")

# Build defines
include_directories(${googletest_SOURCE_DIR}/include)
include_directories(${googlemock_SOURCE_DIR}/include)
include_directories(${misamino_survey_src_SOURCE_DIR})
include_directories(${misamino_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${misamino_SRC} ${misamino_survey_src_SRC} ${misamino_survey_test_SRC})

target_link_libraries(${PROJECT_NAME}
        gtest
        gtest_main
        gmock
        gmock_main
        )
