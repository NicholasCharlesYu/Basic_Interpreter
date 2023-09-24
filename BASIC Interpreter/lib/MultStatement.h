#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"

class MultStatement : public Statement {
private:
    std::string m_variableName;
    std::string m_variableString;
    int m_variableInt;

public:
    // Two constructors to deal with integers and variables
    MultStatement(std::string variableName, std::string variableString);
    MultStatement(std::string variableName, int variableInt);
    ~MultStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
