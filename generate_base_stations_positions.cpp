#include <bits/stdc++.h>
#include "generate_base_stations_positions.h"

using namespace std;

int main() {
  freopen("base_stations_positions.txt", "w", stdout);
  vector<Vector3Int> positions;
  GetBaseStationsPositions(positions);
  for (size_t i = 0; i < positions.size(); ++i) {
    printf("%d,%d,%d\n", positions[i].GetX(), positions[i].GetY(), positions[i].GetZ());
  }
  return 0;
}
