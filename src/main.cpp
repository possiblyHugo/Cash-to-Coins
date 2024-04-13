#include <iostream>
#include <string>

int main() {
	std::string change;
	//std::cin >> change;

	int intChange = 1623;

	int quarters, dimes, nickles, pennies;
	quarters = dimes = nickles = pennies = 0;

	while (intChange > 0) {
		if (intChange >= 100) {
			int tempVal = intChange / 100;
			quarters = tempVal * 4;
			intChange -= tempVal * 100;
		}
		else if (intChange >= 10) {
			dimes = intChange / 10;
			intChange -= dimes * 10;
		}
		else if (intChange >= 5) {
			nickles = intChange / 5;
			intChange -= nickles * 5;
		}
		else if (intChange >= 1) {
			pennies = intChange;
			intChange -= intChange;
		}
	}

	std::cout << quarters << " | " << dimes << " | " << nickles << " | " << pennies << std::endl;


	return 0;
}