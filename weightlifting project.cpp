#include <iostream>   

namespace StrengthCategory { // here we declare a namespace StrengthCategory, which contains the categories of strength and also the calculations for them which are used later

	enum Category { // an enumeration is created with our set constants: the level of strength. This makes our code more readable and is preferrable for specific labels
		Beginner,
		Novice,
		Intermediate,
		Advanced,
		Elite
	};

	Category calculateSquatCategory(double ratio) { // we declare a function for calculating our lift categories using set ratios (obtained online)
		// we declare the ratio using double for decimal places and we use this in conjunction with our calculation to return one of our 5 enum categories
		if (ratio <= 0.75 && ratio < 1.25)
			return Beginner;
		else if (ratio >= 1.25 && ratio < 1.5)
			return Novice;
		else if (ratio >= 1.5 && ratio < 2.25)
			return Intermediate;
		else if (ratio >= 2.25 && ratio < 2.75)
			return Advanced;
		else
			return Elite;
	}
	// here we see that if our ratios are within certain thresholds, they should return a set category to the user. We use if and else if statements to cycle through these
	// && is used to ensure that we only return certain categories if BOTH conditions are true, this prevents an issue found earlier where it would return incorrect categories

	Category calculateBenchCategory(double ratio) {
		if (ratio <= 0.5 && ratio < 0.75)
			return Beginner;
		else if (ratio >= 0.75 && ratio < 1.25)
			return Novice;
		else if (ratio >= 1.25 && ratio < 1.75)
			return Intermediate;
		else if (ratio >= 1.75 && ratio < 2.00)
			return Advanced;
		else
			return Elite;
	}



	Category calculateDLCategory(double ratio) {
		if (ratio <= 1.00 && ratio < 1.50)
			return Beginner;
		else if (ratio >= 1.50 && ratio < 2.00)
			return Novice;
		else if (ratio >= 2.00 && ratio < 2.50)
			return Intermediate;
		else if (ratio >= 2.50 && ratio < 3.00)
			return Advanced;
		else
			return Elite;
	}
	// this is repeated for our Deadlift and Bench Press categories too, which all use different ratios (hence making modulating this a little tricky.) 
}

void printCategory(StrengthCategory::Category category) { // here void is used to print information to the console which can then be called later on
	// this section creates switch cases for each category and we will later call the StrengthCategory via print when appropriate arguments are met
	//  switch case is  more readable and useful here as we are utilizing enumeration of specific values rather than strings or integers
	switch (category) {
	case StrengthCategory::Beginner:
		std::cout << "Beginner\n";
		break;

	case StrengthCategory::Novice:
		std::cout << "Novice\n";
		break;
	
	case StrengthCategory::Intermediate:
		std::cout << "Intermediate\n";
		break;

	case StrengthCategory::Advanced:
		std::cout << "Advanced\n";
		break;

	case StrengthCategory::Elite:
		std::cout << "Elite\n";
		break;
	}

}



int main() {


	// here some key values are declared as double (useful as precise calculations of decimals are required) 
	// the user is prompted to enter their bodyweight and each lift 1RM (1 rep max) which is helpful to determine overall strength in an exercise
	double bodyWeight, squatWeight, benchWeight, DLWeight;
	std::cout << "Welcome to Strength Calculator\n";
	std::cout << "Please enter Bodyweight in kg: ";
	std::cin >> bodyWeight;


	std::cout << "Please enter your squat 1RM in kg: ";
	std::cin >> squatWeight;

	double squatRatio = squatWeight / bodyWeight;


	std::cout << "Please enter your bench press 1RM in kg: ";
	std::cin >> benchWeight;

	double benchRatio = benchWeight / bodyWeight;


	std::cout << "Please enter your deadlift 1RM in kg: ";
	std::cin >> DLWeight;

	double DLRatio = DLWeight / bodyWeight;
// for each lift we also calculate our ratios, this is dont by dividing the weight of the lift by our bodyweight, again this is a tradiitonal way to determine strength levels 
// we also declare each individual ratio here too, using double again to perform the precise calculation. 
	std::cout << "Your strength category for Squat is: ";
	printCategory(StrengthCategory::calculateSquatCategory(squatRatio));


	std::cout << "Your strength category for Bench Press is: ";
	printCategory(StrengthCategory::calculateBenchCategory(benchRatio));


	std::cout << "Your strength category for Deadlift is: ";
	printCategory(StrengthCategory::calculateDLCategory(DLRatio));
// finally we use printCategory to call our namespace StrengthCategory which contains our enums for which level of strength we are at
// we call calculateXCategory for each lift, and the result of these is our calculated ratios, the ratio is compared to the enums and the appropriate strength levels are returned to the user via cout

	system("pause");
// here we pause the program to give the user a chance to read the returned information. I could instead use an infinite loop or ask for user prompt to close the program instead..
// if this line is not added, the program closes immediately after user finishing calculations and user cannot read the info
	return 0;


}