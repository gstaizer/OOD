#include "CCircle.h"


float CCircle::CalculatePerimeter()
{
    return 2 * pi * radius;
}

float CCircle::CalculateArea()
{
    return pi * pow(radius, 2);
}

string CCircle::GetType() const
{
    return type;
}

void CCircle::Draw(RenderWindow& window)
{
    window.draw(circle);
}