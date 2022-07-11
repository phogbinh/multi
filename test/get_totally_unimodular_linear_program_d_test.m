addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");
EMBB_USERS_MULTICONNECTIVITY_CAPABILITIES = importdata("./ml/embb_users_multiconnectivity_capabilities_data.txt");

%% GetTotallyUnimodularLinearProgramDTest
d = get_totally_unimodular_linear_program_d(EMBB_USERS_MULTICONNECTIVITY_CAPABILITIES, EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
d_actuality = importdata("./ml/d_actuality.txt");
assert(isequal(size(d), size(d_actuality)));
for mli = 1 : numel(d_actuality)
  assert(abs(d(mli) - d_actuality(mli)) <= TOLERANCE);
end
