#include "Day2.h"

//read the input, the first character of the line and the last character for quantity. Make a vector then calculate length.

void Day2A()
{

	int Position[2] = { 0,0 };
	int Aim = 0;

	std::ifstream InFile;
	InFile.open("Day2Input.txt", std::ios::in);

	std::string Line;
	std::string Val;
	
	while (std::getline(InFile, Line))
	{
		Val = Line.back();
		if(Line.front() == 'f')
		{
			Position[0] += std::stoi(Val);
			Position[1] += Aim * std::stoi(Val);
		}
		else if (Line.front() == 'd')
		{
			Aim += std::stoi(Val);
		}
		else if (Line.front() == 'u')
		{
			Aim -= std::stoi(Val);
		}

	}
	std::cout << Position[0] << " " << Position[1] << std::endl;
	std::cout << Position[0] * Position[1] << std::endl;

	
}