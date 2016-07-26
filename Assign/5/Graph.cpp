#include "Project.h"
#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

Graph::Graph()
{
//constractor
}

Graph::~Graph()
{
    //dtor
}

void Graph::addEdge(string v1, string v2, int weight)//creates edges
{
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string n)//inseet vertecies
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.district = -1;
        v.visited = false;
        v.ID = vertices.size();
        vertices.push_back(v);
    }
}

void Graph::displayEdges()//print connection between cities
{
    for(int i = 0; i < vertices.size(); i++){
        cout<< vertices[i].district <<":" <<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}

void Graph::assignDistricts()// create district
{
    // Starting district num
    int distID = 1;
    // For each of the vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        // Only consider a vertex that has not been assigned a district.
        if (vertices[i].district == -1)
        {
            // Run breadth first traversal and assign each node in the network to this district.
            BFTraversalLabel(vertices[i].name,distID);
            distID++;
        }
    }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID)//function to travers between the verticies
{
    queue<vertex*> q;
    // Label all as unvisited.
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
    // Find the starting node and enqueue it.
    for(int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == startingCity)
        {
            // set current vertex to be visited.
            vertices[i].visited = true;
            q.push(&vertices[i]);
            vertices[i].district = distID;
            break;
        }
    }
    // Now do the rest of the search.
    while (q.empty() != true)
    {
        vertex * u = q.front();
        q.pop();
        for(int i = 0; i < u->adj.size(); i++)
        {
            if (u->adj[i].v->visited == false)
            {
                u->adj[i].v->visited = true;
                u->adj[i].v->district = distID;
                q.push(u->adj[i].v);
            }
        }
    }
}

void Graph::shortestPath(std::string startingCity,std::string endingCity)//find shortest path
{

    vertex * start = findVertex(startingCity);
    vertex * end = findVertex(endingCity);

    if (start == NULL || end == NULL)
    {
        cout << "One or more cities doesn't exist,or it is not in our Database"<< endl;
        return;
    }
    if (end->district != start->district)
    {
        cout << "You can't get there by car" << endl;
        return;
    }
    if (end->district == -1 || start->district == -1)
    {
        cout << "Please identify the districts before checking distances" << endl;
        return;
    }

    // Initialization
    for(int i = 0; i < vertices.size(); i++)
        vertices[i].visited = false;
    start->visited = true;
    queueVertex qv;
    qv.distance = 0;
    qv.path.push_back(start);
    queue<queueVertex> q;
    q.push(qv);

    while (q.empty() != true)
    {
        qv = q.front();
        q.pop();

        for(int i = 0; i < qv.path.back()->adj.size(); i++)
        {
            if (qv.path.back()->adj[i].v->visited == false)
            {
                // Create a new queueVertex with updated path and distance.
                vector<vertex *> path = qv.path;
                qv.path.back()->adj[i].v->visited = true;
                int distance = qv.distance + 1;

                path.push_back(qv.path.back()->adj[i].v);
                queueVertex temp;
                temp.path = path;
                temp.distance = distance;

                // If we have found the correct path
                if (qv.path.back()->adj[i].v == end)
                {
                    cout << temp.distance;
                    for (int j = 0; j < temp.path.size(); j++)
                        cout << "," << temp.path[j]->name;
                    cout << endl;
                    return;
                }
                else
                    q.push(temp);
            }
        }
    }
    return;
}

// Dijkstra