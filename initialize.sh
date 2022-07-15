cd $MULTI_DIR
rm -r ./bin
mkdir ./bin
g++ generate_base_stations_positions.cpp -o ./bin/generate_base_stations_positions && ./bin/generate_base_stations_positions
cat ./base_stations_positions.txt
rm -r ./users_positions
mkdir ./users_positions
g++ generate_users_begin_end_positions.cpp -o ./bin/generate_users_begin_end_positions && ./bin/generate_users_begin_end_positions
ls ./users_positions
$MATLAB_DIR/matlab -batch "run ./ml/generate_users_positions.m"
rm -r ./users_peak_rates
mkdir ./users_peak_rates
g++ generate_users_peak_rates.cpp -o ./bin/generate_users_peak_rates && ./bin/generate_users_peak_rates
g++ generate_embb_users_multiconnectivity_capabilities.cpp -o ./bin/generate_embb_users_multiconnectivity_capabilities && ./bin/generate_embb_users_multiconnectivity_capabilities
rm -r ./urllc_users_demands
mkdir ./urllc_users_demands
g++ generate_urllc_users_demands.cpp -o ./bin/generate_urllc_users_demands && ./bin/generate_urllc_users_demands
