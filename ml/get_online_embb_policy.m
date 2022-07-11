function [alpha, gamma] = get_online_embb_policy(embb_users_peak_rates, embb_users_multiconnectivity_capabilities, embb_users_moving_average_rates, embb_users_num, base_stations_num, subchannels_num)
  alpha_size = embb_users_num * base_stations_num * subchannels_num;
  C = get_totally_unimodular_linear_program_C(embb_users_num, base_stations_num, subchannels_num);
  d = get_totally_unimodular_linear_program_d(embb_users_multiconnectivity_capabilities, embb_users_num, base_stations_num, subchannels_num);
  e = get_totally_unimodular_linear_program_e(embb_users_peak_rates, embb_users_moving_average_rates, embb_users_num, base_stations_num);
  cvx_begin quiet
    variable x(alpha_size + embb_users_num * base_stations_num)
    maximize(e' * x)
    subject to
      C * x <= d
      x >= 0
  cvx_end
  alpha = x(1 : alpha_size);
  gamma = x(alpha_size + 1 : end);
end
