function filepath = get_embb_users_positions_filepath(time_slot_idx)
  filepath = getenv("MULTI_DIR") + "users_positions/embb-" + time_slot_idx + ".txt";
end
