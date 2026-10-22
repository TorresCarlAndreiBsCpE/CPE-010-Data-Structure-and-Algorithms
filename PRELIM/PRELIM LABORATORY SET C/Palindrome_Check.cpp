#include <iostream>
#include <vector>
#include "Palindrome_Check.h"

//Pseudocode
// MAIN APPLICATION (TESTING OF DATASET & USER INPUT OPTION)
// START
    // 1. Initialize predefined test cases
    // Create dynamic list testCases containing:
        //"10201", //Palindrome
        //"1003003001", //Palindrome
        //"1451", //Not a Palindrome
        //"88", //Palindrome
        //"1234", //Not a Palindrome
        //"0", //Palindrome
        //"911", //Not a Palindrome
        //"6969", //Not a Palindrome
        //"202" //Palindrome

int main() {
    // Test dataset of sample palindrome numbers
    std::vector<std::string> testCases = {
        "10201", //Palindrome
        "1003003001", //Palindrome
        "1451", //Not a Palindrome
        "88", //Palindrome
        "1234", //Not a Palindrome
        "0", //Palindrome
        "911", //Not a Palindrome
        "6969", //Not a Palindrome
        "202" //Palindrome
    };

 //Pseudocode
 // PRINT "--- PALINDROME CHECKER (Stack vs. Queue) ---"

    std::cout << "--- PALINDROME CHECKER (Stack vs. Queue) ---\n\n";
    
//Pseudocode
// 2. Iterate and test all predefined test cases
// FOR EACH str IN testCases DO
    // PRINT "Testing: \"" + str + "\" -> "
    // IF isPalindrome(str) IS True THEN
        // PRINT "VALID Palindrome"
    // ELSE
        // PRINT "NOT a Palindrome"
    // END IF
    // END FOR

    for (const std::string& str : testCases) {
        std::cout << "Testing: \"" << str << "\" -> ";
        if (isPalindrome(str)) {
            std::cout << "VALID Palindrome\n";
        } else {
            std::cout << "NOT a Palindrome\n";
        }
    }

//Pseudocode
// PRINT "--------------------------------------------"

    // Interactive user input section
    std::cout << "\n--------------------------------------------\n";

//Pseudocode
// 3. Prompt user for custom input
    // DECLARE userInput AS String
    // PRINT "Enter a custom number to test: "
    // READ userInput FROM user input

    // PRINT "Palindrome? \"" + userInput + "\": "

    std::string userInput;
    std::cout << "Enter a custom number to test: ";
    std::cin >> userInput;

//Pseudocode
// 4. Test user input
    // IF isPalindrome(userInput) IS True THEN
        // PRINT "VALID Palindrome"
    // ELSE
        // PRINT "NOT a Palindrome"
    // END IF
// END

    std::cout << "Palindrome? \"" << userInput << "\": ";
    if (isPalindrome(userInput)) {
        std::cout << "VALID Palindrome\n";
    } else {
        std::cout << "NOT a Palindrome\n";
    }

    return 0;
}