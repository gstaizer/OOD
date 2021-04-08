#include "CTriangle.h"


float CTriangle::CalculatePerimeter()
{
	float l1 = sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2));
	float l2 = sqrt(pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2));
	float l3 = sqrt(pow(p3.GetX() - p1.GetX(), 2) + pow(p3.GetY() - p1.GetY(), 2));
	return l1 + l2 + l3;
}

float CTriangle::CalculateArea()
{
	float l1 = sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2));
	float l2 = sqrt(pow(p3.GetX() - p2.GetX(), 2) + pow(p3.GetY() - p2.GetY(), 2));
	float l3 = sqrt(pow(p3.GetX() - p1.GetX(), 2) + pow(p3.GetY() - p1.GetY(), 2));
	float perim = GetPerimeter() / 2;
	return sqrt(perim * (perim - l1) * (perim - l2) * (perim - l3));
}

string CTriangle::GetType() const
{
	return type;
}

void CTriangle::Draw(RenderWindow& window)
{
	triangle.setPointCount(3);

	Vector2f vect1(p1.GetX(), p1.GetY());
	Vector2f vect2(p2.GetX(), p2.GetY());
	Vector2f vect3(p3.GetX(), p3.GetY());
	
	triangle.setPoint(0, vect1);
	triangle.setPoint(1, vect2);
	triangle.setPoint(2, vect3);

	window.draw(triangle);
}
