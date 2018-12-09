//
//  main.cpp
//  Graph
//
//  Created by Jiahe Li on 28/11/2018.
//  Copyright © 2018 Gellert. All rights reserved.
//

#include <iostream>
#include "Graph.h"

void printGraph(const Graph&);

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> course {
        {100},
        {140, 100},
        {150, 140},
        {170, 100},
        {200, 150, 265},
        {216, 100},
        {220, 216, 250},
        {250, 150},
        {265},
        {272, 170}
    };
    
    {
        std::cout << "TEST: default constructor, createGraph, isEmpty, printAllCourses\n\n";
        Graph graph;
        graph.createGraph(course);
        printGraph(graph);
    }
    
    std::cout << "\n======================================\n";
    
    {
        std::cout << "TEST: emptyGraph\n\n";
        Graph graph;
        graph.createGraph(course);
		graph.emptyGraph();
        printGraph(graph);
    }
    
    std::cout << "\n======================================\n";
    
    {
        std::cout << "TEST: printPrerequisites\n\n";
        Graph graph;
        graph.createGraph(course);
        printGraph(graph);
        
        std::cout << std::endl;
        
        for (auto const &i : course) {
            std::cout << "CS A" << i[0] << " - Prerequisites: ";
            graph.printPrerequisites(i[0]);
            std::cout << std::endl;
        }
    }
    
    std::cout << "\n======================================\n";
    
    {
        std::cout << "TEST: copy constructor\n\n";
        Graph graph;
        graph.createGraph(course);
        printGraph(graph);

		std::cout << std::endl;

		std::cout << "Creating new graph using copy constructor...\n";
		Graph newGraph(graph);
		std::cout << "Emptying graph...\n";
		graph.emptyGraph();
		std::cout << "Check graph (should be empty)...\n";
		std::cout << "Graph - ";
		printGraph(graph);
		std::cout << "Checking new graph...\n";
		printGraph(newGraph);
    }

	std::cout << "\n======================================\n";

	{
		std::cout << "TEST: move constructor\n\n";
		Graph graph;
		graph.createGraph(course);
		std::cout << "Graph - ";
		printGraph(graph);
		std::cout << std::endl;

		std::cout << "Creating new graph using  move constructor...\n";
		Graph newGraph = std::move(graph);
		std::cout << "Check graph 1 (should be empty)...\n";
		std::cout << "Graph - ";
		printGraph(graph);
		std::cout << "Checking new graph...\n";
		printGraph(newGraph);
	}

	std::cout << "\n======================================\n";

	{
		std::cout << "TEST: overloaded assignment operator\n\n";
		Graph graph;
		graph.createGraph(course);
		std::cout << "Graph - ";
		printGraph(graph);
		std::cout << std::endl;

		std::cout << "Creating new graph with new set of courses...\n";
		std::vector<std::vector<int>> newCourses = {
			{300},
			{301, 300}
		};
		Graph newGraph;
		newGraph.createGraph(newCourses);
		std::cout << "New Graph - ";
		printGraph(newGraph);
		std::cout << "\nCopying graph 1 into new graph using overloaded assignment operator...\n";
		newGraph = graph;
	
		printGraph(newGraph);
	}

	std::cout << "\n======================================\n";

	{
		std::cout << "TEST: move assignment operator\n\n";
		Graph graph;
		graph.createGraph(course);
		std::cout << "Graph - ";
		printGraph(graph);
		std::cout << std::endl;

		std::cout << "Creating new graph with new set of courses...\n";
		std::vector<std::vector<int>> newCourses = {
			{300},
			{301, 300}
		};
		Graph newGraph;
		newGraph.createGraph(newCourses);
		std::cout << "New Graph - ";
		printGraph(newGraph);
		std::cout << "\nCopying graph 1 into new graph using move assignment operator...\n";
		newGraph = std::move(graph);
		std::cout << "Check graph 1 (should be empty)...\n";
		std::cout << "Graph - ";
		printGraph(graph);
		std::cout << "Checking new graph...\n";
		printGraph(newGraph);
	}
	std::cout << "\n======================================\n";

	std::cout << std::endl;

	system("pause");
    
    return 0;
}

void printGraph(const Graph& graph) {
    if (graph.isEmpty()) {
        std::cerr << "Graph is empty." << std::endl;
    } else {
        std::cout << "COURSES:\n";
        graph.printAllCourses();
    }
}
