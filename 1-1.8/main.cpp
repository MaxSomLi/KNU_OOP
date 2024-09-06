#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main()
{
    RenderWindow app(VideoMode(800, 800), "Graph handling");

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
            if (event.type == sf::Event::Closed)
                app.close();
        app.clear();

        app.display();
    }

    return 0;
}
