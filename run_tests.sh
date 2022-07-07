#!/bin/sh
rm -r ./build
cmake -S ./ -B ./build
cmake --build ./build
cd ./build
./generate_problem_derived_parameters_test
./Parser_test
./Vector3Int_test
./generate_base_stations_positions_test
