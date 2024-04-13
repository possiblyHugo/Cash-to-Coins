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
		change.erase(change.begin() + found);
	}

	found = change.find(".");
	if (found != std::string::npos) {
		change.erase(change.begin() + found);
	}

	bool isNumber = stringIsNumber(change);

	if (!isNumber) {
		std::cout << "There was an error converting the string to a number" << std::endl;
		exit(1);
	}

	return stoi(change);
}

int main() {
	// Format ["$12.30"]
	std::string change;
	std::cin >> change;

	int changeAsInt = stringToChange(change);

	int quarters, dimes, nickles, pennies;
	quarters = dimes = nickles = pennies = 0;

	while (changeAsInt > 0) {
		if (changeAsInt >= 100) {
			int tempVal = changeAsInt / 100;
			quarters = tempVal * 4;
			changeAsInt -= tempVal * 100;
		}
		else if (changeAsInt >= 10) {
			dimes = changeAsInt / 10;
			changeAsInt -= dimes * 10;
		}
		else if (changeAsInt >= 5) {
			nickles = changeAsInt / 5;
			changeAsInt -= nickles * 5;
		}
		else if (changeAsInt >= 1) {
			pennies = changeAsInt;
			changeAsInt -= changeAsInt;
		}
	}

	// This is currently here for testing
	std::cout << quarters << " | " << dimes << " | " << nickles << " | " << pennies << std::endl;


	return 0;
}