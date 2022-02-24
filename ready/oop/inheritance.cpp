#include <iostream>
#include <string>

using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    void set_shape_name(const string& shape_name)
    {
        _shape_name = shape_name;
    }
    void display()
    {
        cout << _shape_name << " area:" << area() << endl;
    }
private:
    string _shape_name;
};

class Triangle : public Shape
{
public:
    Triangle(double len = 0, double high = 0) : _len(len), _high(high) {}
    double area() const
    {
        return _len * _high * 0.5;
    }
    void draw() const
    {

    }

private:
    double _len;
    double _high;
};

class Rectangle : public Shape
{
public:
    Rectangle(double len = 0, double high = 0) : _len(len), _high(high) {}
    double area() const
    {
        return _len * _high;
    }
    void draw() const
    {

    }

private:
    double _len;
    double _high;
};

class Circle : public Shape
{
public:
    Circle(double radius = 0) : _radius(radius) {}
    double area() const
    {
        return _radius * _radius * 3.14;
    }
    void draw() const
    {

    }

private:
    double _radius;
};


int main(int argc, char const *argv[])
{
    const int SHAPE_NUM = 3;
    Shape* shapes[SHAPE_NUM];

    Triangle t(10, 10);
    Rectangle r(10, 10);
    Circle c(5);

    t.set_shape_name("Triangle");
    r.set_shape_name("Rectangle");
    c.set_shape_name("Circle");

    shapes[0] = &t;
    shapes[1] = &r;
    shapes[2] = &c;

    for (int i = 0; i < SHAPE_NUM; i++)
    {
        shapes[i]->display();
    }

    return 0;
}