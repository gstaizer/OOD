#pragma once
#include "IVisitor.h"
#include "CShapeDecorator.h"
#include <istream>
#include <memory>

using namespace std;

class CShapeVisitor : public IVisitor
{
public:
	CShapeVisitor(ostream& out)
		:output(out)
	{};

	void VisitType(CShapeDecorator& shape) const override;
	void VisitPerimeter(CShapeDecorator& shape) const override;
	void VisitArea(CShapeDecorator& shape) const override;
private:
	ostream& output;
	const string P = ": P=", S = ", S=";
};

