addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");

%% GetTotallyUnimodularLinearProgramCTest
C = get_totally_unimodular_linear_program_C(EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
C_actuality = importdata("./ml/C_actuality.txt");
assert(isequal(size(C), size(C_actuality)));
for row_mli = 1 : numel(C_actuality(:, 1))
  for col_mli = 1 : numel(C_actuality(1, :))
    assert(abs(C(row_mli, col_mli) - C_actuality(row_mli, col_mli)) <= TOLERANCE);
  end
end
