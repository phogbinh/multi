addpath(genpath("../ml"));

EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");

%% GetTotallyUnimodularLinearProgramC1Test
C1 = get_totally_unimodular_linear_program_C1(EMBB_USERS_NUM, BASE_STATIONS_NUM);
C1_actuality = importdata("./ml/C1_actuality.txt");
assert(isequal(C1, C1_actuality));
