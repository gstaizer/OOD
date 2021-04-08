#include "DataInteraction.h"
using namespace std;

vectShapes DataInteraction::InputInfo(istream& input) {
    vectShapes shapes;
    CShapeFactory* factory = CShapeFactory::GetInstanceF();
    string str;
    
    while (!input.eof())
    {
        input >> str;
        shared_ptr<CShapeDecorator> shape = factory->CreateShape(str, input);
        shapes.push_back(shape);
    }

    return shapes;
}

void DataInteraction::OutputInfo(vectShapes shapes, ostream& output)
{
    CShapeVisitor visitor(output);
    for (unsigned int i = 0; i < shapes.size(); ++i)
    {
        shapes[i]->Accept(visitor);
        output << endl;
    }
}

void DataInteraction::DrawShape(vectShapes shapes)
{
    RenderWindow window(VideoMode({ 500, 600 }), TITLE);
    const Color colorShape = Color(255, 229, 180, 255);
    window.clear();

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(colorShape);

        for (unsigned int i = 0; i < shapes.size(); ++i)
        {
            shapes[i]->Draw(window);
        }

        window.display();
    }
};