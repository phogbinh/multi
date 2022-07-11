addpath(genpath("../ml"));

TOLERANCE = importdata("./ml/tolerance.txt");

embb_users_num = 2;
base_stations_num = 1;
subchannels_num = 1;
embb_users_peak_rates = [8;
                         6];
embb_users_multiconnectivity_capabilities = [1;
                                             1];
first_embb_users_moving_average_rates = [1;
                                         1];
second_embb_users_moving_average_rates = [4.5;
                                          0.5];
third_embb_users_moving_average_rates = [2.25;
                                         3.25];

%% FirstTimeSlotTest
[alpha, gamma] = get_online_embb_policy(embb_users_peak_rates, embb_users_multiconnectivity_capabilities, first_embb_users_moving_average_rates, embb_users_num, base_stations_num, subchannels_num);
assert(isequal(size(alpha), [2, 1]));
assert(abs(alpha(1) - 1) <= TOLERANCE);
assert(abs(alpha(2) - 0) <= TOLERANCE);
assert(isequal(size(gamma), [2, 1]));
assert(abs(gamma(1) - 1) <= TOLERANCE);

%% SecondTimeSlotTest
[alpha, gamma] = get_online_embb_policy(embb_users_peak_rates, embb_users_multiconnectivity_capabilities, second_embb_users_moving_average_rates, embb_users_num, base_stations_num, subchannels_num);
assert(isequal(size(alpha), [2, 1]));
assert(abs(alpha(1) - 0) <= TOLERANCE);
assert(abs(alpha(2) - 1) <= TOLERANCE);
assert(isequal(size(gamma), [2, 1]));
assert(abs(gamma(2) - 1) <= TOLERANCE);

%% ThirdTimeSlotTest
[alpha, gamma] = get_online_embb_policy(embb_users_peak_rates, embb_users_multiconnectivity_capabilities, third_embb_users_moving_average_rates, embb_users_num, base_stations_num, subchannels_num);
assert(isequal(size(alpha), [2, 1]));
assert(abs(alpha(1) - 1) <= TOLERANCE);
assert(abs(alpha(2) - 0) <= TOLERANCE);
assert(isequal(size(gamma), [2, 1]));
assert(abs(gamma(1) - 1) <= TOLERANCE);
