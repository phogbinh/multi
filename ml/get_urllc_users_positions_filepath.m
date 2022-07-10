function filepath = get_urllc_users_positions_filepath(time_slot_idx, time_minislot_idx) % TODO test
  filepath = getenv("MULTI_DIR") + "users_positions/urllc-" + time_slot_idx + "-" + time_minislot_idx + ".txt";
end
