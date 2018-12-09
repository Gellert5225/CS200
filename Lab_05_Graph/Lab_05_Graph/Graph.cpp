//
//  Graph.cpp
//  Graph
//
//  Created by Jiahe Li on 28/11/2018.
//  Copyright © 2018 Gellert. All rights reserved.
//

#include "Graph.h"
#include <iostream>

Graph::Graph() {
    graph = new std::map<int, std::set<int>>;
    numberOfVertices = 0;
}

Graph::Graph(const Graph& g) {
	graph = new std::map<int, std::set<int>>;
    *graph = *g.graph;
    numberOfVertices = g.numberOfVertices;
}

Graph::Graph(Graph&& g) {
    graph = g.graph;
    numberOfVertices = g.numberOfVertices;
    
    g.graph = nullptr;
    g.numberOfVertices = 0;
}

Graph& Graph::operator=(Graph&& g) {
    if (this == &g) std::cerr << "Cannot assign object to itserlf" << std::endl;
    else {
        delete graph;
        graph = g.graph;
        numberOfVertices = g.numberOfVertices;
        
        g.graph = nullptr;
        g.numberOfVertices = 0;
    }
    
    return *this;
}

Graph& Graph::operator=(const Graph& g) {
    if (this == &g) std::cerr << "Cannot assign object to itserlf" << std::endl;
    else {
        *graph = *g.graph;
        numberOfVertices = g.numberOfVertices;
    }
    return *this;
}

bool Graph::isEmpty() const {
    return numberOfVertices == 0;
}

void Graph::createGraph(const std::vector<std::vector<int>>& v) {
    for (auto i : v) {
        std::set<int> temp;
        for (int j = 1; j < i.size(); j++) {
            temp.insert(i[j]);
        }
        graph->insert({i[0], temp});
    }
	numberOfVertices = v.size();
}

void Graph::emptyGraph() {
	if (graph != nullptr) {
		graph->clear();
	}
}

void Graph::printAllCourses() const {
    std::map<int, std::set<int>>::const_iterator iter = graph->begin();
    std::map<int, std::set<int>>::const_iterator end = graph->end();
    
    while (iter != end) {
        std::cout << "CS A" << iter->first << " ";
        iter++;
    }
	std::cout << std::endl;
}

void Graph::printPrerequisites(int course) const {
	std::map<int, std::set<int>>::const_iterator iter;
    
    bool found = false;

	iter = graph->find(course);

	if (iter == graph->end()) std::cout << "There is no such course" << std::endl;
	else {
		if (iter->second.empty()) std::cout << "No prerequisite" << std::endl;
		else {
			std::set<int>::const_iterator iter2 = iter->second.begin();
			std::set<int>::const_iterator end2 = iter->second.end();

			while (iter2 != end2) {
				std::cout << "CS A" << *iter2 << " ";
				iter2++;
			}
			std::cout << std::endl;
		}
	}
 }

Graph::~Graph() {
	delete graph;
	graph = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Graph& graph) {
	std::map<int, std::set<int>>::const_iterator iter = graph.graph->begin();
	std::map<int, std::set<int>>::const_iterator end = graph.graph->end();

	std::set<int>::const_iterator iter2;
	std::set<int>::const_iterator end2;

	while (iter != end) {
		out << iter->first << ": ";

		iter2 = iter->second.begin();
		end2 = iter->second.end();
		while (iter2 != end2) {
			out << *iter2 << " ";
			iter2++;
		}
		out << std::endl;
		iter++;
	}
    return out;
}
