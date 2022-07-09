#include <bits/stdc++.h>

// input @ numerology
// output @ [kHz]
int GetSubcarrierSpacing(const int numerology) {
  return (int)pow(2.0, (double)numerology) * 15;
}

// input @ subcarrierSpacing[kHz]
// output @ [Hz]
int GetSubchannelBandwidth(const int subcarrierSpacing) {
  return 12 * subcarrierSpacing * (int)1E3;
}

// input @ numerology
// output @ [s]
double GetTimeSlotDuration(const int numerology) {
  return pow(2.0, -(double)numerology) * 1E-3;
}

// input @ timeSlotDuration[s], timeMinislotsNum
// output @ [s]
double GetTimeMinislotDuration(const double timeSlotDuration, const int timeMinislotsNum) {
  return timeSlotDuration / (double)timeMinislotsNum;
}

// input @ baseFrequency[GHz], subchannelIdx, subchannelBandwidth[Hz]
// output @ [GHz]
double GetSubchannelFrequency(const int baseFrequency, const size_t subchannelIdx, const int subchannelBandwidth) {
  return (double)baseFrequency + (double)subchannelIdx * 1E-9 * (double)subchannelBandwidth;
}
