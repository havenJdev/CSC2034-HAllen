#include <iostream>
#include <cmath> // log10
using namespace std;

/*
* A program using Hans Luhn's algorithm to validate a c/c number.
*/

// return true if the argument is a valid card number
bool isValid(unsigned long long int);

// get the result from step 2
int sumOfDoubleEvenPlace(unsigned long long int number);

/* return this number if argument is a single digit, otherwise
 * return the sum of the two digit argument
 */
int getDigit(int);

// return sum of odd placed digits in argument
int sumOfOddPlace(unsigned long long int);

// return true if prefix d is a prefix for number
bool prefixMatched(unsigned long long int number, int d);

// return the number of digits in argument
int getSize(unsigned long long int);

/* return the first k number of digits from number.  If the
 * number of digits in number is is less than k, return number.
 */
unsigned long int getPrefix(unsigned long long int number, int k);

int main() {
    unsigned long long int ccNum;
    char stopChar = 'y';
    do {
        cout << endl << "Enter a credit card number: ";
        cin >> ccNum;
        cout << endl << ccNum << ((isValid(ccNum)) ? " is" : " is not") << " a valid credit card number." << endl;
        cout << "Enter another number? (y/n): ";
        cin >> stopChar;
    } while (stopChar != 'n');
}

bool isValid(unsigned long long int num) {
    if(getSize(num) >= 13 && getSize(num) <= 16 && (prefixMatched(num, 4) || prefixMatched(num, 5)
    || prefixMatched(num, 6) || prefixMatched(num, 37)))
        {
            return (sumOfOddPlace(num) + sumOfDoubleEvenPlace(num)) % 10 == 0;
        }
    return false;
}


int sumOfDoubleEvenPlace(unsigned long long int number){
    int sum = 0;
    int position = 1;  // Variable to keep track of the position of the digit

    while (number > 0) {
        int digit = number % 10;

        if (position % 2 == 0) {
            digit *= 2;

            // If the doubling results in a two-digit number, add up the two digits
            digit = getDigit(digit);

            sum += digit;  // Add the digit to the sum
        }

        position++;
        number /= 10;
    }

    return sum;
}

int getDigit(int number){
    int digitSum = 0;
    while (number > 0) {
        digitSum += number % 10;
        number /= 10;
    }
    return digitSum;
}

int sumOfOddPlace(unsigned long long int number) {
    int sum = 0;
    int position = 1;  // Variable to keep track of the position of the digit

    while (number > 0) {
        int digit = number % 10;

        if (position % 2 != 0) {
            sum += digit;  // Add the odd-placed digit to the sum
        }

        position++;
        number /= 10;
    }

    return sum;
}

bool prefixMatched(unsigned long long int number, int d){
    if(d >= 10){
        return getPrefix(number, 2) == d;
    } else {
        return getPrefix(number, 1) == d;
    }
}

int getSize(unsigned long long int num){
    return static_cast<int>(log10(num)) + 1;
}

unsigned long int getPrefix(unsigned long long int number, int k){
    // Get the number of digits in the given number
    int numDigits = getSize(number);

    // If the number of digits is less than or equal to k, return the number itself
    if (numDigits <= k) {
        return number;
    }

    // Extract the first k digits from the number
    unsigned long long int divisor = static_cast<unsigned long long int>(pow(10, numDigits - k));
    return static_cast<unsigned long int>(number / divisor);
}