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
$MATLAB_DIR/matlab -batch "runtests({'get_block_diagonal_matrix_test', 'get_totally_unimodular_linear_program_e_test', 'get_totally_unimodular_linear_program_d_test', 'get_totally_unimodular_linear_program_C1_test', 'get_totally_unimodular_linear_program_C2_test', 'get_totally_unimodular_linear_program_C4_test', 'get_totally_unimodular_linear_program_C_test', 'get_online_embb_policy_test.m'})"
