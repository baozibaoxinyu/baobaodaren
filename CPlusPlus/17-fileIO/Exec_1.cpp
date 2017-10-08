//filename:Exec_1.cpp
//Writing primes to a file
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
typedef unsigned long long ulong;
int main()
{
	size_t max{};
	std::cout << "How many primes would you like(at least 4)? : ";
	std::cin >> max;
	if (max < 4) max = 4;

	std::vector<ulong> primes{ 2ULL,3ULL,5ULL };
	ulong trial{ 5ULL };
	bool isPrime = false;
	ulong limit{};
	while (primes.size() < max) {
		trial += 2;
		limit = static_cast<ulong>(std::sqrt(trial));
		for (auto prime : primes) {
			if (prime > limit) break;
			isPrime = trial%prime > 0;
			if (!isPrime) break;
		}
		if (isPrime)
			primes.push_back(trial);
	}
	std::string filename{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\primes.txt" };
	std::ofstream outFile{ filename };
	if (!outFile.fail()) {
		size_t perline{ 5 };
		size_t count{};
		for (auto prime : primes) {
			outFile << std::setw(10) << prime;
			if (++count%perline == 0) {
				outFile << std::endl;
			}
			
		}
		outFile << std::endl;
		outFile.close();
		std::cout << max << " primes written to " << filename << std::endl;
	}
	else {
		std::cout << "Fail to write file." << std::endl;
	}

	return 0;
}
