function C2 = get_totally_unimodular_linear_program_C2(embb_users_num, base_stations_num, subchannels_num)
  C2 = [eye(embb_users_num * base_stations_num * subchannels_num), get_block_diagonal_matrix(-ones(subchannels_num, 1), embb_users_num * base_stations_num)];
end
