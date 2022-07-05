#include <bits/stdc++.h>

int GetSubcarrierSpacing(const int numerology) {
  return (int)pow(2.0, (double)numerology) * 15;
}

int GetSubchannelBandwidth(const int subcarrierSpacing) {
  return 12 * subcarrierSpacing * (int)1E3;
}

double GetTimeSlotDuration(const int numerology) {
  return pow(2.0, -(double)numerology) * 1E-3;
}
