#include "Day1.h"

#include <iostream>
#include <string>

int CountIncreases()
{
	int HitCount = 0;
	int OldVal = -1;
	int NewVal;
	int Delta;
	
	std::ifstream InFile;
	InFile.open("Day1Input.txt", std::ios::in);
	
	std::string Line;
	while (std::getline(InFile, Line))
	{
		if (OldVal == -1) { OldVal = std::stoi(Line); }
		else
		{
			NewVal = std::stoi(Line);
			Delta = NewVal / OldVal;
			if (Delta >= 1) { HitCount++; }
			OldVal = std::stoi(Line);
		}
	}
	
	//now loop compare and return
	return HitCount;
	
}
