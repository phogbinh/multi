cd $MULTI_DIR/test
../initialize.sh
rm -r ./bin
mkdir ./bin
$MATLAB_DIR/matlab -batch "run generate_users_positions_test.m"
