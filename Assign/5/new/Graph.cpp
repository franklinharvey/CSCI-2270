#include "Graph.h"
using namespace std;

Graph::Graph(){

}
Graph::~Graph(){

}

void Graph::addEdge(string v1, string v2, int weight){
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j<vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    if(!vertices[j].visited){
                        vertices[i].visited = 1;
                        adjVertex adjVert;
                        adjVert.v = &vertices[j];
                        adjVert.weight = weight;
                        vertices[i].adj.push_back(adjVert);

                        adjVertex adjVert2;
                        adjVert2.v = &vertices[i];
                        adjVert2.weight = weight;
                        vertices[j].adj.push_back(adjVert2);
                    }
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i<vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
        }
    }
    if(!found){
        vertex tmpV;
        tmpV.name = n;
        tmpV.district = -1;
        vertices.push_back(tmpV);
    }
}

void Graph::displayEdges(){

    for(int i = 0; i<vertices.size(); i++){
        cout << vertices[i].district << ":" << vertices[i].name << "-->";
        for(int j = 0; j<vertices[i].adj.size();j++){
            std::cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        std::cout<<std::endl;
    }
}

void Graph::assignDistricts(){
    BFTraversalLabel(vertices[0].name, 1);
    int counter = 1;

    for(int i = 1; i < vertices.size(); i++){
        bool a = false;
        for(int j = 1; j <= counter; j++){
            if(vertices[i].district == j){
                a = true;
            }
        }
        if(a == false){
            BFTraversalLabel(vertices[i].name, counter+1);
            counter++;
        }
    }
}

void Graph::shortestPath(string startingingCity, string endingCity){

    vertex * starting = findVertex(startingingCity);
    vertex * ending = findVertex(endingCity);

    if (starting == NULL || ending == NULL){ //found on google
        cout << "One or more cities doesn't exist"<< endl;
    }
    else if (ending->district != starting->district){
        cout << "No safe path between cities" << endl;
    }
    else if (ending->district == -1 || starting->district == -1){
        cout << "Please identify the districts before checking distances" << endl;
    }
    else{
        vertex *n;
        queue<vertex*> myQueue;
        vector<string> path;

        for(int i = 0; i < vertices.size(); i++){
            vertices[i].visited = 0;
            vertices[i].distance = 0;
            vertices[i].parent = NULL;
        }

        starting->visited = true;
        starting->distance = 0;
        myQueue.push(starting);
        while(!myQueue.empty()){

            n = myQueue.front();
            myQueue.pop();
            for(int i = 0; i < n->adj.size(); i++){

                if(!n->adj[i].v->visited){

                    n->adj[i].v->distance = n->distance + 1;
                        n->adj[i].v->parent = n;

                    if(n->adj[i].v->name == endingCity){
                        vertex* temp = n->adj[i].v;
                        n->adj[i].v->visited = true;
                        cout << temp->distance << ",";
                        vertex* tmp=ending;
                        while(tmp!=NULL){
                            path.push_back(tmp->name);
                            tmp=tmp->parent;
                        }
                        for (int k=path.size()-1; k>=1; k--){
                            cout<<path[k]<<",";
                        }
                        cout << path[0] << endl;
                        break;
                    }
                    else{
                        n->adj[i].v->visited = true;
                        myQueue.push(n->adj[i].v);
                    }
                }
            }
        }
    }
}

vertex * Graph::findVertex(std::string name){
    int i = 0;
    while(i < vertices.size()){
        if(vertices[i].name == name){
            return &vertices[i];
        }
        i++;
    }
    return NULL;
}

void Graph::BFTraversalLabel(std::string startingingCity, int distID){
    vertex *vert;
    vertex n;
    std::queue<vertex> myQueue;
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = 0;
    }

    vert = findVertex(startingingCity);
    vert->district=distID;
    vert->visited = true;
    myQueue.push(*vert);
    while(!myQueue.empty()){
        n = myQueue.front();
        myQueue.pop();
        for(int i = 0; i < n.adj.size(); i++){
            if(!n.adj[i].v->visited){
                n.adj[i].v->visited = true;
                n.adj[i].v->district = distID;
                myQueue.push(*n.adj[i].v);
            }
        }
    }
}
