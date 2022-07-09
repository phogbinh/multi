#include <cmath>

#ifndef VECTOR_3_INT_H
#define VECTOR_3_INT_H
class Vector3Int {
public:
  Vector3Int() {
    // body intentionally empty
  }
  Vector3Int(const Vector3Int& vector) : Vector3Int(vector._x, vector._y, vector._z) {
    // body intentionally empty
  }
  Vector3Int(int x, int y, int z) : _x(x), _y(y), _z(z) {
    // body intentionally empty
  }
  Vector3Int& operator=(const Vector3Int& vector) {
    if (this != &vector) {
      _x = vector._x;
      _y = vector._y;
      _z = vector._z;
    }
    return *this;
  }
  const int GetX() const {
    return _x;
  }
  const int GetY() const {
    return _y;
  }
  const int GetZ() const {
    return _z;
  }
  double GetDistanceTo(const Vector3Int& vector) {
    double x = (double)vector._x - (double)_x;
    double y = (double)vector._y - (double)_y;
    double z = (double)vector._z - (double)_z;
    return sqrt(x * x + y * y + z * z);
  }
private:
  int _x = 0;
  int _y = 0;
  int _z = 0;
};
#endif
