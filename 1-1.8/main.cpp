#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int main()
{
    RenderWindow app(VideoMode(800, 800), "Graph handling");
    int x = Mouse::getPosition(app).x, y = Mouse::getPosition(app).y, coordsSize = 0;
    vector<Vector2f> nodeCoords;
    bool isPressed = 0;
    app.setMouseCursorVisible(0);
    Texture cursorTexture;
    cursorTexture.loadFromFile("cursor.png");
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
            if (event.type == Event::Closed)
                app.close();
        app.clear(Color::White);
        x = Mouse::getPosition(app).x;
        y = Mouse::getPosition(app).y;
        Sprite cursor;
        cursor.setTexture(cursorTexture);
        cursor.setScale(app.getSize().x / 4000.f, app.getSize().x / 4000.f);
        if (isPressed)
            cursor.setScale(app.getSize().x / 9000.f, app.getSize().x / 9000.f);
        cursor.setOrigin(cursor.getLocalBounds().width / 2, cursor.getLocalBounds().height / 2);
        cursor.setPosition(x, y);
        app.draw(cursor);
        if (Mouse::isButtonPressed(Mouse::Left))
            isPressed = 1;
        if (event.type == Event::MouseButtonReleased && isPressed)
        {
            isPressed = 0;
            nodeCoords.push_back({x, y});
            coordsSize++;
        }
        for (int i = 0; i < coordsSize; i++)
        {
            CircleShape node(app.getSize().x / 80.f);
            node.setFillColor(Color::Blue);
            node.setOrigin(app.getSize().x / 80.f, app.getSize().x / 80.f);
            node.setPosition(nodeCoords[i]);
            app.draw(node);
        }
        app.display();
    }

    return 0;
}
