#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "IVisitor.h"

class IVisitor;

class IShape
{
public:
	virtual float GetPerimeter() const = 0;
	virtual float GetArea() const = 0;
	virtual void SetPerimeter(float perimeter) = 0;
	virtual void SetArea(float area) = 0;
	virtual void Accept(IVisitor& visitor) = 0;
private:
};