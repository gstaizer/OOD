#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CShape.h"
#include "CShapeFactory.h"
#include "CShapeVisitor.h"
#include "DataInteraction.h"

using namespace std;

const string inputFile = "input.txt", outputFile = "output.txt";

int main()
{
    ifstream input;
    ofstream output;
    input.open(inputFile);
    output.open(outputFile);

    DataInteraction dataInteraction;
    vectShapes shapes = dataInteraction.InputInfo(input);
    dataInteraction.OutputInfo(shapes, output);
    dataInteraction.DrawShape(shapes);

    return 0;
}