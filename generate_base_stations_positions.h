#include <bits/stdc++.h>
#include "Vector3Int.h"
#include "Parser.h"

using namespace std;

void GetBaseStationsPositions(vector<Vector3Int>& positions) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  ifstream file;
  file.open("./../base_stations_2d_positions.txt");
  positions.resize(parameters.BASE_STATIONS_NUM);
  for (int i = 0; i < parameters.BASE_STATIONS_NUM; ++i) {
    int x;
    int y;
    char comma;
    file >> x >> comma >> y;
    positions[i] = Vector3Int(x, y, parameters.BASE_STATION_Z);
  }
  file.close();
}
