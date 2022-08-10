#include "../include/RandomGenerator.h"

namespace random
{
	int randomIntInRange(int min, int max)
	{
		std::random_device randomSeed; // obtain a random number from hardware
		std::mt19937 randomGenerator(randomSeed()); // seed the generator
		std::uniform_int_distribution<> distr(min, max);
		
		
		return distr(randomGenerator);
	}
}