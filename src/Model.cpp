#include "Model.h"
#include "Flow.h"

using namespace std;

// ---------- CONSTRUCTORS AND DESTRUCTOR ----------

Model::Model() {}

Model::~Model() {}

Model::Model(const Model& model) {

    // if(this == &model)
    //     return;

    systems.clear();
    flows.clear();

    for(SystemIterator systemIterator = systemsBegin(); systemIterator < systemsEnd(); systemIterator++) {
        add(*systemIterator);
    }

    for(FlowIterator flowIterator = flowsBegin(); flowIterator < flowsEnd(); flowIterator++) {
        add(*flowIterator);
    }
}

// ---------- GETTERS ----------

// vector<System*> Model::getSystems() const {
//     return systems;
// }

// vector<Flow*> Model::getFlows() const {
//     return flows;
// }

// ---------- ITERATORS ----------

Model::SystemIterator Model::systemsBegin() {
    return systems.begin();
}

Model::SystemIterator Model::systemsEnd() {
    return systems.end();
}

Model::FlowIterator Model::flowsBegin() {
    return flows.begin();
}

Model::FlowIterator Model::flowsEnd() {
    return flows.end();
}

// ---------- CRUD METHODS ----------

bool Model::add(System* system) {

    for(SystemIterator systemIterator = systemsBegin(); systemIterator < systemsEnd(); systemIterator++) {
        if(*systemIterator == system) {
            return true;
        }
    }

    systems.push_back(system);

    if(systems.back() == system) {
        return true;
    }

    return false;
}

bool Model::add(Flow* flow) {

    for(FlowIterator flowsIterator = flowsBegin(); flowsIterator < flowsEnd(); flowsIterator++) {
        if(*flowsIterator == flow) {
            return true;
        }
    }

    flows.push_back(flow);

    if(flows.back() == flow) {
        return true;
    }

    return false;
}

bool Model::remove(System* system) {

    for(SystemIterator systemIterator = systemsBegin(); systemIterator < systemsEnd(); systemIterator++) {
        
        if(*systemIterator == system) {
            systems.erase(systemIterator);
            return true;
        }
    }

    return false;
}

bool Model::remove(Flow* flow) {

    for(FlowIterator flowIterator = flowsBegin(); flowIterator < flowsEnd(); flowIterator++) {
        
        if(*flowIterator == flow) {
            flows.erase(flowIterator);
            return true;
        }
    }

    return false;
}

// ---------- OVERLOAD ----------

Model& Model::operator= (const Model& model) {

    for(SystemIterator systemIterator = systemsBegin(); systemIterator < systemsEnd(); systemIterator++) {
        add(*systemIterator);
    }

    for(FlowIterator flowIterator = flowsBegin(); flowIterator < flowsEnd(); flowIterator++) {
        add(*flowIterator);
    }

    return *this;
}

// ---------- MAIN METHODS ----------

bool Model::run(int startTime, int endTime) {

    for(int i = startTime; i < endTime; i++) {

        double *equations = new double[flows.size()];
        int counter = 0;

        for(FlowIterator flowIterator = flowsBegin(); flowIterator < flowsEnd(); flowIterator++) {
            equations[counter] = (*flowIterator)->execute();
            counter++;
        }

        counter = 0;

        for(FlowIterator flowIterator = flowsBegin(); flowIterator < flowsEnd(); flowIterator++) {
            
            System* source = (*flowIterator)->getSource();
            source->setValue(source->getValue() - equations[counter]);

            System* target = (*flowIterator)->getTarget();
            target->setValue(target->getValue() + equations[counter]);

            counter++;
        }
    }

    return true;
}

// para cada sistema “i” pertencente ao modelo{ imprime( sistema[i] ) }

// bool Model::printSystems() {

//     for(SystemIterator systemIterator = systemsBegin(); systemIterator < systemsEnd(); systemIterator++) {

//     }
// }
