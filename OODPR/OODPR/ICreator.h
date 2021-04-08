#pragma once
#include "CShapeDecorator.h"
#include "CShape.h"

class ICreator
{
public:
	virtual shared_ptr<CShapeDecorator> CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) = 0;
};