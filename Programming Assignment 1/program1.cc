#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

// Function to check if a number is valid for a given base
// Ensures each digit in the number is within the valid range for the given base
bool isValidNumber(std::string number, int base) {
    for (char digit : number) {
        if (digit < '0' || digit >= ('0' + base)) {
            return false; // Invalid digit found
        }
    }
    return true; // All digits are valid
}

// Function to convert a number from base b to base 10
int toDecimal(std::string number, int base) {
    int result = 0;
    for (char digit : number) {
        result = result * base + (digit - '0'); // Convert character to integer and compute decimal value
    }
    return result;
}

int main() {
    std::string number; // Stores the input number as a string
    int base; // Stores the input base
    char moreInput; // Stores user choice for continuing input
    int count = 0, maxDecimal = -1, maxPosition = 0;

    while (cin >> number >> base) {
        // Check if base is within the accepted range (2-9)
        if (base < 2 || base > 9) {
            cout << "Base Not Accepted" << endl;
            return 0;
        }
        
        // Validate that the number contains only valid digits for the given base
        if (!isValidNumber(number, base)) {
            cout << "Invalid Digit(s) in Number" << endl;
            return 0;
        }
        
        // Convert the valid input number to decimal
        int decimalValue = toDecimal(number, base);
        cout << decimalValue << endl;
        count++; // Increment input count
        
        // Update maximum decimal value and its position if a new max is found
        if (decimalValue > maxDecimal) {
            maxDecimal = decimalValue;
            maxPosition = count;
        }
        
        // Read user input to determine whether to continue or stop
        cin >> moreInput;
        if (moreInput == 'n') {
            // Print the final result
            cout << "Of the " << count << " values input, the ";
            if (maxPosition % 10 == 1 && maxPosition % 100 != 11) cout << maxPosition << "st";
            else if (maxPosition % 10 == 2 && maxPosition % 100 != 12) cout << maxPosition << "nd";
            else if (maxPosition % 10 == 3 && maxPosition % 100 != 13) cout << maxPosition << "rd";
            else cout << maxPosition << "th";
            cout << " value entered (" << maxDecimal << ") was the largest" << endl;
            return 0; // End program execution
        }
    }
    return 0; // Ensure program ends cleanly if loop exits naturally
}
