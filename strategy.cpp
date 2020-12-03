#include <iostream>
#include <memory>

static constexpr float PI = 3.14159265359;

class Shape {
 public:
  virtual float area() const = 0;
};

class Circle : public Shape {
 private:
  float radius;

 public:
  Circle(float radius) : radius(radius) {}

  float area() const override { return PI * radius * radius; }
};

class Rectangle : public Shape {
 private:
  float width;
  float height;

 public:
  Rectangle(float width, float height) : width(width), height(height) {}

  float area() const override { return width * height; }
};

int main() {
  std::shared_ptr<Shape> shape;

  shape = std::make_shared<Rectangle>(2, 2);
  std::cout << shape->area() << std::endl;

  shape = std::make_shared<Circle>(1.0);
  std::cout << shape->area() << std::endl;

  return 0;
}