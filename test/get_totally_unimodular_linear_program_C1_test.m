addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
EMBB_USERS_NUM = importdata("./ml/embb_users_num.txt");
BASE_STATIONS_NUM = importdata("./ml/base_stations_num.txt");

%% GetTotallyUnimodularLinearProgramC1Test
C1 = get_totally_unimodular_linear_program_C1(EMBB_USERS_NUM, BASE_STATIONS_NUM);
C1_actuality = importdata("./ml/C1_actuality.txt");
assert(isequal(size(C1), size(C1_actuality)));
for row_mli = 1 : numel(C1_actuality(:, 1))
  for col_mli = 1 : numel(C1_actuality(1, :))
    assert(abs(C1(row_mli, col_mli) - C1_actuality(row_mli, col_mli)) <= TOLERANCE);
  end
end
