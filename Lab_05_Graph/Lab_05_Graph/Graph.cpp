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
            numberOfVertices++;
        }
        graph->insert({i[0], temp});
        numberOfVertices++;
    }
}

void Graph::emptyGraph() {
    graph->clear();
}

void Graph::printAllCourses() const {
    std::map<int, std::set<int>>::const_iterator iter = graph->begin();
    std::map<int, std::set<int>>::const_iterator end = graph->end();
    
    std::set<int>::const_iterator iter2;
    std::set<int>::const_iterator end2;
    
    while (iter != end) {
        std::cout << iter->first << ": ";
        
        iter2 = iter->second.begin();
        end2 = iter->second.end();
        while (iter2 != end2) {
            std::cout << *iter2 << " ";
            iter2++;
        }
        std::cout << std::endl;
        iter++;
    }
}

void Graph::printPrerequisites(int course) const {
    std::map<int, std::set<int>>::const_iterator iter = graph->begin();
    std::map<int, std::set<int>>::const_iterator end = graph->end();
    
    bool found = false;
    
    while (iter != end) {
        if (iter->first == course) {
            found = true;
            std::cout << "Prerequisite for class " << course << ": ";
            if (iter->second.empty()) std::cout << "No prerequisite" << std::endl;
            else {
                std::set<int>::const_iterator iter2 = iter->second.begin();
                std::set<int>::const_iterator end2 = iter->second.end();
                
                while (iter2 != end2) {
                    std::cout << *iter2 << " ";
                    iter2++;
                }
                std::cout << std::endl;
            }
        }
        iter++;
    }
    
    if (!found) std::cout << "There is no such course" << std::endl;
}

Graph::~Graph() {
    emptyGraph();
}

std::ostream& operator<<(std::ostream& out, const Graph& graph) {
    return out;
}
