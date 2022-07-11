function C1 = get_totally_unimodular_linear_program_C1(embb_users_num, base_stations_num)
  C1 = get_block_diagonal_matrix(ones(1, base_stations_num), embb_users_num);
end
