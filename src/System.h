#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <iostream>

using namespace std;

class System {
    double value;

    public:

        // Constructor and destructor
        System(); // default constructor
        System(double = 0.);

        virtual ~System();

        // Copy constructor
        System(const System&);

        // Value getter and setter
        double getValue() const;
        bool setValue(double value);

        // Updates a system
        bool update(double value);

        // = operator overload
        System& operator= (const System&);
};

#endif
