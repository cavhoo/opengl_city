#include "randomGenerator.hpp"
#include <random>

RandomGenerator::RandomGenerator():m_generator((std::random_device())())
{

}

RandomGenerator* RandomGenerator::instance = 0;

RandomGenerator* RandomGenerator::getInstance() {
	if (instance == 0)
	{
		instance = new RandomGenerator();
	}
	return instance;
}

int RandomGenerator::getIntFromRange(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(this->m_generator);
}
