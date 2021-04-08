#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:

	void SetPerimeter(float perimeter) override
	{
		this->perimeter = perimeter;
	}

	void SetArea(float area) override
	{
		this->area = area;
	}

	float GetPerimeter() const override
	{
		return perimeter;
	}

	float GetArea() const override
	{
		return area;
	}

	void Accept(IVisitor& visitor) override
	{}

private:
	float perimeter = 0;
	float area = 0;
};