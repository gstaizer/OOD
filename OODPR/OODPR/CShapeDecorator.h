#pragma once
#include "IShape.h"
#include "CPoint.h"
#include <string>

using namespace std;
using namespace sf;

class CShapeDecorator : public IShape
{
public:

	CShapeDecorator(shared_ptr<IShape>&& shape) :
		shape(move(shape))
	{};

	void SetPerimeter(float peremeter) override {};
	void SetArea(float area) override {};

	void SetPerimeter()
	{
		shape->SetPerimeter(CalculatePerimeter());
	}

	void SetArea()
	{
		shape->SetArea(CalculateArea());
	}
	
	float GetPerimeter() const override
	{
		return shape->GetPerimeter();
	}

	float GetArea() const override
	{
		return shape->GetArea();
	}

	Color GetTriangleColor() const
	{
		return this->triangleColor;
	}

	Color GetRectangleColor() const
	{
		return this->rectangleColor;
	}

	Color GetCircleColor() const
	{
		return this->circleColor;
	}

	Color GetOutlineColor() const
	{
		return this->outlineColor;
	}
	
	float GetOutlineThickness() const
	{
		return this->outlineThickness;
	}

	void Accept(IVisitor& visitor) override
	{
		visitor.VisitType(*this);
		visitor.VisitPerimeter(*this);
		visitor.VisitArea(*this);
	}

	virtual float CalculatePerimeter() = 0;
	virtual float CalculateArea() = 0;
	virtual string GetType() const = 0;
	virtual void Draw(RenderWindow& window) = 0;
	virtual void setParameters(Color shapeColor, Color outlineColor, float outlineThickness) = 0;

private:
	shared_ptr<IShape> shape;
	const Color triangleColor = Color(255, 0, 0, 255), rectangleColor = Color(0, 0, 255, 255),
		circleColor = Color(0, 255, 0, 255), outlineColor = Color(0, 0, 0, 255);
	const float outlineThickness = 10;
};