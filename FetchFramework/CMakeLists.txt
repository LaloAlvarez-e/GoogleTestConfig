cmake_minimum_required(VERSION 3.17)

# Set the project name
project(GoogleTestConfig)
set (EXECUTABLE_DIR ${CMAKE_BINARY_DIR}/bin)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Tests)

# add test option to enable testing
option(TEST "Enable testing" ON)

#if TEST option is enabled, then include the googletest framework
if(TEST)
    message("Testing is enabled")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.11.0
    )
    FetchContent_GetProperties(googletest)
    if(NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
        add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
        include_directories(${googletest_INCLUDE_DIRS})
    endif()
else()
    message("Testing is disabled")
endif()



# Add the library
add_library(sumLib STATIC sum.c)

# Include header files
target_include_directories(sumLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# Add the executable
add_executable(mainApp main.c)

# Set the output directory for the executable
set_target_properties(mainApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_DIR}
)

# Link the library to the executable
target_link_libraries(mainApp PRIVATE sumLib)


if(TEST)
    # Add the test executable
    add_executable(testApp ${TEST_DIR}/sumTest.cpp)

    # Include header files
    target_include_directories(testApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

    # Set the output directory for the executable
    set_target_properties(testApp PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_DIR}
    )
    # Link the library to the test executable
    target_link_libraries(testApp PRIVATE sumLib gtest_main gmock_main)
endif()

