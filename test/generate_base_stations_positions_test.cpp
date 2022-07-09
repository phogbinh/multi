#include <gtest/gtest.h>
#include "../Vector3Int.h"
#include "../generate_base_stations_positions.h"

TEST(GenerateBaseStationsPositionsTest, GetBaseStationsPositionsTest) {
  vector<Vector3Int> positions;
  GetBaseStationsPositions(positions);
  EXPECT_EQ(positions[0].GetX(), 300);
  EXPECT_EQ(positions[0].GetY(), 300);
  EXPECT_EQ(positions[0].GetZ(), 100);
  EXPECT_EQ(positions[1].GetX(), 500);
  EXPECT_EQ(positions[1].GetY(), 700);
  EXPECT_EQ(positions[1].GetZ(), 100);
  EXPECT_EQ(positions[2].GetX(), 700);
  EXPECT_EQ(positions[2].GetY(), 300);
  EXPECT_EQ(positions[2].GetZ(), 100);
}
