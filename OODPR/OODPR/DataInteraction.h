#pragma once
#include <iostream>
#include <fstream>
#include "CShapeDecorator.h"
#include "CShape.h"
#include "CShapeFactory.h"
#include "CShapeVisitor.h"
#include <vector>

using namespace std;

typedef vector<shared_ptr<CShapeDecorator>> vectShapes;

class DataInteraction
{
public:
	vectShapes InputInfo(istream& input);
	void OutputInfo(vectShapes shapes, ostream& output);
	void DrawShape(vectShapes shapes);
private:
	const string RECTANGLE = "RECTANGLE:", TRIANGLE = "TRIANGLE:", CIRCLE = "CIRCLE:", TITLE = "OODPR";
};