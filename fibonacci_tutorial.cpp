#include <iostream>
#include <regex>

int fibbonacci(int n)
{
	if(n < 0)
		return -1;

	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	return fibbonacci(n - 1) + fibbonacci(n - 2);
}

int main(int argc, char** argv)
{
	int n = 0;
	bool bIterate = false;

	if(argc > 1)
	{
		std::string curr_arg = argv[1];
		if(std::regex_match(curr_arg, std::regex("[0-9]+")))
			n = std::atoi(argv[1]);
		else
			return 1;

		if(argc > 2)
		{
			if(std::regex_match(std::string(argv[2]), std::regex("[a-z0-9]*")))
			{
				bool bArg = (!strcmp(argv[2], "true") || !strcmp(argv[2], "1"));
				bIterate = (bArg) ? true : false;
			}
		}
	}
	else
	{
		std::cout << "Enter N: ";
		std::cin >> n;
	}

	if(n < 0)
	{
		std::cout << "Invalid Value N" << std::endl;
		return 0;
	}
	
	for(int i = 0; i < n && bIterate; ++i)
		std::cout << fibbonacci(i) << ' ';

	if(!bIterate)
		std::cout << fibbonacci(n) << std::endl;

	std::cout << std::endl;
	return 0;
}
