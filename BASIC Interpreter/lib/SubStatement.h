#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"

class SubStatement : public Statement {
private:
    std::string m_variableName;
    std::string m_variableString;
    int m_variableInt;

public:
    // Two constructors to deal with integers and variables
    SubStatement(std::string variableName, std::string variableString);
    SubStatement(std::string variableName, int variableInt);
    ~SubStatement();

    virtual void execute(ProgramState* state, std::ostream& outf);
};

#endif
