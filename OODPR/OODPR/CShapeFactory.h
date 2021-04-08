#pragma once
#include "CCircle.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CShapeDecorator.h"
#include "CShape.h"
#include "IShape.h"
#include <memory>
#include <string>

using namespace std;

class CShapeFactory
{
private:
	const string RECTANGLE = "RECTANGLE:", TRIANGLE = "TRIANGLE:", CIRCLE = "CIRCLE:", P1 = "P1=", P2 = "P2=", P3 = "P3=", R = "R=", C = "C=";
	static CShapeFactory *instanciateF;
	CShapeFactory() {}
	~CShapeFactory() {}
public:
	shared_ptr<CShapeDecorator> CreateShape(const string& type, istream& input);
	float GetDot(istream& input);
	void operator=(const CShapeFactory&) = delete;
	static CShapeFactory* GetInstanceF();

};
