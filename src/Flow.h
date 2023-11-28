#ifndef _FLOW_H_
#define _FLOW_H_

#include "System.h"

using namespace std;

class Flow {
    System* source;
    System* target;

    public:

        // Constructor and destructor
        Flow(); // default constructor
        Flow(System*, System*);

        virtual ~Flow();

        // Copy constructor
        Flow(const Flow&);

        // Source getter and setter
        System* getSource() const;
        bool setSource(System*);

        // Target getter and setter
        System* getTarget() const;
        bool setTarget(System*);

        // Updates a flow
        bool update(System*, System*);

        // Equation function
        virtual double execute() = 0;

        // = operator overload
        Flow& operator= (const Flow&);
};

#endif
