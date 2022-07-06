#include <gtest/gtest.h>
#include "Parser.h"

TEST(ParserTest, GetParametersTest) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  EXPECT_EQ(parameters.BASE_FREQUENCY, 28);
}
