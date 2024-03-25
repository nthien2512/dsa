template <class P>
class Point {
  private:
    P x;
    P y;
  public:
    Point(P x = 0, P y = 0) : x(x), y(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
      return os << "(" << point.x << ", " << point.y << ")";
    }
    bool operator!=(const Point& other) const {
      return x != other.x || y != other.y;
    }
};