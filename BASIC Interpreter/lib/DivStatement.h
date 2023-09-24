#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"

class DivStatement : public Statement {
private:
    std::string m_variableName;
    std::string m_variableString;
    int m_variableInt;

public:
    // Two constructors to deal with integers and variables
    DivStatement(std::string variableName, std::string variableString);
    DivStatement(std::string variableName, int variableInt);
    ~DivStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
