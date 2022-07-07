class Vector3Int {
public:
  Vector3Int(int x, int y, int z) : _x(x), _y(y), _z(z) {
    // body intentionally empty
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
private:
  int _x = 0;
  int _y = 0;
  int _z = 0;
};
