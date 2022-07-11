function d = get_totally_unimodular_linear_program_d(embb_users_multiconnectivity_capabilities, embb_users_num, base_stations_num, subchannels_num)
  d = [embb_users_multiconnectivity_capabilities                     ;
       zeros(embb_users_num * base_stations_num * subchannels_num, 1);
       ones(embb_users_num * base_stations_num, 1)                   ;
       ones(base_stations_num * subchannels_num, 1)                  ];
end
