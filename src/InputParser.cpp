#include "../include/InputParser.h"

InputParser::InputParser(int argc, char* argv[])
{
    _argc = argc;
    for(int i=0; i<_argc ; i++)
    {
        _argv.push_back(argv[i]);
    }
}

bool InputParser::Parse()
{
    for(int i = 1; i < _argc; i++)
    {
        if(_argv[i] == "-o")
        {
            ++i;
            if(i==_argc)return false;

            _outputFileName = _argv[i];
        }
    }
    return true;
}

std::string InputParser::GetOutputFileName()
{
    return _outputFileName;
}

void InputParser::PrintParserUsage()
{
    std::cout << "if you enter output path in the following way, system generates the output. Otherwise pi approximation is printed to the command window."<<std::endl;
    std::cout << "-o outputPath"<<std::endl;
}

