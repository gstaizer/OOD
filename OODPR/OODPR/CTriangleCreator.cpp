#include "CTriangleCreator.h"
#include "CTriangle.h"
#include "ICreator.h"

shared_ptr<CShapeDecorator> TriangleCreator::CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) 
{
	auto tempShape = make_shared<CShape>();
	shared_ptr<CShapeDecorator> shape;
	shape = make_shared<CTriangle>(move(tempShape), x1, y1, x2, y2, x3, y3);
	shape->setParameters(shape->GetTriangleColor(), shape->GetOutlineColor(), shape->GetOutlineThickness());
	return shape;
}

TriangleCreator* TriangleCreator::GetInstanceT()
{
	if (!instanciateT)
	{
		instanciateT = new TriangleCreator();
	}
	return instanciateT;
}

TriangleCreator* TriangleCreator::instanciateT = 0;


