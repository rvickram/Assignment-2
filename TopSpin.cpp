#include "TopSpin.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

TopSpin::TopSpin(int size, int spinSize) { //Constructor
	//check for valid values, use default if not:
	if (size > 1 && spinSize <= size && spinSize > 0) {
		boardSize = size;
		spinMechSize = spinSize;
		for (int i(1); i < (boardSize + 1); i++) {
			newBoard.addData(i);
		}
	}
	else {
		boardSize = 20;
		spinMechSize = 4;
		for (int i(1); i < (boardSize + 1); i++) {
			newBoard.addData(i);
		}
	}
	std::cout << "A board of size " << boardSize << ", and spinner size " << spinMechSize << " was created." << std::endl;
}

//TopSpin::~TopSpin() { 
//	
//}

void TopSpin::shiftLeft() {
	newBoard.decrementHead(); 
}

void TopSpin::shiftRight() { //shifts to right
	newBoard.incrementHead();
}

void TopSpin::spin() { //spins the numbers in the spin mechanism
	for (int i(0); i < (spinMechSize / 2); i++) {
		newBoard.swap(i + 1, spinMechSize - i);
	}
} 

bool TopSpin::isSolved() { //true if solved, false if not
	int xi(0), prev(1);
	for (CDLL<int>::Iterator k = newBoard.begin(); k != newBoard.end(); ++k) {
		xi++;
		if (prev != k.getValue()) { return false; }
		else { prev++; }
		if (xi == boardSize) { break; }
	}
	return true;
}

void TopSpin::random(unsigned int times) { ///NOT SCRAMBLING WELL......
	srand((unsigned int)time(NULL));
	int randInt = (rand() % 19 + 1);
	for (int j(0); j <times; j++) {
		for (int i(0); i < randInt; i++) {
			this->shiftLeft();
		}
		this->spin();
	}
}