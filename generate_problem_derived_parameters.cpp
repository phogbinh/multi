#include <bits/stdc++.h>
#include "Parser.h" // Parser, Parameters
#include "generate_problem_derived_parameters.h"

using namespace std;

int main() {
  freopen("problem_derived_parameters.txt", "w", stdout);
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  int subcarrierSpacing = GetSubcarrierSpacing(parameters.NUMEROLOGY);
  printf("SUBCARRIER_SPACING=%d kHz\n", subcarrierSpacing);
  printf("SUBCHANNEL_BANDWIDTH=%d Hz\n", GetSubchannelBandwidth(subcarrierSpacing));
  double timeSlotDuration = GetTimeSlotDuration(parameters.NUMEROLOGY);
  printf("TIME_SLOT_DURATION=%f s\n", timeSlotDuration);
  printf("TIME_MINISLOT_DURATION=%f s\n", GetTimeMinislotDuration(timeSlotDuration, parameters.TIME_MINISLOTS_NUM));
  return 0;
}
