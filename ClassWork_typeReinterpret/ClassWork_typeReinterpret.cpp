
#include <iostream>

class Shape
{
protected:
public:
	virtual float area(float a, float b)
	{
		return a * b;
	}
};

class Rectangle :public Shape
{
private:
public:
	float area(float a, float b) override
	{
		return Shape::area(a, b);
	}
};
class Triangle : public Shape
{
private:
public:
	float area(float a, float h) override
	{
		return Shape::area(a, h) / 2;
	}
};

float compare(Shape* &first, Shape* &second)
{
	if (first->area(10, 5) > second->area(10, 11))
	{
		return first->area(10, 5);
	}
	else
	{
		return second->area(10, 11);
	}
}

int main()
{
	Rectangle test1;
	Triangle test2;
	Shape* help1 = static_cast<Shape*>(&test1);
	Shape* help2 = static_cast<Shape*>(&test2);
	std::cout << compare(help1, help2) << '\n'; //(Rectangle, Triangle)

}
