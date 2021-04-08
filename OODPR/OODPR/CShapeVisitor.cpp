#include "CShapeVisitor.h"

using namespace std;

void CShapeVisitor::VisitType(CShapeDecorator& shape) const
{
	output << shape.GetType();
}

void CShapeVisitor::VisitPerimeter(CShapeDecorator& shape) const
{
	output << P << shape.GetPerimeter();
}

void CShapeVisitor::VisitArea(CShapeDecorator& shape) const
{
	output << S << shape.GetArea();
}