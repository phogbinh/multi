addpath(genpath("../ml"));

EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");

%% GetTotallyUnimodularLinearProgramC2Test
C2 = get_totally_unimodular_linear_program_C2(EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
C2_actuality = importdata("./ml/C2_actuality.txt");
assert(isequal(C2, C2_actuality));
