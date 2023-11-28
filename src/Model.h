#ifndef _MODEL_H_
#define _MODEL_H_

#include <iostream>
#include <vector>
#include <iterator>

#include "System.h"
#include "Flow.h"

using namespace std;

class Model {
    vector<System*> systems;
    vector<Flow*> flows;

    public:

        // Default constructor
        Model();
        // Constructor
        Model(vector<System*>, vector<Flow*>);
        // Destructor
        virtual ~Model();
        // Copy constructor
        Model(const Model&);

        // Systems getter
        vector<System*> getSystems() const;
        // Flows getter
        vector<Flow*> getFlows() const;

        // System iterator
        typedef vector<System*>::iterator SystemIterator;
        SystemIterator systemsBegin();
        SystemIterator systemsEnd();

        // Flow iterator
        typedef vector<Flow*>::iterator FlowIterator;
        FlowIterator flowsBegin();
        FlowIterator flowsEnd();

        // Add a system or a flow
        bool add(System*);
        bool add(Flow*);

        // Remove a system or a flow
        bool remove(System*);
        bool remove(Flow*);

        // Run a simulation
        bool run(int, int);

        // Print the systems
        // bool printSystems();
};

#endif
