#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setbase
#include <cstdio>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


int main() {
	// setbase example
	std::cout << std::setbase(16);
	std::cout << "hex number for 110 is " << 110 << std::endl;
	 
	/* srand example */
	unsigned long long d = time(NULL);
	std::cout << sizeof(d) << std::endl;
	printf("First number: %d\n", rand() % 100);
	srand(time(NULL));
	printf("Random number: %d\n", rand() % 100);
	srand(1);
	printf("Again the first number: %d\n", rand() % 100);

	return 0;
}