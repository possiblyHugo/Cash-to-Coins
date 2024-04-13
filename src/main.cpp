#include <string>
#include <iostream>
#include <cctype>

bool stringIsNumber(std::string stringToCheck) {
	for (int i = 0; i < stringToCheck.length(); i++) {
		if (!isdigit(stringToCheck[i])) {
			return false;
		}
	}
	return true;
}

int stringToChange(std::string change) {
	int result = 0;

	// Search for "$" and "." and removes them
	std::size_t found = change.find("$");

	if (found != std::string::npos) {
		change.erase(found);
	}

	found = change.find(".");
	if (found != std::string::npos) {
		change.erase(found);
	}

	bool isNumber = stringIsNumber(change);

	if (!isNumber) {
		std::cout << "There was an error converting the string to a number" << std::endl;
		exit(1);
	}

	return result;
}

int main() {
	
	// Format ["$12.30"]
	std::string change;
	std::cin >> change;

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

	// This is currently here for testing
	std::cout << quarters << " | " << dimes << " | " << nickles << " | " << pennies << std::endl;


	return 0;
}