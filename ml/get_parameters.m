function parameters = get_parameters()
  parameters = Parameters;
  file_id = fopen(getenv("MULTI_DIR") + "problem_parameters.txt", "rt");
  while ~feof(file_id)
    line = fgetl(file_id);
    equal_mli = regexp(line, "=");
    space_mli = regexp(line, " ");
    value = -1;
    if ~isempty(space_mli) % has unit
      value = str2num(line(equal_mli + 1 : 1 : space_mli - 1));
    else
      value = str2num(line(equal_mli + 1 : 1 : end));
    end
    key = line(1 : 1 : equal_mli - 1);
    if key == "TIME_SLOTS_NUM"
      parameters.TIME_SLOTS_NUM = value;
    elseif key == "TIME_MINISLOTS_NUM"
      parameters.TIME_MINISLOTS_NUM = value;
    elseif key == "EMBB_USERS_NUM"
      parameters.EMBB_USERS_NUM = value;
    elseif key == "URLLC_USERS_NUM"
      parameters.URLLC_USERS_NUM = value;
    elseif key == "MINIMUM_X"
      parameters.MINIMUM_X = value;
    elseif key == "MAXIMUM_X"
      parameters.MAXIMUM_X = value;
    elseif key == "MINIMUM_Y"
      parameters.MINIMUM_Y = value;
    elseif key == "MAXIMUM_Y"
      parameters.MAXIMUM_Y = value;
    end
  end
  fclose(file_id);
end
