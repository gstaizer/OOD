#pragma once
#include "CPoint.h"
#include "CShapeDecorator.h"

using namespace std;
using namespace sf;

class CCircle : public CShapeDecorator
{
public:
	CCircle(shared_ptr<IShape>&& shape, float x, float y, float radius)
		: CShapeDecorator(move(shape)),
		radius(radius)
	{
		circle.setRadius(radius);
		circle.setPosition(x, y);
	};

	float CalculatePerimeter() override;
	float CalculateArea() override;
	string GetType() const override;
	void Draw(RenderWindow& window) override;

	void setParameters(Color shapeColor, Color outlineColor, float outlineThickness) override
	{
		circle.setFillColor(shapeColor);
		circle.setOutlineColor(outlineColor);
		circle.setOutlineThickness(outlineThickness);
	}

private:
	CircleShape circle;
	float radius;
	const float pi = 3.14f;
	string type = "CIRCLE";
};

