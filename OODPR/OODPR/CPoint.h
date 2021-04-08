#pragma once
class CPoint
{
public:
	CPoint() {};
	CPoint(float x, float y) 
		: x(x), y(y) {};

	float GetX()
	{
		return x;
	}

	float GetY()
	{
		return y;
	}

	void SetX(float x)
	{
		this->x = x;
	}

	void SetY(float y)
	{
		this->y = y;
	}

	~CPoint() {};

private:
	float x = 0;
	float y = 0;
};