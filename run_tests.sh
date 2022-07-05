#!/bin/sh
rm -r ./build
cmake -S ./ -B ./build
cmake --build ./build
cd ./build
./generate_problem_derived_parameters_test
