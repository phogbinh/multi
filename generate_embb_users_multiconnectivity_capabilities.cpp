#include <bits/stdc++.h>
#include "parser.h"
#include "EmbbUsersMulticonnectivityCapabilitiesGenerator.h"

using namespace std;

int main() {
  Parameters parameters;
  GetParameters(parameters);
  EmbbUsersMulticonnectivityCapabilitiesGenerator generator(parameters.EMBB_USERS_NUM, parameters.MINIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY, parameters.MAXIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY);
  vector<int> capabilities;
  generator.GetCapabilities(capabilities);
  ofstream file;
  file.open(string(getenv("MULTI_DIR")) + "embb_users_multiconnectivity_capabilities.txt");
  for (auto capability : capabilities) {
    file << capability << endl;
  }
  file.close();
  return 0;
}
