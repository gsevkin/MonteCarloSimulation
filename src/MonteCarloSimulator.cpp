#include "../include/MonteCarloSimulator.h"

MonteCarloSimulator::MonteCarloSimulator()
{
    _radius = 1;
    _distribution = uniform_real_distribution<double>(0,_radius);
}

bool MonteCarloSimulator::Simulate()
{
    int inCircleCounter = 0;
    int counter = 0;

    while(true)
    {
        double x = _distribution(_generator);
        double y = _distribution(_generator);

        _cn = new ComplexNumbers(x, y);

        if(_cn->Magnitude()<=_radius)
            ++inCircleCounter;
        counter++;

        double aprPi = 4*(double)inCircleCounter/counter;

        _piValues.push_back(aprPi);

        if(std::abs(PI-aprPi ) < 0.0000001)
            break;
    }

    return true;
}

void MonteCarloSimulator::PrintVals()
{
    for(unsigned int i = 0; i< _piValues.size(); i++)
    {
        std::cout <<i+1<<", "<<_piValues[i]<<std::endl;
    }
}

void MonteCarloSimulator::PrintVals(string ofPath)
{
    if(ofPath == "")
    {
        PrintVals();
        return;
    }

    ofstream outfile;
    outfile.open(ofPath, ios::out | ios::trunc );

    for(unsigned int i = 0; i< _piValues.size(); i++)
    {
        outfile <<i+1<<" "<<_piValues[i]<<std::endl;
    }

    outfile.close();
}




