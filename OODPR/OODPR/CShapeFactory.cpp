#include "CShapeFactory.h"
#include "CTriangleCreator.h"
#include "CRectangleCreator.h"
#include "CCircleCreator.h"

using namespace std;

float CShapeFactory::GetDot(istream& input)
{
    string str;
    input >> str;
    str.erase(str.size() - 1);
    
    return stof(str.c_str());
}


CShapeFactory* CShapeFactory::GetInstanceF()
{
    if (!instanciateF)
    {
        instanciateF = new CShapeFactory();
    }
    return instanciateF;
}

shared_ptr<CShapeDecorator> CShapeFactory::CreateShape(const string& type, istream& input)
{
    shared_ptr<CShapeDecorator> shape;
    string str; 
    float x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, radius = 0;

    if (type == RECTANGLE || type == TRIANGLE || type == CIRCLE)
    {
        input >> str;
        if (str == P1 || str == C)
        {
            x1 = GetDot(input);
            y1 = GetDot(input);
        }

        if (type == CIRCLE)
        {
            input >> str;
            if (str == R)
            {
                radius = GetDot(input);
            }

            CircleCreator* circleCreator = CircleCreator::GetInstanceC();
            shape = circleCreator->CreateCurrentShape(x1, y1, x2, y2, x3, y3, radius);
        }
        else if (type == RECTANGLE || type == TRIANGLE)
        {
            input >> str;
            if (str == P2)
            {
                x2 = GetDot(input);
                y2 = GetDot(input);
            }

            if (type == RECTANGLE)
            {
                RectangleCreator* rectangleCreator = RectangleCreator::GetInstanceR();
                shape = rectangleCreator->CreateCurrentShape(x1, y1, x2, y2, x3, y3, radius);
            }

            if (type == TRIANGLE)
            {
                input >> str;
                if (str == P3)
                {
                    x3 = GetDot(input);
                    y3 = GetDot(input);
                }
                
                TriangleCreator* triangleCreator = TriangleCreator::GetInstanceT();
                shape = triangleCreator->CreateCurrentShape(x1, y1, x2, y2, x3, y3, radius);
            }
        }
        shape->SetPerimeter();
        shape->SetArea();
    }

    return shape;
}

CShapeFactory* CShapeFactory::instanciateF = 0;