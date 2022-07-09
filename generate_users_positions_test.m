addpath(genpath("ml"));

POINTS_NUM = 11;

parameters = get_parameters();
for time_slot_idx = 0 : parameters.TIME_SLOTS_NUM - 1
  embb_users_positions = importdata(get_embb_users_positions_filepath(time_slot_idx));
  for time_minislot_idx = 0 : parameters.TIME_MINISLOTS_NUM - 1
    urllc_users_positions = importdata(get_urllc_users_positions_filepath(time_slot_idx, time_minislot_idx));
    hold off; % new plot
    current_plot = plot(embb_users_positions(:, 1), embb_users_positions(:, 2), "ob");
    hold on;
    plot(urllc_users_positions(:, 1), urllc_users_positions(:, 2), "+r");
    xlim([parameters.MINIMUM_X parameters.MAXIMUM_X]);
    ylim([parameters.MINIMUM_Y parameters.MAXIMUM_Y]);
    xticks(linspace(parameters.MINIMUM_X, parameters.MAXIMUM_X, POINTS_NUM));
    yticks(linspace(parameters.MINIMUM_Y, parameters.MAXIMUM_Y, POINTS_NUM));
    hgsave(current_plot, "./bin/users-" + time_slot_idx + "-" + time_minislot_idx + ".png");
  end
end
