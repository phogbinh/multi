addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
EMBB_USERS_PEAK_RATES = importdata("./ml/embb_users_peak_rates.txt");
EMBB_USERS_MOVING_AVERAGE_RATES = importdata("./ml/embb_users_moving_average_rates.txt");

%% GetTotallyUnimodularLinearProgramETest
e = get_totally_unimodular_linear_program_e(EMBB_USERS_PEAK_RATES, EMBB_USERS_MOVING_AVERAGE_RATES, EMBB_USERS_NUM, BASE_STATIONS_NUM);
e_actuality = importdata("./ml/e_actuality.txt");
assert(numel(e), numel(e_actuality));
for mli = 1 : numel(e_actuality)
  assert(abs(e(mli) - e_actuality(mli)) <= TOLERANCE);
end
