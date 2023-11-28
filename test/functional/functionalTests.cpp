#include "functionalTests.h"
#include "../../src/Model.h"

#include <iostream>
#include <math.h>
#include <assert.h>

using namespace std;

// ---------- FLOWS ----------

class ExponentialFlow: public Flow {
    public:

        ExponentialFlow(System* source, System* target):
            Flow(source, target) {}

        // 0.01 * pop1
        double execute() {
            return 0.01 * getSource()->getValue();
        }
};

class LogisticFlow: public Flow {
    public:

        LogisticFlow(System* source, System* target):
            Flow(source, target) {}

        // 0.01 * p2 * (1 - p2/70)
        double execute() {
            return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue()/70.0));
        }
};

// ---------- TESTS ----------

void exponentialTest() {

    cout << "*------------------------------*" << endl
        << "Exponential test started.\n" << endl;

    Model model;
    System pop1(100.0), pop2(0.0);
    ExponentialFlow flow1(&pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow1);

    // model.run(0, 10);
    // assert(fabs(pop1.getValue() - 90.4382) < 0.0001);
    // assert(fabs(pop2.getValue() - 9.5617) < 0.0001);

    // no float errors:
    // assert(trunc(fabs(pop1.getValue() - 90.4382) * 10000) < 1);

    // pop1.setValue(100.0);
    // pop2.setValue(0.0);

    model.run(0, 100);
    assert(fabs(pop1.getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2.getValue() - 63.3968) < 0.0001);

    // pop1.setValue(100.0);
    // pop2.setValue(0.0);

    // model.run(0, 547);
    // assert(fabs(pop1.getValue() - 0.4096) < 0.0001);
    // assert(fabs(pop2.getValue() - 99.5903) < 0.0001);

    cout << "Exponential test passed :)." << endl
        << "*------------------------------*\n" << endl;
}

void logisticTest() {

    cout << "*------------------------------*" << endl
        << "Logistic test started.\n" << endl;

    Model model;
    System p1(100.0), p2(10.0);
    LogisticFlow flow1(&p1, &p2);

    model.add(&p1);
    model.add(&p2);
    model.add(&flow1);

    // model.run(0, 10);
    // assert(fabs(p1.getValue() - 99.1151) < 0.0001);
    // assert(fabs(p2.getValue() - 10.8849) < 0.0001);

    // p1.setValue(100.0);
    // p2.setValue(10.0);

    // model.run(0, 80);
    // assert(fabs(p1.getValue() - 91.0933) < 0.0001);
    // assert(fabs(p2.getValue() - 18.9067) < 0.0001);

    // p1.setValue(100.0);
    // p2.setValue(10.0);

    model.run(0, 100);
    assert(fabs(p1.getValue() - 88.2167) < 0.0001);
    assert(fabs(p2.getValue() - 21.7833) < 0.0001);

    // model.run(0, 347);
    // assert(fabs(p1.getValue() - 51.0168) < 0.0001);
    // assert(fabs(p2.getValue() - 58.9832) < 0.0001);

    // p1.setValue(100.0);
    // p2.setValue(10.0);

    // model.run(0, 547);
    // assert(fabs(p1.getValue() - 41.7114) < 0.0001);
    // assert(fabs(p2.getValue() - 68.2886) < 0.0001);

    cout << "Logistic test passed :)." << endl
        << "*------------------------------*\n" << endl;
}

void complexTest() {

    cout << "*------------------------------*" << endl
        << "Complex test started.\n" << endl;

    Model model;
    System Q1(100.0), Q2(0.0), Q3(100.0), Q4(0.0), Q5(0.0);
    
    ExponentialFlow f(&Q1, &Q2), g(&Q1, &Q3), r(&Q2, &Q5),
                    t(&Q2, &Q3), u(&Q3, &Q4), v(&Q4, &Q1);

    model.add(&Q1);
    model.add(&Q2);
    model.add(&Q3);
    model.add(&Q4);
    model.add(&Q5);
    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);

    // model.run(0, 10);
    // assert(fabs(Q1.getValue() - 82.1225) < 0.0001);
    // assert(fabs(Q2.getValue() - 8.3484) < 0.0001);
    // assert(fabs(Q3.getValue() - 99.5740) < 0.0001);
    // assert(fabs(Q4.getValue() - 9.5504) < 0.0001);
    // assert(fabs(Q5.getValue() - 0.4046) < 0.0001);

    // Q1.setValue(100.0);
    // Q2.setValue(0.0);
    // Q3.setValue(100.0);
    // Q4.setValue(0.0);
    // Q5.setValue(0.0);

    model.run(0, 100);
    assert(fabs(Q1.getValue() - 31.8513) < 0.0001);
    assert(fabs(Q2.getValue() - 18.4003) < 0.0001);
    assert(fabs(Q3.getValue() - 77.1143) < 0.0001);
    assert(fabs(Q4.getValue() - 56.1728) < 0.0001);
    assert(fabs(Q5.getValue() - 16.4612) < 0.0001);

    // Q1.setValue(100.0);
    // Q2.setValue(0.0);
    // Q3.setValue(100.0);
    // Q4.setValue(0.0);
    // Q5.setValue(0.0);

    // model.run(0, 1000);
    // assert(fabs(Q1.getValue() - 14.3791) < 0.0001);
    // assert(fabs(Q2.getValue() - 7.5792) < 0.0001);
    // assert(fabs(Q3.getValue() - 24.4748) < 0.0001);
    // assert(fabs(Q4.getValue() - 27.2798) < 0.0001);
    // assert(fabs(Q5.getValue() - 126.2870) < 0.0001);

    cout << "Complex test passed :)." << endl
        << "*------------------------------*\n" << endl;
}
