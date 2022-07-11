addpath(genpath("../ml"));

EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");

%% GetTotallyUnimodularLinearProgramCTest
C = get_totally_unimodular_linear_program_C(EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
C_actuality = importdata("./ml/C_actuality.txt");
assert(isequal(C, C_actuality));
