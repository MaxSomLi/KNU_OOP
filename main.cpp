#include <SFML/Graphics.hpp>
#include <fstream>
#include "tinyfiledialogs.h"
#include <windows.h>
#include "cccc.h"
using namespace sf;
using namespace std;
void handleText(string &code, int &startIndex, int &endIndex, bool &isTextSelected, RenderWindow &app, bool &isCapsOn, bool &isShiftOn)
{
    bool flag = 0;
    if (startIndex > endIndex)
    {
        swap(startIndex, endIndex);
        flag = 1;
    }
    if (!isTextSelected)
    {
        startIndex = code.length();
        endIndex = startIndex;
    }
    Event event;
    app.pollEvent(event);
    if (event.type == Event::TextEntered)
    {
        isShiftOn = Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift);
        isCapsOn = GetKeyState(VK_CAPITAL) & 0x0001;
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "a" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "A" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::B))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "b" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "B" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::C))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "c" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "C" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "d" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "D" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::E))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "e" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "E" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::F))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "f" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "F" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::G))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "g" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "G" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::H))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "h" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "H" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::I))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "i" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "I" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::J))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "j" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "J" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::K))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "k" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "K" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::L))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "l" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "L" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::M))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "m" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "M" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::N))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "n" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "N" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::O))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "o" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "O" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "p" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "P" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "q" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "Q" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::R))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "r" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "R" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "s" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "S" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::T))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "t" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "T" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::U))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "u" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "U" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::V))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "v" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "V" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "w" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "W" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::X))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "x" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "X" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Y))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "y" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "Y" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            if (isShiftOn == isCapsOn)
                code = code.substr(0, startIndex) + "z" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "Z" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Backspace) && code != "")
        {
            code = code.substr(0, startIndex - 1) + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            code = code.substr(0, startIndex) + " " + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Tab))
        {
            code = code.substr(0, startIndex) + "\t" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Semicolon))
        {
            code = code.substr(0, startIndex) + ";" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Comma))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "<" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "," + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::LBracket))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "{" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "[" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::RBracket))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "}" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "]" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Hyphen))
        {
            code = code.substr(0, startIndex) + "-" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num0))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + ")" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "0" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num1))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "!" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "1" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num2))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "@" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "2" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num3))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "#" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "3" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num4))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "$" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "4" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num5))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "%" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "5" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num6))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "^" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "6" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num7))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "&" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "7" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num8))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "*" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "8" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Num9))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "(" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "9" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Quote))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "\"" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "'" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Equal))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + "+" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "=" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Period))
        {
            if (isShiftOn)
                code = code.substr(0, startIndex) + ">" + code.substr(endIndex, code.length() - endIndex);
            else
                code = code.substr(0, startIndex) + "." + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            code = code.substr(0, startIndex) + "\n" + code.substr(endIndex, code.length() - endIndex);
            endIndex = startIndex;
        }
    }
    if (flag)
        swap(startIndex, endIndex);
}
int closestCharacter(Vector2i position, Text text, int len)
{
    for (int i = 0; i < len; i++)
        if (abs(text.findCharacterPos(i).x - position.x) < 10 && abs(text.findCharacterPos(i).y - position.y) < 10)
            return i;
    return -1;
}
int main()
{
    RenderWindow app(VideoMode(800, 800), "Selector", Style::Titlebar | Style::Close);
    Font font;
    font.loadFromFile("digital-7 (mono).ttf");
    Text text;
    text.setCharacterSize(50);
    text.setFillColor(Color::White);
    text.setFont(font);
    text.setString("Select a .cpp file.");
    text.setColor(Color::Black);
    bool openExplorer = 0, isAffPressed = 0, openEditor = 0, isTextPressed = 0, isTextSelected = 0, isCapsOn = 0, isShiftOn = 0;
    int x, y, editTextY = 0, startIndex, endIndex, maxIndex, minIndex, help, len;
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
        file.close();
        while (app.isOpen())
        {
            Event event;
            while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    app.close();
                handleText(fileContents, startIndex, endIndex, isTextSelected, app, isCapsOn, isShiftOn);
                if (event.type == Event::MouseWheelMoved)
                    editTextY += 20 * event.mouseWheel.delta;
                editTextY = min(0, editTextY);
                editTextY = max(editTextY, 1000 - int(text.getGlobalBounds().height));
            }
            app.clear(Color::Cyan);
            text.setPosition(0, editTextY);
            text.setString(fileContents);
            len = fileContents.length();
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
                ofstream outfile(filePath);
                outfile << fileContents;
                outfile.close();
                string command = "C:\\CCCC\\cccc.exe \"" + filePath + "\"";
                system(command.c_str());
                ifstream fileres("C:\\Program Files\\CodeBlocks\\graphs2.0\\main.cpp");
                fileContents = string((istreambuf_iterator<char>(fileres)), (istreambuf_iterator<char>()));
                fileres.close();
                ofstream outfileres("C:\\Program Files\\CodeBlocks\\graphs2.0\\main.cpp");
                outfileres << "#include \"" << filePath << "\"" << endl << fileContents;
                outfileres.close();
                app.close();
            }
            app.display();
        }
    }
    return 0;
}
