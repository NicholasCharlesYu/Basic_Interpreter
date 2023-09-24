#ifndef STATEMENT_INCLUDED
#define STATEMENT_INCLUDED

#include "ProgramState.h"
#include <fstream>

class Statement {
public:
    virtual ~Statement() {}
    virtual void execute(ProgramState* state, std::ostream& outf) = 0;
};

#endif
