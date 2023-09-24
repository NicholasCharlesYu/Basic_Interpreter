#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"

class AddStatement : public Statement {
private:
    std::string m_variableName;
    std::string m_variableString;
    int m_variableInt;

public:
    // Two constructors to deal with integers and variables
    AddStatement(std::string variableName, std::string variableString);
    AddStatement(std::string variableName, int variableInt);
    ~AddStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
