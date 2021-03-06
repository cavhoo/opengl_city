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

float RandomGenerator::getFloatFromRange(float min, float max)
{
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(this->m_generator);
}


Color3f RandomGenerator::getRandomColor(void)
{
	float red = this->getFloatFromRange(0.1, 1.0);
	float green = this->getFloatFromRange(0.1, 1.0);
	float blue = this->getFloatFromRange(0.1, 1.0);

	return { red, green, blue };
}
