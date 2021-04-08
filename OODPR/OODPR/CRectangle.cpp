#include "CRectangle.h"


float CRectangle::CalculatePerimeter()
{
    float l1 = p2.GetY() - p1.GetY();
    float l2 = p2.GetX() - p1.GetX();
    return 2 * l1 + 2 * l2;
}

float CRectangle::CalculateArea()
{
    float l1 = p2.GetY() - p1.GetY();
    float l2 = p2.GetX() - p1.GetX();
    return l1 * l2;
}

string CRectangle::GetType() const
{
    return type;
}

void CRectangle::Draw(RenderWindow& window)
{
    window.draw(rectangle);
}

