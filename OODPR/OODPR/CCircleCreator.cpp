#include "CCircleCreator.h"
#include "CCircle.h"
#include "ICreator.h"

shared_ptr<CShapeDecorator> CircleCreator::CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) 
{
	auto tempShape = make_shared<CShape>();
	shared_ptr<CShapeDecorator> shape;
	shape = make_shared<CCircle>(move(tempShape), x1, y1, radius);
	shape->setParameters(shape->GetCircleColor(), shape->GetOutlineColor(), shape->GetOutlineThickness());
	return shape;
}

CircleCreator* CircleCreator::GetInstanceC()
{
	if (!instanciateC)
	{
		instanciateC = new CircleCreator();
	}
	return instanciateC;
}

CircleCreator* CircleCreator::instanciateC = 0;


