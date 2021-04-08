#pragma once
#include "ICreator.h"


class RectangleCreator : public ICreator
{
private:
	static RectangleCreator *instanciateR;
	RectangleCreator() {}
	~RectangleCreator() {}
public:
	void operator=(const RectangleCreator&) = delete;
	static RectangleCreator* GetInstanceR();
	shared_ptr<CShapeDecorator> CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) override;
};
