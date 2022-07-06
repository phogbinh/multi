cmake_minimum_required(VERSION 3.14)
project(multi)
set(CMAKE_CXX_STANDARD 14) # googletest requires at least c++14
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(
  generate_problem_derived_parameters_test
  generate_problem_derived_parameters_test.cpp
)
target_link_libraries(
  generate_problem_derived_parameters_test
  gtest_main
)
add_executable(
  Parser_test
  Parser_test.cpp
)
target_link_libraries(
  Parser_test
  gtest_main
)
include(GoogleTest)
gtest_discover_tests(generate_problem_derived_parameters_test)
gtest_discover_tests(Parser_test)
