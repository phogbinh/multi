addpath(genpath("../ml"));

EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");

%% GetTotallyUnimodularLinearProgramC4Test
C4 = get_totally_unimodular_linear_program_C4(EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
C4_actuality = importdata("./ml/C4_actuality.txt");
assert(isequal(C4, C4_actuality));
