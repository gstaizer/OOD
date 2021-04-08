#pragma once
#include "CShapeDecorator.h"

class CTriangle : public CShapeDecorator
{
public:

	CTriangle(shared_ptr<IShape>&& shape, float x1, float y1, float x2, float y2, float x3, float y3)
		: p1(x1, y1),
		p2(x2, y2),
		p3(x3, y3),
		CShapeDecorator(move(shape))
	{
	};

	float CalculatePerimeter() override;
	float CalculateArea() override;
	string GetType() const;
	void Draw(RenderWindow& window) override;

	void setParameters(Color shapeColor, Color outlineColor, float outlineThickness) override
	{
		triangle.setFillColor(shapeColor);
		triangle.setOutlineColor(outlineColor);
		triangle.setOutlineThickness(outlineThickness);
	}

private:
	ConvexShape triangle;
	string type = "TRIANGLE";
	CPoint p1, p2, p3;
};

