#pragma once
#include "ICreator.h"


class TriangleCreator : public ICreator
{
private:
	static TriangleCreator *instanciateT;
	TriangleCreator() {}
	~TriangleCreator() {}
public:
	void operator=(const TriangleCreator&) = delete;
	static TriangleCreator* GetInstanceT();
	shared_ptr<CShapeDecorator> CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) override;
};
