#pragma once
#include "CDLL.h"
#include "TopSpinADT.h"
#include <iostream>

class TopSpin : public TopSpinADT {

public:
	TopSpin(int size, int spinSize); //constructor creates a new board from a user inputted size
	//~TopSpin();
	void shiftLeft(); //moves puzzle one space to the left
	void shiftRight(); //moves puzzle one space to the right
	void spin();
	bool isSolved();
	void random(unsigned int times);
	friend std::ostream& operator<<(std::ostream& output, const TopSpin& ts);

private:
	int spinMechSize;
	int boardSize;
	CDLL<int> newBoard;
};

static std::ostream& operator<< (std::ostream& output, const TopSpin& ts) {
	//will print numbers inside spinner mechanism:
	for (int i(0); i < ts.spinMechSize * 3; i++) {
		output << "-";
	}
	output << std::endl;
	output << " |";
	for (int i(0); i < ts.spinMechSize; i++) {
		output << " ";
		output << ts.newBoard.getData(i + 1);
	}
	output << " |";

	//will print all other numbers
	for (int i(ts.spinMechSize); i < ts.boardSize; i++) { 
		output << " ";
		output << ts.newBoard.getData(i + 1);
	}
	output << std::endl;
	for (int i(0); i < ts.spinMechSize * 3; i++) {
		output << "-";
	}
	output << std::endl;

	return output;
}