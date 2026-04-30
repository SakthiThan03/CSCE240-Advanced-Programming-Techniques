//Copyright Sakthi Thanigai 02/17/25
#include "program2functions.h"

bool IsSquare(int num) {
    if (num < 0 ) return false;
    int root = std::sqrt(num);
    return root * root == num;
}

bool IsPerfect(int num) {
    if (num <= 1) return false;
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
            sum += num / i;
            }
        }
    }
    return sum == num;
}

bool IsVowel(char c, bool yIsVowel) {
    // Defines standard vowels
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    // Check for whether 'y' is considered a vowel
    if (yIsVowel && c == 'y') {
        return true;
    }
    return false;
}

bool IsConsonant(char c, bool yIsConsonant) {
    //Return false if not a letter
    if (!isalpha(c)) {
        return false;
    }
    //Return false if letter is a vowel
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return false;
    }
    //Special case for 'y' letter
    if (c == 'y' && !yIsConsonant) {
        return false;
    }
    //Is a consonant
    return true;
}

int ToDigit(char c) {
    if (c >= '0' && c <= '9') {
        //Convert character to integer
        return c - '0';
    }
    //Return 0 if entry is not a digit
    return 0;
}

int Range(int &x, int &y) {
    if (x > y) {
        //Swaps so smaller number is 'x' and larger number is 'y'
        std::swap(x,y);
    }
    //Returns range of x and y
    return y - x;
}

int DigitInPosition(double num, int position) {
    if (position < 0) {
        //Extracts digits to the left of the ones place
        num = fabs(num); //No negative numbers
        int int_part = static_cast<int>(num);
        int digit = (int_part / static_cast<int>(pow(10, abs(position)))) % 10;
        return digit;
    } else {
        //Extracts digits to the right of the ones place
        num = fabs(num);
        int digit = static_cast<int>(num * pow(10, position)) % 10;
        return digit;
    }
}
