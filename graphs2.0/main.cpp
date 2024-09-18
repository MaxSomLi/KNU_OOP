#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace std;
class Edge;
class Node
{
private:
    Vector2f coords;
    vector<Edge*> edges;
    bool classified;
public:
    Node(Vector2f nc): coords(nc), edges({}), classified(0) {}
    Vector2f getCoords()
    {
        return coords;
    }
    vector<Edge*> getEdges()
    {
        return edges;
    }
    bool getClassified()
    {
        return classified;
    }
    void classify()
    {
        classified = 1;
    }
    void addEdge(Edge *edge)
    {
        edges.push_back(edge);
    }
    void removeEdge(Edge *edge)
    {
        edges.erase(find(edges.begin(), edges.end(), edge));
    }
};
class Edge
{
private:
    double weight;
    vector<Node*> incs;
    bool willBeInTree;
public:
    Edge(double setWeight, Node *inc1, Node *inc2): weight(setWeight), incs({inc1, inc2}), willBeInTree(0) {}
    double getWeight()
    {
        return weight;
    }
    vector<Node*> getIncs()
    {
        return incs;
    }
    bool getWillBeInTree()
    {
        return willBeInTree;
    }
    void addToTree()
    {
        willBeInTree = 1;
    }
};
class Graph
{
private:
    vector<Node*> nodes;
    vector<Edge*> edges;
public:
    vector<Node*> getNodes()
    {
        return nodes;
    }
    vector<Edge*> getEdges()
    {
        return edges;
    }
    void addNode(Node *nodeToAdd)
    {
        nodes.push_back(nodeToAdd);
    }
    void addEdge(double dist, Node *node1, Node *node2)
    {
        Edge *newEdge = new Edge(dist, node1, node2);
        node1->addEdge(newEdge);
        node2->addEdge(newEdge);
        edges.push_back(newEdge);
    }
    void deleteNode(Node *nodeToDelete)
    {
        while (!nodeToDelete->getEdges().empty())
        {
            Edge *edgeToDelete = nodeToDelete->getEdges()[0];
            edgeToDelete->getIncs()[0]->removeEdge(edgeToDelete);
            edgeToDelete->getIncs()[1]->removeEdge(edgeToDelete);
            edges.erase(find(edges.begin(), edges.end(), edgeToDelete));
            delete edgeToDelete;
        }
        nodes.erase(find(nodes.begin(), nodes.end(), nodeToDelete));
        delete nodeToDelete;
    }
    void deleteEdge(Edge *edgeToDelete)
    {
        edgeToDelete->getIncs()[0]->removeEdge(edgeToDelete);
        edgeToDelete->getIncs()[1]->removeEdge(edgeToDelete);
        edges.erase(find(edges.begin(), edges.end(), edgeToDelete));
        delete edgeToDelete;
    }
    int getIndexOfClosestNode(int x, int y)
    {
        int nodesSize = nodes.size();
        for (int i = 0; i < nodesSize; i++)
            if (abs(x - nodes[i]->getCoords().x) < 30 && abs(y - nodes[i]->getCoords().y) < 30)
                return i;
        return -1;
    }
    int getIndexOfConnectingEdge(Node *node1, Node *node2)
    {
        int edgesSize = node1->getEdges().size();
        for (int i = 0; i < edgesSize; i++)
            if (node1->getEdges()[i]->getIncs()[0] == node2 || node1->getEdges()[i]->getIncs()[1] == node2)
                return i;
        return -1;
    }
    void makeGraphDrawing(RenderTexture &graphTexture, string path)
    {
        for (Node *node : nodes)
        {
            CircleShape n(10);
            n.setFillColor(Color::Blue);
            n.setOrigin(10, 10);
            n.setPosition(node->getCoords());
            graphTexture.draw(n);
        }
        for (Edge *edge : edges)
        {
            Vertex e[] = {{edge->getIncs()[0]->getCoords(), Color::Blue}, {edge->getIncs()[1]->getCoords(), Color::Blue}};
            graphTexture.draw(e, 2, Lines);
        }
        Texture res = graphTexture.getTexture();
        Image img = res.copyToImage();
        img.flipVertically();
        img.saveToFile(path);
    }
    void pushToComponent(Node *node, vector<Node*> &component)
    {
        if (node->getClassified())
            return;
        component.push_back(node);
        node->classify();
        for (Edge *edge : node->getEdges())
        {
            pushToComponent(edge->getIncs()[0], component);
            pushToComponent(edge->getIncs()[1], component);
        }
    }
    int minEdgeIndex(vector<Node*> component1, vector<Node*> component2)
    {
        Edge *edge;
        double m = -1, weight;
        int nodesSize = component1.size(), edgesSize, res;
        for (int i = 0; i < nodesSize; i++)
        {
            edgesSize = component1[i]->getEdges().size();
            for (int j = 0; j < edgesSize; j++)
            {
                edge = component1[i]->getEdges()[j];
                if ((find(component1.begin(), component1.end(), edge->getIncs()[0]) == component1.end()) == (find(component2.begin(), component2.end(), edge->getIncs()[1]) == component2.end()))
                {
                    weight = edge->getWeight();
                    if (m == -1 || m > weight)
                    {
                        m = weight;
                        res = find(edges.begin(), edges.end(), edge) - edges.begin();
                    }
                }
            }
        }
        return res;
    }
    void determineEdgesPosition(vector<Node*> component)
    {
        vector<Node*> component1 = {component[0]}, component2 = component;
        Edge *edge;
        component2.erase(component2.begin());
        while (!component2.empty())
        {
            edge = edges[minEdgeIndex(component1, component2)];
            edge->addToTree();
            auto it = find(component2.begin(), component2.end(), edge->getIncs()[0]);
            if (it != component2.end())
            {
                component2.erase(it);
                component1.push_back(edge->getIncs()[0]);
            }
            else
            {
                it = find(component2.begin(), component2.end(), edge->getIncs()[1]);
                component2.erase(it);
                component1.push_back(edge->getIncs()[1]);
            }
        }
    }
    void makeIntoTree()
    {
        vector<Node*> currentComponent;
        for (Node *node : nodes)
        {
            pushToComponent(node, currentComponent);
            if(!currentComponent.empty())
                determineEdgesPosition(currentComponent);
            currentComponent.clear();
        }
        int edgesSize = edges.size();
        for (int i = 0; i < edgesSize; i++)
            while (!edges[i]->getWillBeInTree())
                deleteEdge(edges[i]);
    }
    void drawOnApp(RenderWindow &app)
    {
        for (Node *node : nodes)
        {
            CircleShape n(10);
            n.setFillColor(Color::Blue);
            n.setOrigin(10, 10);
            n.setPosition(node->getCoords());
            app.draw(n);
        }
        for (Edge *edge : edges)
        {
            Vertex e[] = {{edge->getIncs()[0]->getCoords(), Color::Blue}, {edge->getIncs()[1]->getCoords(), Color::Blue}};
            app.draw(e, 2, Lines);
        }
    }
};
int main()
{
    RenderWindow app(VideoMode(800, 800), "Graph handling", Style::Titlebar | Style::Close);
    RenderTexture graphTexture, treesTexture;
    graphTexture.create(800, 800);
    treesTexture.create(800, 800);
    graphTexture.clear();
    treesTexture.clear();
    int x = Mouse::getPosition(app).x, y = Mouse::getPosition(app).y, nodeIndex, edgeIndex;
    Graph graph;
    double xd, yd, dist;
    bool isLeftPressed = 0, isRightPressed = 0, isStartSelected = 0;
    Node *start;
    app.setMouseCursorVisible(0);
    Texture cursorTexture;
    cursorTexture.loadFromFile("cursor.png");
    while (app.isOpen())
    {
        app.clear(Color::White);
        graph.drawOnApp(app);
        Event event;
        while (app.pollEvent(event))
            if (event.type == Event::Closed)
            {
                graph.makeGraphDrawing(graphTexture, "resulting-graph.png");
                graph.makeIntoTree();
                graph.makeGraphDrawing(treesTexture, "resulting-trees.png");
                app.close();
            }
        x = Mouse::getPosition(app).x;
        y = Mouse::getPosition(app).y;
        if (Mouse::isButtonPressed(Mouse::Left))
            isLeftPressed = 1;
        if (Mouse::isButtonPressed(Mouse::Right))
            isRightPressed = 1;
        if (event.type == Event::MouseButtonReleased && isLeftPressed)
        {
            isLeftPressed = 0;
            nodeIndex = graph.getIndexOfClosestNode(x, y);
            if (nodeIndex > -1)
                graph.deleteNode(graph.getNodes()[nodeIndex]);
            else
            {
                Node* newNode = new Node({x, y});
                graph.addNode(newNode);
            }
        }
        if (event.type == Event::MouseButtonReleased && isRightPressed)
        {
            isRightPressed = 0;
            nodeIndex = graph.getIndexOfClosestNode(x, y);
            if (isStartSelected)
            {
                isStartSelected = 0;
                if (nodeIndex > -1)
                {
                    if (graph.getNodes()[nodeIndex] != start)
                    {
                        edgeIndex = graph.getIndexOfConnectingEdge(start, graph.getNodes()[nodeIndex]);
                        if (edgeIndex > -1)
                            graph.deleteEdge(start->getEdges()[edgeIndex]);
                        else
                        {
                            xd = start->getCoords().x - graph.getNodes()[nodeIndex]->getCoords().x;
                            yd = start->getCoords().y - graph.getNodes()[nodeIndex]->getCoords().y;
                            dist = sqrt(xd*xd + yd*yd);
                            graph.addEdge(dist, start, graph.getNodes()[nodeIndex]);
                        }
                    }
                }
            }
            else if (nodeIndex > -1)
            {
                isStartSelected = 1;
                start = graph.getNodes()[nodeIndex];
            }
        }
        Sprite cursor;
        cursor.setTexture(cursorTexture);
        cursor.setScale(0.2, 0.2);
        if (isLeftPressed || isRightPressed)
            cursor.setScale(0.1, 0.1);
        cursor.setOrigin(cursor.getLocalBounds().width / 2, cursor.getLocalBounds().height / 2);
        cursor.setPosition(x, y);
        app.draw(cursor);
        app.display();
    }
    return 0;
}
