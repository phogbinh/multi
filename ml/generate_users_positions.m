parameters = get_parameters();
EMBB_USERS_BEGIN_POSITIONS = importdata(get_embb_users_positions_filepath(0                            ));
EMBB_USERS_END_POSITIONS   = importdata(get_embb_users_positions_filepath(parameters.TIME_SLOTS_NUM - 1));
paths = zeros(parameters.EMBB_USERS_NUM,...
              parameters.TIME_SLOTS_NUM,...
              3); % an embb user's path consists of time slots' positions
for embb_user_mli = 1 : parameters.EMBB_USERS_NUM
  xs = linspace(EMBB_USERS_BEGIN_POSITIONS(embb_user_mli, 1),...
                EMBB_USERS_END_POSITIONS(embb_user_mli, 1),...
                parameters.TIME_SLOTS_NUM);
  ys = linspace(EMBB_USERS_BEGIN_POSITIONS(embb_user_mli, 2),...
                EMBB_USERS_END_POSITIONS(embb_user_mli, 2),...
                parameters.TIME_SLOTS_NUM);
  zs = linspace(EMBB_USERS_BEGIN_POSITIONS(embb_user_mli, 3),...
                EMBB_USERS_END_POSITIONS(embb_user_mli, 3),...
                parameters.TIME_SLOTS_NUM);
  for time_slot_mli = 1 : parameters.TIME_SLOTS_NUM
    paths(embb_user_mli, time_slot_mli, 1) = floor(xs(time_slot_mli));
    paths(embb_user_mli, time_slot_mli, 2) = floor(ys(time_slot_mli));
    paths(embb_user_mli, time_slot_mli, 3) = floor(zs(time_slot_mli));
  end
end
for time_slot_mli = 1 : parameters.TIME_SLOTS_NUM
  positions = zeros(parameters.EMBB_USERS_NUM, 3);
  for embb_user_mli = 1 : parameters.EMBB_USERS_NUM
    for coordinate_mli = 1 : 3
      positions(embb_user_mli, coordinate_mli) = paths(embb_user_mli, time_slot_mli, coordinate_mli); % a time slot's positions consists of embb users' positions
    end
  end
  writematrix(positions, get_embb_users_positions_filepath(time_slot_mli - 1));
end
URLLC_USERS_BEGIN_POSITIONS = importdata(get_urllc_users_positions_filepath(0                            , 0                                ));
URLLC_USERS_END_POSITIONS   = importdata(get_urllc_users_positions_filepath(parameters.TIME_SLOTS_NUM - 1, parameters.TIME_MINISLOTS_NUM - 1));
paths = zeros(parameters.URLLC_USERS_NUM,...
              parameters.TIME_SLOTS_NUM,...
              parameters.TIME_MINISLOTS_NUM,...
              3); % a urllc user's path consists of (time slot, time minislot)s' positions
for urllc_user_mli = 1 : parameters.URLLC_USERS_NUM
  xs = linspace(URLLC_USERS_BEGIN_POSITIONS(urllc_user_mli, 1),...
                URLLC_USERS_END_POSITIONS(urllc_user_mli, 1),...
                parameters.TIME_SLOTS_NUM * parameters.TIME_MINISLOTS_NUM);
  ys = linspace(URLLC_USERS_BEGIN_POSITIONS(urllc_user_mli, 2),...
                URLLC_USERS_END_POSITIONS(urllc_user_mli, 2),...
                parameters.TIME_SLOTS_NUM * parameters.TIME_MINISLOTS_NUM);
  zs = linspace(URLLC_USERS_BEGIN_POSITIONS(urllc_user_mli, 3),...
                URLLC_USERS_END_POSITIONS(urllc_user_mli, 3),...
                parameters.TIME_SLOTS_NUM * parameters.TIME_MINISLOTS_NUM);
  for time_slot_mli = 1 : parameters.TIME_SLOTS_NUM
    for time_minislot_mli = 1 : parameters.TIME_MINISLOTS_NUM
      paths(urllc_user_mli, time_slot_mli, time_minislot_mli, 1) = floor(xs((time_slot_mli - 1) * parameters.TIME_MINISLOTS_NUM + time_minislot_mli));
      paths(urllc_user_mli, time_slot_mli, time_minislot_mli, 2) = floor(ys((time_slot_mli - 1) * parameters.TIME_MINISLOTS_NUM + time_minislot_mli));
      paths(urllc_user_mli, time_slot_mli, time_minislot_mli, 3) = floor(zs((time_slot_mli - 1) * parameters.TIME_MINISLOTS_NUM + time_minislot_mli));
    end
  end
end
for time_slot_mli = 1 : parameters.TIME_SLOTS_NUM
  for time_minislot_mli = 1 : parameters.TIME_MINISLOTS_NUM
    positions = zeros(parameters.URLLC_USERS_NUM, 3);
    for urllc_user_mli = 1 : parameters.URLLC_USERS_NUM
      for coordinate_mli = 1 : 3
        positions(urllc_user_mli, coordinate_mli) = paths(urllc_user_mli, time_slot_mli, time_minislot_mli, coordinate_mli); % a (time slot, time minislot)'s positions consists of urllc users' positions
      end
    end
    writematrix(positions, get_urllc_users_positions_filepath(time_slot_mli - 1, time_minislot_mli - 1));
  end
end
