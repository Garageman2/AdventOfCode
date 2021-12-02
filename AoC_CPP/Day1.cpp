#include "Day1.h"

#include <iostream>
#include <string>
#include <vector>


int CountIncreases()
{
	int HitCount = 0;
	int OldVal = -1;
	int NewVal;
	int Delta;

	std::vector<int>Parts;
	int SumIncrease = 0;

	
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
		
		std::cout << "length " << Parts.size() << std::endl;
		if (Parts.size() < 4) { Parts.push_back(std::stoi(Line)); }
		else
		{
			//not detecting all
			std::cout << Parts.at(0) << "  ,  " << Parts.at(3) << std::endl;
			if (Parts.at(3) > Parts.at(0)) { SumIncrease++; std::cout << "True" << std::endl; }
			Parts.erase(Parts.begin());
			Parts.push_back(std::stoi(Line));
		}
	}
	

	return SumIncrease;
	
}
