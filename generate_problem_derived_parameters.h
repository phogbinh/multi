#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES // M_PI
#define MINIMUM_FREQUENCY 25000000 // [Hz]
#define LIGHT_SPEED 3E8 // [m/s]
#define PATH_LOSS_EXPONENT 2.0
#define SHADOWING_STANDARD_DEVIATION 4.6 // [dB]
#define TIME_SLOT_SYMBOLS_NUM 168 // 12 subcarriers * 14 symbols

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

// input @ transmittedPower[dB], pathLossShadowing[dB]
// output @ [dB]
double GetReceivedPower(const int transmittedPower, const double pathLossShadowing) {
  return (double)transmittedPower - pathLossShadowing;
}

// input @ thermalNoiseDensity[dB/Hz], subchannelBandwidth[Hz]
// output @ [dB]
int GetSubchannelThermalNoise(const int thermalNoiseDensity, const int subchannelBandwidth) {
  return (int)(10.0 * log10(pow(10.0, (double)thermalNoiseDensity / 10.0) * (double)subchannelBandwidth));
}

// input @ subchannelBandwidth[Hz], receivedPower[dB], subchannelThermalNoise[dB]
// output @ [bits/s]
double GetShannonRate(const int subchannelBandwidth, const double receivedPower, const int subchannelThermalNoise) {
  return (double)subchannelBandwidth * log2(1.0 + pow(10.0, (receivedPower - (double)subchannelThermalNoise) / 10.0));
}

// input @ subchannelBandwidth[Hz], receivedPower[dB], subchannelThermalNoise[dB], timeSlotDuration[s]
// output @ [bits/slot]
int GetTimeSlotPeakRate(const int subchannelBandwidth, const double receivedPower, const int subchannelThermalNoise, const double timeSlotDuration) {
  double shannonRate = (double)subchannelBandwidth * log2(1.0 + pow(10.0, (receivedPower - (double)subchannelThermalNoise) / 10.0)) * timeSlotDuration;
  return (int)floor(shannonRate / (double)TIME_SLOT_SYMBOLS_NUM) * TIME_SLOT_SYMBOLS_NUM;
}

// input @ subchannelBandwidth[Hz], receivedPower[dB], subchannelThermalNoise[dB], timeMinislotDuration[s], timeMinislotsNum
// output @ [bits/minislot]
int GetTimeMinislotPeakRate(const int subchannelBandwidth, const double receivedPower, const int subchannelThermalNoise, const double timeMinislotDuration, const int timeMinislotsNum) {
  double shannonRate = (double)subchannelBandwidth * log2(1.0 + pow(10.0, (receivedPower - (double)subchannelThermalNoise) / 10.0)) * timeMinislotDuration;
  int timeMinislotSymbolsNum = TIME_SLOT_SYMBOLS_NUM / timeMinislotsNum;
  return (int)floor(shannonRate / (double)timeMinislotSymbolsNum) * timeMinislotSymbolsNum;
}
