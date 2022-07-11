function C1 = get_totally_unimodular_linear_program_C1(embb_users_num, base_stations_num)
  diagonal_element = ones(1, base_stations_num);
  diagonal_cell = {diagonal_element};
  diagonal_cells = repmat(diagonal_cell, 1, embb_users_num);
  C1 = blkdiag(diagonal_cells{:});
end
