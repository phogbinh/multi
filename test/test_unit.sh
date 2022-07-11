cd $MULTI_DIR/test
rm -r ./build
cmake -S ./ -B ./build
cmake --build ./build
cd ./build
./communications_test
./parser_test
./Vector3Int_test
./generate_base_stations_positions_test
./UsersBeginEndPositionsGenerator_test
./EmbbUsersMulticonnectivityCapabilitiesGenerator_test
cd ..
$MATLAB_DIR/matlab -batch "runtests('get_totally_unimodular_linear_program_e_test')"
$MATLAB_DIR/matlab -batch "runtests('get_totally_unimodular_linear_program_d_test')"
