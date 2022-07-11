function block_diagonal_matrix = get_block_diagonal_matrix(diagonal_block, diagonal_blocks_num)
  diagonal_cell = {diagonal_block};
  diagonal_cells = repmat(diagonal_cell, 1, diagonal_blocks_num);
  block_diagonal_matrix = blkdiag(diagonal_cells{:});
end
