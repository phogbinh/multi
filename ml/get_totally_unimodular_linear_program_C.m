function C = get_totally_unimodular_linear_program_C(embb_users_num, base_stations_num, subchannels_num)
  C = [zeros(embb_users_num, embb_users_num * base_stations_num * subchannels_num)                    , get_totally_unimodular_linear_program_C1(embb_users_num, base_stations_num)   ;
       get_totally_unimodular_linear_program_C2(embb_users_num, base_stations_num, subchannels_num)                                                                                   ;
       zeros(embb_users_num * base_stations_num, embb_users_num * base_stations_num * subchannels_num), eye(embb_users_num * base_stations_num)                                       ;
       get_totally_unimodular_linear_program_C4(embb_users_num, base_stations_num, subchannels_num)   , zeros(base_stations_num * subchannels_num, embb_users_num * base_stations_num)];
end
