#include "Day3.h"


void Cull(char Test, int i);
char FindCommon(int i);
char FindCommon2(int i);
std::ifstream InFile;
std::string Gamma;
std::string Epsilon;
std::string Line;
std::vector<int> Excludes;

int Count[2];
int Answers[2];
int Results[2];


void Day3A()
{


	//0 in 0 1 in 1


	for (int i = 0; i < 12; i++)
	{
		Count[0] = 0;
		Count[1] = 0;
		InFile.open("Day3Input.txt", std::ios::in);
		while (std::getline(InFile, Line))
		{
			if (Line[i] == '0') { Count[0]++; }
			else { Count[1]++; }
		}
		InFile.close();
		
		std::cout << Count[0] << Count[1] << std::endl;
		if (Count[0] > Count[1]) { Gamma.append("0"); Epsilon.append("1"); }
		else { Gamma.append("1"); Epsilon.append("0"); }
	}
	std::cout << std::stoi(Gamma,nullptr,2) << "  " << std::stoi(Epsilon,nullptr,2) << std::endl;
	std::cout << std::stoi(Gamma, nullptr, 2) * std::stoi(Epsilon, nullptr, 2) << std::endl;


	int Index = 0;

	while(Excludes.size() < 999)
	{
		Cull(FindCommon(Index), Index);
		Index++;
		std::cout << "length " << Excludes.size() << std::endl;
		if (Excludes.size() == 998) { std::cout << "solved" << std::endl; break; }
		if (Index > 12) { break; }
	}
	//iterate through one more time, exclude all excludes to find included line
	for(int i = 0; i<1001;i++)
	{
		if (std::find(Excludes.begin(), Excludes.end(), i) == Excludes.end()) { std::cout << "the result is line " << i << std::endl; Answers[1] = i; break; }
	}

	Index = 0;
	Excludes.clear();

	while (Excludes.size() < 999)
	{
		Cull(FindCommon2(Index), Index);
		Index++;
		std::cout << "length " << Excludes.size() << std::endl;
		if (Excludes.size() == 998) { std::cout << "solved" << std::endl; break; }
		if (Index > 12) { break; }
	}
	//iterate through one more time, exclude all excludes to find included line
	for (int i = 0; i < 1001; i++)
	{
		if (std::find(Excludes.begin(), Excludes.end(), i) == Excludes.end()) { std::cout << "the result is line " << i << std::endl; Answers[0] = i; break; }
	}

	
	InFile.open("Day3Input.txt", std::ios::in);
	int LineNum = 0;
	while (std::getline(InFile, Line))
	{
		if (LineNum == Answers[0])
		{
			Results[0] = std::stoi(Line, 0, 2);
		}
		else if (LineNum == Answers[1])
		{
			Results[1] = std::stoi(Line, 0, 2);
		}
		LineNum++;
	}
	InFile.close();

	std::cout << Results[0] * Results[1] << std::endl;


	//22 first common
	//382 least
	
	

}

void Cull(char Test,int i)
{
	std::cout << "test " << Test << std::endl;
	int LineNum = 0;
	InFile.open("Day3Input.txt", std::ios::in);
	while (std::getline(InFile, Line))
	{
		if (std::find(Excludes.begin(), Excludes.end(), LineNum) != Excludes.end()) { }
		else
		{
			if (Line[i] != Test) { Excludes.push_back(LineNum);}
		}
		LineNum++;
	}
	InFile.close();
}


char FindCommon(int i)
{
	Count[0] = 0;
	Count[1] = 0;
	InFile.open("Day3Input.txt", std::ios::in);
	while (std::getline(InFile, Line))
	{
		if (Line[i] == '0') { Count[0]++; }
		else { Count[1]++; }
	}
	InFile.close();

	if (Count[0] > Count[1]) { return '0'; }
	else { return '1'; }
	
}

char FindCommon2(int i)
{
	Count[0] = 0;
	Count[1] = 0;
	InFile.open("Day3Input.txt", std::ios::in);
	while (std::getline(InFile, Line))
	{
		if (Line[i] == '0') { Count[0]++; }
		else { Count[1]++; }
	}
	InFile.close();

	if (Count[0] > Count[1]) { return '1'; }
	else { return '0'; }

}