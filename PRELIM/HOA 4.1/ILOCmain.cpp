#include <iostream>
#include "ILOC_List.h"


int main() {
    std::cout << "---USER INPUT---\n";
    std::string expression = "{[()]}"; // Example expression to check the right variables
    std::cout << "Enter an Expression: "; //User Input
    std::getline(std::cin, expression); //getLine to read all the characters in the expression
    
    std::cout << "---Push and Pop Operations---\n";
    for (char ch : expression) {
        // Check if the character is an opening symbol, then push it onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            push<char>(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') { //if the character is a closing symbol, then chec against the stack
            // Pop the matching opening symbol from the stack
            if (!pop<char>(ch)) {
                // If the pop operation fails, it means the symbols are mismatched or empty stack, it will report NOT balanced and stop the program
                std::cout << "The expression's symbols are NOT balanced." << std::endl;
                std::cout << "The expression is NOT VALID.\n"; //Reports that the expression is NOT VALID
                return 0;
            }
            //If the pop operation is successful, it will display it process
            std::cout << "Popped: " << ch << "\n";
            //shows the current top of the stack and displays all the elements in the stack
            Top<char>();
            displayAll<char>();
        }
    }
    
    std::cout << "---isEmpty and Symbol Balancing Check---\n";
    if (!isEmpty<char>()) { //checks if the stack is empty at the end of the input, if not then it will report NOT balanced or Error: stack not empty at end of input
        std::cout << "Error: stack not empty at end of input.\n"; 
        displayAll<char>(); //Displays the remaining elements in the stack
        std::cout << "The expression is NOT VALID.\n"; //Reports that the expression is NOT VALID
    } else {
        std::cout << "Symbols are balanced!\n"; //If the stack is empty at the end of the input, it will report that the symbols are balanced
        std::cout << "The expression is VALID.\n"; //Reports that the expression is VALID
    }

    return 0;
}