//
//  Graph.h
//  Graph
//
//  Created by Jiahe Li on 28/11/2018.
//  Copyright © 2018 Gellert. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <ostream>
#include <map>
#include <set>
#include <vector>

class Graph {
    friend std::ostream& operator<<(std::ostream& out, const Graph& graph);
public:
    Graph();
    Graph(const Graph& g);
    Graph(Graph&& g);
    
    Graph& operator=(Graph&& g);
    Graph& operator=(const Graph& g);
    
    bool isEmpty() const;
    
    void createGraph(const std::vector<std::vector<int>>& v);
    void emptyGraph();
    
    void printAllCourses() const;
    void printPrerequisites(int course) const;
    
    ~Graph();
    
private:
    std::map<int, std::set<int>> *graph;
    int numberOfVertices;
};


#endif