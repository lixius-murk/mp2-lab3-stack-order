cmake_minimum_required(VERSION 3.5)
set(TEST_TARGET "tests")

# Находим файлы
file(GLOB TEST_SRC_FILES "*.cpp")
file(GLOB_RECURSE PROJECT_SRC_FILES "../src/*.cpp")

message(STATUS "Test sources: ${TEST_SRC_FILES}")
message(STATUS "Project sources: ${PROJECT_SRC_FILES}")

add_executable(${TEST_TARGET}
    ${TEST_SRC_FILES}
    ${PROJECT_SRC_FILES}
)

# Критически важно: добавляем include директории
target_include_directories(${TEST_TARGET} 
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../gtest
    ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/include
)

target_link_libraries(${TEST_TARGET} gtest)

set_target_properties(${TEST_TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)