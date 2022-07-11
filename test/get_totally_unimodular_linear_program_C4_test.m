addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");

%% GetTotallyUnimodularLinearProgramC4Test
C4 = get_totally_unimodular_linear_program_C4(EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
C4_actuality = importdata("./ml/C4_actuality.txt");
assert(isequal(size(C4), size(C4_actuality)));
for row_mli = 1 : numel(C4_actuality(:, 1))
  for col_mli = 1 : numel(C4_actuality(1, :))
    assert(abs(C4(row_mli, col_mli) - C4_actuality(row_mli, col_mli)) <= TOLERANCE);
  end
end
