addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");
SUBCHANNELS_NUM = importdata("./ml/subchannels_num.txt");

%% GetTotallyUnimodularLinearProgramC2Test
C2 = get_totally_unimodular_linear_program_C2(EMBB_USERS_NUM, BASE_STATIONS_NUM, SUBCHANNELS_NUM);
C2_actuality = importdata("./ml/C2_actuality.txt");
assert(isequal(size(C2), size(C2_actuality)));
for row_mli = 1 : numel(C2_actuality(:, 1))
  for col_mli = 1 : numel(C2_actuality(1, :))
    assert(abs(C2(row_mli, col_mli) - C2_actuality(row_mli, col_mli)) <= TOLERANCE);
  end
end
