#define SEED_CAPABILITY 1

class EmbbUsersMulticonnectivityCapabilitiesGenerator {
public:
  // input @ embbUsersNum, minCapability, maxCapability
  // output @ _capabilities
  EmbbUsersMulticonnectivityCapabilitiesGenerator(const int embbUsersNum, const int minCapability, const int maxCapability) {
    default_random_engine engine(SEED_CAPABILITY);
    uniform_int_distribution<int> uniform(minCapability, maxCapability);
    _capabilities.resize(embbUsersNum);
    for (int i = 0; i < embbUsersNum; ++i) {
      _capabilities[i] = uniform(engine);
    }
  }
  // output @ capabilities
  void GetCapabilities(vector<int>& capabilities) {
    capabilities = _capabilities;
  }
private:
  vector<int> _capabilities;
};
