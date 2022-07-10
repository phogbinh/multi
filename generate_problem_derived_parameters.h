#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES // M_PI
#define MINIMUM_FREQUENCY 25000000 // [Hz]
#define LIGHT_SPEED 3E8 // [m/s]
#define PATH_LOSS_EXPONENT 2.0
#define SHADOWING_STANDARD_DEVIATION 4.6 // [dB]

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

// input @ baseFrequency[Hz], subchannelIdx, subchannelBandwidth[Hz]
// output @ [Hz]
long long int GetSubchannelFrequency(const long long int baseFrequency, const size_t subchannelIdx, const int subchannelBandwidth) {
  return baseFrequency + (long long int)subchannelIdx * (long long int)subchannelBandwidth;
}

// input @ frequency[Hz], distance[m]
// output @ [dB]
double GetPathLossShadowing(const long long int frequency, const double distance) {
  if (frequency < MINIMUM_FREQUENCY) {
    throw runtime_error("frequency is smaller than minimum frequency");
  }
  if (distance < 1.0) {
    throw runtime_error("distance is smaller than 1");
  }
  return 20.0 * log10(4.0 * M_PI * (double)frequency / LIGHT_SPEED) + 10.0 * PATH_LOSS_EXPONENT * log10(distance) + SHADOWING_STANDARD_DEVIATION;
}
