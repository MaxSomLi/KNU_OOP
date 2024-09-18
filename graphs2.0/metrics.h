#ifndef METRICS_H_INCLUDED
#define METRICS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "tinyfiledialogs.h"
#include <windows.h>
#include "cccc.h"
using namespace sf;
using namespace std;
int closestCharacter(Vector2i position, Text text, int len)
{
    for (int i = 0; i < len; i++)
        if (abs(text.findCharacterPos(i).x - position.x) < 10 && abs(text.findCharacterPos(i).y - position.y) < 10)
            return i;
    return -1;
}

int main()
{
    RenderWindow app(VideoMode(800, 800), "SELECTOR", Style::Titlebar | Style::Close);

    Font font;
    font.loadFromFile("digital-7 (mono).ttf");

    Text text;
    text.setCharacterSize(50);
    text.setFillColor(Color::White);
    text.setFont(font);
    text.setString("Select a .cpp file.");
    text.setColor(Color::Black);

    bool openExplorer = 0, isAffPressed = 0, openEditor = 0, isTextPressed = 0, isTextSelected = 0;
    int x, y, editTextY = 0, startIndex, endIndex, maxIndex, minIndex, help;
    string filePath;

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
            if (event.type == Event::Closed)
                app.close();

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            x = Mouse::getPosition(app).x;
            y = Mouse::getPosition(app).y;
            if (x > 350 && x < 450 && y > 350 && y < 450)
                isAffPressed = 1;
        }

        if (event.type == Event::MouseButtonReleased && isAffPressed)
        {
            isAffPressed = 0;
            x = Mouse::getPosition(app).x;
            y = Mouse::getPosition(app).y;
            if (x > 350 && x < 450 && y > 350 && y < 450)
                openExplorer = 1;
        }

        app.clear(Color::Cyan);
        app.draw(text);

        RectangleShape aff(Vector2f(100, 100));
        if (isAffPressed)
            aff.setSize(Vector2f(80, 80));
        aff.setFillColor(Color::Green);
        aff.setOutlineColor(Color::Black);
        aff.setOutlineThickness(5);
        aff.setOrigin(aff.getGlobalBounds().width / 2, aff.getGlobalBounds().height / 2);
        aff.setPosition(400, 400);
        app.draw(aff);

        if (openExplorer)
        {
            openExplorer = 0;
            auto f = tinyfd_openFileDialog("Select .cpp file", "", 0, {}, 0, 0);
            if (f != NULL)
            {
                filePath = string(f);
                app.close();
                openEditor = 1;
            }
        }

        app.display();
    }

    if (openEditor)
    {
        RenderWindow app(VideoMode(1000, 1000), "Editor", Style::Titlebar | Style::Close);

        Font font;
        font.loadFromFile("comicz.ttf");

        Text text;
        text.setCharacterSize(20);
        text.setFillColor(Color::White);
        text.setFont(font);
        text.setColor(Color::Black);

        ifstream file(filePath);
        string fileContents((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())), findString;
        int len = fileContents.length();
        text.setString(fileContents);
        file.close();

        while (app.isOpen())
        {
            Event event;
            while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    app.close();

                if (event.type == Event::MouseWheelMoved)
                    editTextY += 20 * event.mouseWheel.delta;
                editTextY = min(0, editTextY);
                editTextY = max(editTextY, 1000 - int(text.getGlobalBounds().height));
            }

            app.clear(Color::Cyan);
            text.setPosition(0, editTextY);

            if (isTextSelected)
            {
                maxIndex = max(startIndex, endIndex);
                minIndex = min(startIndex, endIndex);
                help = maxIndex - minIndex;
                findString = fileContents.substr(minIndex, help);
                for (int i = 0; i < minIndex - help; i++)
                    if (fileContents.substr(i, help) == findString)
                    {
                        for (int j = i; j < i + help; j++)
                        {
                            RectangleShape highlight(Vector2f(20, 20));
                            highlight.setFillColor(Color::Magenta);
                            highlight.setPosition(text.findCharacterPos(j));
                            app.draw(highlight);
                        }
                    }
                for (int i = minIndex; i < maxIndex; i++)
                {
                    RectangleShape highlight(Vector2f(20, 20));
                    highlight.setFillColor(Color::Yellow);
                    highlight.setPosition(text.findCharacterPos(i));
                    app.draw(highlight);
                }
                for (int i = maxIndex; i < len - help; i++)
                    if (fileContents.substr(i, help) == findString)
                    {
                        for (int j = i; j < i + help; j++)
                        {
                            RectangleShape highlight(Vector2f(20, 20));
                            highlight.setFillColor(Color::Magenta);
                            highlight.setPosition(text.findCharacterPos(j));
                            app.draw(highlight);
                        }
                    }
            }

            app.draw(text);

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (!isTextPressed)
                    isTextSelected = 0;
                if (isTextSelected)
                {
                    help = closestCharacter(Mouse::getPosition(app), text, len);
                    if (help > -1)
                        endIndex = help;
                }
                else
                {
                    help = closestCharacter(Mouse::getPosition(app), text, len);
                    if (help > -1)
                    {
                        isTextSelected = 1;
                        startIndex = help;
                        endIndex = help;
                    }
                }
                isTextPressed = 1;
            }

            if (event.type == Event::MouseButtonReleased)
                isTextPressed = 0;

            if (Mouse::isButtonPressed(Mouse::Right))
            {
                string command = "C:\\CCCC\\cccc.exe \"" + filePath + "\"";
                system(command.c_str());
                app.close();
                ofstream file(filePath);
                file << fileContents;
                file.close();
            }
            app.display();
        }
    }

    return 0;
}


#endif
