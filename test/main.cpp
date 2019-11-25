#include "../include/InputParser.h"
#include "../include/MonteCarloSimulator.h"

/**
* This program is objected to approximate
* Pi using Monte Carlo simulation method.
* If user specify the output path, than the
* output is a text file, otherwise it is
* printed on the terminal.
*/
int main(int argc, char* argv[])
{
    InputParser *inPar = new InputParser(argc, argv);

    if(!inPar->Parse())
    {
        inPar->PrintParserUsage();
        return 1;
    }

    string ofPath = inPar->GetOutputFileName();

    MonteCarloSimulator *mcs = new MonteCarloSimulator();

    mcs->Simulate();
    mcs->PrintVals(ofPath);

    return 0;
}
