#pragma once
#include "CShapeDecorator.h"

class CRectangle : public CShapeDecorator
{
public:

	CRectangle(shared_ptr<IShape>&& shape, float x1, float y1, float x2, float y2) :
		p1(x1, y1),
		p2(x2, y2),
		CShapeDecorator(move(shape))
	{
		float l1 = p2.GetY() - p1.GetY(), l2 = p2.GetX() - p1.GetX();
		Vector2f vect1(l1, l2);
		rectangle.setSize(vect1);
		rectangle.setPosition(p1.GetX(), p1.GetY());
	};

	float CalculatePerimeter() override;
	float CalculateArea() override;
	string GetType() const;
	void Draw(RenderWindow& window) override;

	void setParameters(Color shapeColor, Color outlineColor, float outlineThickness) override
	{
		rectangle.setFillColor(shapeColor);
		rectangle.setOutlineColor(outlineColor);
		rectangle.setOutlineThickness(outlineThickness);
	}

private:
	RectangleShape rectangle;
	string type = "RECTANGLE";
	CPoint p1, p2;
};

