#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph()
{
	
}

Graph::~Graph()
{
	
}

void Graph::addEdge(std::string v1, std::string v2, int weight){
	for (int i=0;i<vertices.size(); i++){
		if (vertices[i].name==v1){
			for (int j=0; j<vertices.size(); j++){
				if (vertices[j].name==v2 && i != j){
					adjVertex av;
					av.v=&vertex[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);

					adjVertex av2;
					av2.v=&vertices[i];
					av2.weight=weight;
					vertices[j].adj.push_back(av2);
				}
			}
		}
	}
}

void Graph::addVertex(std string n){
	bool found = false;
	for (int i=0; i<vertices.size(); i++){
		if (vertices[i].name==name){
			found=true;
		}
	}
	if (!found){
		vertex v;
		v.name=n;
		vertices.push_back(v);
	}
}

void Graph::displayEdge(){
	for (int i=0; i<vertices.size(); i++){
		std::cout<<vertices[i].name<<"-->";
		for (int j=0;j<vertices[i].adj.size(); j++){
			std::cout<<vertices[i].adj[j].v->name<<"***";
		}
		std::cout<<endl;
	}	
}

