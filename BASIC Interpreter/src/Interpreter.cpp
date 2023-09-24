// Interpreter.cpp
#include "AddStatement.h"
#include "DivStatement.h"
#include "EndStatement.h"
#include "GoSubStatement.h"
#include "GoToStatement.h"
#include "IfThenStatement.h"
#include "LetStatement.h"
#include "MultStatement.h"
#include "PrintAllStatement.h"
#include "PrintStatement.h"
#include "ProgramState.h"
#include "ReturnStatement.h"
#include "Statement.h"
#include "SubStatement.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement*>& program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement* parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
void interpretProgram(istream& inf, ostream& outf);

int main() {
    cout << "Enter BASIC program file name: ";
    string filename;
    getline(cin, filename);
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "Cannot open " << filename << "!" << endl;
        return 1;
    }
    interpretProgram(infile, cout);
}

void parseProgram(istream& inf, vector<Statement*>& program) {
    program.push_back(NULL);

    string line;
    while (!inf.eof()) {
        getline(inf, line);
        program.push_back(parseLine(line));
    }
}

Statement* parseLine(string line) {
    Statement* statement;
    stringstream ss;
    int line_num;
    string type;
    string var;
    int val;

    ss << line;
    ss >> line_num;
    ss >> type;

    if (type == "LET") {
        ss >> var;
        ss >> val;
        statement = new LetStatement(var, val);
    }

    // PRINT
    else if (type == "PRINT") {
        ss >> var;
        statement = new PrintStatement(var);
    }

    // END or .
    else if (type == "END" || type == ".") {
        statement = new EndStatement();
    }

    // PRINTALL
    else if (type == "PRINTALL") {
        statement = new PrintAllStatement();
    }

    // ADD
    else if (type == "ADD") {
        ss >> var;
        string temp;
        ss >> temp;
        stringstream ts(temp);
        int isInt;

        if (ts >> isInt) {
            statement = new AddStatement(var, isInt);
        } else {
            statement = new AddStatement(var, temp);
        }
    }

    // SUB
    else if (type == "SUB") {
        ss >> var;
        string temp;
        ss >> temp;
        stringstream ts(temp);
        int isInt;

        if (ts >> isInt) {
            statement = new SubStatement(var, isInt);
        } else {
            statement = new SubStatement(var, temp);
        }
    }

    // MULT
    else if (type == "MULT") {
        ss >> var;
        string temp;
        ss >> temp;
        stringstream ts(temp);
        int isInt;

        if (ts >> isInt) {
            statement = new MultStatement(var, isInt);
        } else {
            statement = new MultStatement(var, temp);
        }
    }

    // DIV
    else if (type == "DIV") {
        ss >> var;
        string temp;
        ss >> temp;
        stringstream ts(temp);
        int isInt;

        if (ts >> isInt) {
            statement = new DivStatement(var, isInt);
        } else {
            statement = new DivStatement(var, temp);
        }
    }

    // GOTO
    else if (type == "GOTO") {
        ss >> val;
        statement = new GoToStatement(val);
    }

    // IF
    else if (type == "IF") {
        string compOperator;
        string then;
        int lineNum;
        ss >> var;
        ss >> compOperator;
        ss >> val;
        ss >> then;
        ss >> lineNum;
        statement = new IfThenStatement(var, compOperator, val, lineNum);
    }

    // GOSUB
    else if (type == "GOSUB") {
        ss >> val;
        statement = new GoSubStatement(val);
    }

    // RETURN
    else if (type == "RETURN") {
        statement = new ReturnStatement();
    }

    return statement;
}

void interpretProgram(istream& inf, ostream& outf) {
    vector<Statement*> program;
    parseProgram(inf, program);

    ProgramState* state = new ProgramState(program.size() - 1);
    while (!state->getTerminate()) {
        program[state->valCounter()]->execute(state, outf);
    }

    // Deallocate
    for (size_t i = 0; i < program.size(); i++) {
        delete program[i];
    }
    delete state;
}
