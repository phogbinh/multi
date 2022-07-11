function C4 = get_totally_unimodular_linear_program_C4(embb_users_num, base_stations_num, subchannels_num)
  C4 = repmat(eye(base_stations_num * subchannels_num), 1, embb_users_num);
end
