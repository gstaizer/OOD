#pragma once
#include "IShape.h"

class CShapeDecorator;

class IVisitor
{
public:
	virtual void VisitType(CShapeDecorator& shape) const = 0;
	virtual void VisitPerimeter(CShapeDecorator& shape) const = 0;
	virtual void VisitArea(CShapeDecorator& shape) const = 0;
};
