#ifndef MONTECARLOSIMULATOR_H
#define MONTECARLOSIMULATOR_H

#include "ComplexNumbers.h"
#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include <fstream>

using namespace std;

/**
* This class creates simulator object for
* Monte Carlo method.
*/

class MonteCarloSimulator
{
    public:

        /**
        * Constructed for Monte Carlo Simulator.
        */
        MonteCarloSimulator();

        /**
        * Simulate method randomly creates points
        * in the complex plane and checks if it is
        * in the circle. Then saves an approximated
        * value for each step.
        */
        bool Simulate();

        /**
        * Prints approximated values to a file.
        */
        void PrintVals(string ofPath);

        /**
        * Prints approximated values to terminal.
        */
        void PrintVals();

    private:
        ComplexNumbers *_cn;
        std::vector<double> _piValues;
        std::default_random_engine _generator;
        std::uniform_real_distribution<double> _distribution;
        double _radius;
};

#endif // MONTECARLOSIMULATOR_H
