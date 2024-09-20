#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace std;
Vector2f getProjPos(Vector3f coords, Vector3f camCoords)
{
    float x = coords.x - camCoords.x, y = coords.y - camCoords.y, z = coords.z - camCoords.z, n = camCoords.x*camCoords.x + camCoords.y*camCoords.y + camCoords.z*camCoords.z;
    Vector3f projection = ((x*camCoords.x + y*camCoords.y + z*camCoords.z) / n)*camCoords;
    n = sqrt(x*x + y*y + z*z) / 500;
    return {400 + (x + projection.x) / n, 400 + (y + projection.y) / n};
}
float distanceFromCenterToCam(vector<Vector3f> coords, Vector3f camCoords)
{
    Vector3f vect = camCoords - 0.25f*(coords[0] + coords[1] + coords[2] + coords[3]);
    return sqrt(vect.x*vect.x + vect.y*vect.y + vect.z*vect.z);
}
class Face
{
private:
    vector<Vector3f> coords;
    Color color;
public:
    Face(vector<Vector3f> setCoords, Color col): coords(setCoords), color(col) {}
    vector<Vector3f> getCoords()
    {
        return coords;
    }
    void drawFace(RenderWindow& app, Vector3f camCoords)
    {
        ConvexShape face;
        face.setFillColor(color);
        face.setPointCount(4);
        for (int i = 0; i < 4; i++)
            face.setPoint(i, getProjPos(coords[i], camCoords));
        app.draw(face);
    }
};
class Cube
{
private:
    Vector3f camCoords;
    vector<Face*> faces;
public:
    Vector3f getCamCoords()
    {
        return camCoords;
    }
    void setCamCoords(Vector3f newCamCoords)
    {
        camCoords = newCamCoords;
    }
    void addFace(Face *face)
    {
        faces.push_back(face);
    }
    vector<Face*> getFaces()
    {
        return faces;
    }
    void drawCube(RenderWindow &app)
    {
        for (Face* face : faces)
            face->drawFace(app, camCoords);
    }
    void sortFaces()
    {
        int m, dist, index;
        for (int i = 0; i < 5; i++)
        {
            m = distanceFromCenterToCam(faces[i]->getCoords(), camCoords);
            index = i;
            for (int j = i + 1; j < 6; j++)
            {
                dist = distanceFromCenterToCam(faces[j]->getCoords(), camCoords);
                if (dist > m)
                {
                    m = dist;
                    index = j;
                }
            }
            swap(faces[i], faces[index]);
        }
    }
    float getCamDistance()
    {
        return sqrt(camCoords.x*camCoords.x + camCoords.y*camCoords.y + camCoords.z*camCoords.z);
    }
};
int main()
{
    RenderWindow app(VideoMode(800, 800), "Cube", Style::Titlebar | Style::Close);
    float x = Mouse::getPosition(app).x, y = Mouse::getPosition(app).y, alpha = 0, beta = 0;
    Cube cube;
    cube.setCamCoords({0, 0, 200});
    Face* newFace = new Face({{-100, -100, -100}, {-100, 100, -100}, {100, 100, -100}, {100, -100, -100}}, {209, 76, 113});
    cube.addFace(newFace);
    newFace = new Face({{-100, -100, 100}, {-100, 100, 100}, {100, 100, 100}, {100, -100, 100}}, {63, 103, 187});
    cube.addFace(newFace);
    newFace = new Face({{-100, -100, -100}, {-100, 100, -100}, {-100, 100, 100}, {-100, -100, 100}}, {82, 187, 63});
    cube.addFace(newFace);
    newFace = new Face({{100, -100, 100}, {100, 100, 100}, {100, 100, -100}, {100, -100, -100}}, {202, 202, 10});
    cube.addFace(newFace);
    newFace = new Face({{-100, -100, -100}, {-100, -100, 100}, {100, -100, 100}, {100, -100, -100}}, {202, 10, 182});
    cube.addFace(newFace);
    newFace = new Face({{-100, 100, 100}, {-100, 100, -100}, {100, 100, -100}, {100, 100, 100}}, {94, 10, 202});
    cube.addFace(newFace);
    cube.sortFaces();
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if (event.type == Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta < 0 && cube.getCamDistance() < 500)
                    cube.setCamCoords(cube.getCamCoords() / 0.9f);
                if (event.mouseWheel.delta > 0 && cube.getCamDistance() > 200)
                    cube.setCamCoords(cube.getCamCoords()*0.9f);
            }
        }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            x -= Mouse::getPosition(app).x;
            y -= Mouse::getPosition(app).y;
            alpha += M_PI*x / 800;
            beta += M_PI*y / 800;
            cube.setCamCoords(cube.getCamDistance()*Vector3f(sin(alpha), sin(beta), sqrt(1 - sin(alpha)*sin(alpha) - sin(beta)*sin(beta))));
            cube.sortFaces();
        }
        x = Mouse::getPosition(app).x;
        y = Mouse::getPosition(app).y;
        app.clear(Color::White);
        cube.drawCube(app);
        app.display();
    }
    return 0;
}
