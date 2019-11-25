#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>
#include <iostream>
#include<vector>

/**
* InputParser class parses command line arguments.
*/
class InputParser
{
    public:
        /**
        * Constructor for InputParser class.
        **/
        InputParser(int argc, char* argv[]);

        /**
        * Parser method takes the input string
        * and searches the key words.
        **/
        bool Parse();

        /**
        * Get method for output path.
        **/
        std::string GetOutputFileName();

        /**
        * In case of wrong usage, this
        * method prints the correct usage.
        **/
        void PrintParserUsage();

    private:
        int _argc;
        std::vector<std::string> _argv;
        std::string  _outputFileName;
};

#endif // INPUTPARSER_H
