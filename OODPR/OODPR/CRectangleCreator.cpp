#include "CRectangleCreator.h"
#include "CRectangle.h"
#include "ICreator.h"

shared_ptr<CShapeDecorator> RectangleCreator::CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) 
{
	auto tempShape = make_shared<CShape>();
	shared_ptr<CShapeDecorator> shape;
	shape = make_shared<CRectangle>(move(tempShape), x1, y1, x2, y2);
	shape->setParameters(shape->GetRectangleColor(), shape->GetOutlineColor(), shape->GetOutlineThickness());
	return shape;
}

RectangleCreator* RectangleCreator::GetInstanceR()
{
	if (!instanciateR)
	{
		instanciateR = new RectangleCreator();
	}
	return instanciateR;
}

RectangleCreator* RectangleCreator::instanciateR = 0;