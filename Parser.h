struct Parameters {
  int BASE_FREQUENCY;
};

class Parser {
public:
  // output @ parameters
  void GetParameters(Parameters& parameters) {
    parameters.BASE_FREQUENCY = 28;
  }
private:
};
