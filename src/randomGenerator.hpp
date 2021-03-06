#ifndef __RANDOMGENERATOR_H_
#define __RANDOMGENERATOR_H_

#include "structs.hpp"
#include <random>
class RandomGenerator {
	private:
		std::mt19937 m_generator;
		static RandomGenerator* instance;
		RandomGenerator();
	public:
		static RandomGenerator* getInstance();
		int getIntFromRange(int min, int max);
		float getFloatFromRange(float min, float max);
		Color3f getRandomColor(void);
};
#endif // __RANDOMGENERATOR_H_
