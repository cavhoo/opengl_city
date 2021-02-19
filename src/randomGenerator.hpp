#ifndef __RANDOMGENERATOR_H_
#define __RANDOMGENERATOR_H_

#include <random>
class RandomGenerator {
	private:
		std::mt19937 m_generator;
		static RandomGenerator* instance;
		RandomGenerator();
	public:
		static RandomGenerator* getInstance();
		int getIntFromRange(int min, int max);
};
#endif // __RANDOMGENERATOR_H_
