cd $MULTI_DIR
rm -r ./bin
mkdir ./bin
g++ generate_problem_derived_parameters.cpp -o ./bin/generate_problem_derived_parameters && ./bin/generate_problem_derived_parameters
cat ./problem_derived_parameters.txt
g++ generate_base_stations_positions.cpp -o ./bin/generate_base_stations_positions && ./bin/generate_base_stations_positions
cat ./base_stations_positions.txt
rm -r ./users_positions
mkdir ./users_positions
g++ generate_users_begin_end_positions.cpp -o ./bin/generate_users_begin_end_positions && ./bin/generate_users_begin_end_positions
ls ./users_positions
$MATLAB_DIR/matlab -batch "run ./ml/generate_users_positions.m"
