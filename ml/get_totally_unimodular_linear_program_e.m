function e = get_totally_unimodular_linear_program_e(embb_users_peak_rates, embb_users_moving_average_rates, embb_users_num, base_stations_num)
  e = [embb_users_peak_rates ./ embb_users_moving_average_rates;
       zeros(embb_users_num * base_stations_num, 1)            ];
end
