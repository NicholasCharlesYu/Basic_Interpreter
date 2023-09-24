BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall -std=c++11 -Ilib 

all: $(BIN_DIR)/.dirstamp ./Interpreter

./Interpreter: src/Interpreter.cpp $(BIN_DIR)/ProgramState.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/EndStatement.o $(BIN_DIR)/PrintAllStatement.o $(BIN_DIR)/AddStatement.o $(BIN_DIR)/SubStatement.o $(BIN_DIR)/MultStatement.o $(BIN_DIR)/DivStatement.o $(BIN_DIR)/GoToStatement.o $(BIN_DIR)/IfThenStatement.o $(BIN_DIR)/GoSubStatement.o $(BIN_DIR)/ReturnStatement.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/ProgramState.o: src/ProgramState.cpp lib/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/PrintStatement.o: src/PrintStatement.cpp lib/PrintStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/LetStatement.o: src/LetStatement.cpp lib/LetStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/EndStatement.o: src/EndStatement.cpp lib/EndStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/PrintAllStatement.o: src/PrintAllStatement.cpp lib/PrintAllStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/AddStatement.o: src/AddStatement.cpp lib/AddStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/SubStatement.o: src/SubStatement.cpp lib/SubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/MultStatement.o: src/MultStatement.cpp lib/MultStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/DivStatement.o: src/DivStatement.cpp lib/DivStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/GoToStatement.o: src/GoToStatement.cpp lib/GoToStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/IfThenStatement.o: src/IfThenStatement.cpp lib/IfThenStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/GoSubStatement.o: src/GoSubStatement.cpp lib/GoSubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/ReturnStatement.o: src/ReturnStatement.cpp lib/ReturnStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@



.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp