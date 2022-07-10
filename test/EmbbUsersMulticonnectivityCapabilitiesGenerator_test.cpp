#include <gtest/gtest.h>
#include "../parser.h"
#include "../EmbbUsersMulticonnectivityCapabilitiesGenerator.h"

TEST(EmbbUsersMulticonnectivityCapabilitiesGeneratorTest, GetCapabilitiesTest) {
  Parameters parameters;
  GetParameters(parameters);
  EmbbUsersMulticonnectivityCapabilitiesGenerator generator(parameters.EMBB_USERS_NUM, parameters.MINIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY, parameters.MAXIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY);
  vector<int> capabilities;
  generator.GetCapabilities(capabilities);
  EXPECT_EQ(capabilities.size(), 100);
  // seed of capability is 1
  EXPECT_EQ(capabilities[0], 1);
  EXPECT_EQ(capabilities[50], 4);
}
