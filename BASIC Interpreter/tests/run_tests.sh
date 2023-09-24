#!/bin/bash

# Check for file
EXECUTABLEPATH="../Interpreter" 
if [ ! -f $EXECUTABLEPATH ]; then
    echo "Error:  Could not find $EXECUTABLEPATH you may need to change line 11 of the script to match your executable location"
    exit 1
fi

# Run all tests
for n in {1..50};
do
    echo "Running Test $n"
    ./$EXECUTABLEPATH <<< "test_input/facile_test$n.txt" > "test_output/facile_output$n.txt"
    if [ $? -ne 0 ]; then
        # Stop if the executable does not return 0
        echo "Error on test $n, check that the test does not crash and make sure it returns 0 from main"
        exit 1
    else
        test_output="test_output"
        output_file="$test_output/facile_output$n.txt"
        solution_file="$test_output/facile_solution$n.txt"
        output_start_text="Enter BASIC program file name: "
        # Remove text that prompts for filename
        sed -i "1s/^$output_start_text//" $output_file
        # Compare outputs
        diff $output_file $solution_file > /dev/null 2>&1
        if [ $? -ne 0 ]; then
            diff $output_file $solution_file
            echo "Test $n failed, check output/solution file for differences"
            exit 1
        else
            echo "Test $n passed!"
        fi
    fi
done