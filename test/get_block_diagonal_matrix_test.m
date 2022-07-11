addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");
DIAGONAL_BLOCK = importdata("./ml/diagonal_block.txt");
DIAGONAL_BLOCKS_NUM = importdata("./ml/diagonal_blocks_num.txt");

%% GetBlockDiagonalMatrixTest
block_diagonal_matrix = get_block_diagonal_matrix(DIAGONAL_BLOCK, DIAGONAL_BLOCKS_NUM);
block_diagonal_matrix_actuality = importdata("./ml/block_diagonal_matrix_actuality.txt");
assert(isequal(size(block_diagonal_matrix), size(block_diagonal_matrix_actuality)));
for row_mli = 1 : numel(block_diagonal_matrix_actuality(:, 1))
  for col_mli = 1 : numel(block_diagonal_matrix_actuality(1, :))
    assert(abs(block_diagonal_matrix(row_mli, col_mli) - block_diagonal_matrix_actuality(row_mli, col_mli)) <= TOLERANCE);
  end
end
