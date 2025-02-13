#include <iostream>
#include <cmath>

class Figure {
public:
    virtual double area() const = 0;
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Figure {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    std::cout << "Площадь круга: " << circle.area() << std::endl;
    std::cout << "Площадь прямоугольника: " << rectangle.area() << std::endl;

    return 0;
}