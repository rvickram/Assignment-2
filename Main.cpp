#include "CDLL.h"
#include "TopSpin.h"
#include <iostream>

int main() {
	//enter board size and spinner size
	std::cout << "Enter the board size: ";
	int x; std::cin >> x;
	std::cout << "Enter the spinner size: ";
	int y; std::cin >> y;
	TopSpin newGame(x, y); //create object based on user inputs
	std::cout << newGame; //print unscrambled game
	std::cout << "Enter a random number to scramble the puzzle with:";
	std::cin >> y; newGame.random(y);
	std::cout << newGame;
	char switchDir;

	//loop contains menu for game
	while (1) {
		x = -1; //stores response from main menu:
		y = -1; //stores number of shifts response
		switchDir = 'a'; //stores response for shift direction

		//ask user to make a move and verify
		std::cout << "Make a move: " << std::endl <<
			"1. Shift   2. Spin   3.Quit" << std::endl;
		std::cin >> x;
		if (x < 1 || x > 3) { 
			std::cout << "Invalid selection..." << std::endl;
			continue; 
		}

		//execute an action based on user response
		switch (x) {
		case 1://shift
			//Ask how many shifts user would like:
			std::cout << "How many shifts would you like: ";
			std::cin >> y;

			//Ask which direction user wants to shift, and verify;
			std::cout << "Shift Left or Right: (L/R) ";
			std::cin >> switchDir;
			if (switchDir == 'l' || switchDir == 'L') {

				//shift left 'y' times:
				for (int i(0); i < y; i++) { newGame.shiftLeft(); }
				std::cout << "Board has been shifted " << y << " times to the left." << std::endl;
			}
			else if (switchDir == 'r' || switchDir == 'R') {
				//shift right 'y' times:
				for (int i(0); i < y; i++) { newGame.shiftRight(); }
				std::cout << "Board has been shifted " << y << " times to the right." << std::endl;
			}
			else { 
				std::cout << "Invalid selection. Returning to main menu..." << std::endl; 
				continue; 
			}
			break;

		case 2://spin
			newGame.spin();
			std::cout << "Items have been spun!" << std::endl;
			break;
		case 3:
			std::cout << "Quitting..." << std::endl;
			return 0;
			break;
		}
		std::cout << newGame;
		if (newGame.isSolved()) {
			std::cout << "CONGRATULATIONS!!!!!!!!!!!" << std::endl;
			return 0;
			break;
		}
	}
}


//BELOW IS THE TESTING MAIN FOR CDLL

//using namespace std;
//int menu();
//int main() {
//	CDLL<int> a;
//
//	while (1) {
//		int d(0), e(0), xi(0);
//		switch (menu()) {
//		case 1:
//			for (int i(1); i < 21; i++) {
//				a.addData(i);
//			}
//			break;
//		/*case 2:
//			cout << "The list has a size of " << a.getSize() << endl;
//			break;*/
//		case 3:
//			cout << "Which item would you like to see: ";
//			cin >> d;
//			cout << "The item at " << d << " has a value of " << a.getData(d) << endl;
//			break;
//		case 4:
//			cout << "List items: " << endl;
//			for (CDLL<int>::Iterator k = a.begin(); k != a.end(); ++k) {
//				xi++;
//				cout << k.getValue() << endl;
//				if (xi == 20) { break; }
//			}
//			break;
//		case 5:
//			a.incrementHead();
//			cout << "Array has been shifted right!" << endl;
//			break;
//		case 6:
//			a.decrementHead();
//			cout << "Array has been shift left!" << endl;
//			break;
//		case 7:
//			cout << "Enter the 1st swap: ";
//			cin >> d;
//			cout << endl << "Enter the 2nd swap: ";
//			cin >> e;
//			a.swap(d, e);
//			break;
//		case 8:
//			return 0;
//			break;
//		}
//	}
//	return 0;
//}
//
//int menu() {
//	cout << "Select an option:" << endl
//		<< "1. Add value" << endl
//		<< "2. Get size" << endl
//		<< "3. Get value" << endl
//		<< "4. Print array" << endl
//		<< "5. Shift right" << endl
//		<< "6. Shit left" << endl
//		<< "7. Swap" << endl
//		<< "8. Quit" << endl;
//	int selection; cin >> selection;
//	return selection;
//}