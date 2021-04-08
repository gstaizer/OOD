#pragma once
#include "ICreator.h"


class CircleCreator : public ICreator
{
private:
	static CircleCreator *instanciateC;
	CircleCreator() {}
	~CircleCreator() {}
public:
	void operator=(const CircleCreator&) = delete;
	static CircleCreator* GetInstanceC();
	shared_ptr<CShapeDecorator> CreateCurrentShape(float x1, float y1, float x2, float y2, float x3, float y3, float radius) override;
};