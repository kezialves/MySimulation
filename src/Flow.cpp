#include "Flow.h"
#include "System.h"

using namespace std;

// ---------- CONSTRUCTORS AND DESTRUCTOR ----------

Flow::Flow(System* source, System* target):
    source(source), target(target) {}

Flow::~Flow() {}

Flow::Flow(const Flow& flow) {

    if(this == &flow)
        return;

    source = flow.getSource();
    target = flow.getTarget();
}

// ---------- GETTERS AND SETTERS ----------

System* Flow::getSource() const {
    return source;
}

bool Flow::setSource(System* sourceSystem) {
    
    source = sourceSystem;

    if(source == sourceSystem)
        return true;

    return false;
}

System* Flow::getTarget() const {
    return target;
}

bool Flow::setTarget(System* targetSystem) {
    
    target = targetSystem;

    if(target == targetSystem)
        return true;

    return false;
}

// ---------- CRUD METHODS ----------

bool Flow::update(System* sourceSystem, System* targetSystem) {
    
    if(setSource(sourceSystem) && setTarget(targetSystem))
        return true;

    return false;
}

// ---------- OVERLOAD ----------

Flow& Flow::operator= (const Flow& flow) {

    if(this == &flow) {
        return *this;
    }

    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
