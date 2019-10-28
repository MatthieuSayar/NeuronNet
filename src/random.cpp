#include "random.h"


RandomNumbers::RandomNumbers(unsigned long int s)
:seed(s)
{
	if (s==0) {
		std::random_device rd;
		seed = rd();
	}
	rng = std::mt19937(seed);
}




void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper){
	std::uniform_real_distribution<double> dis(lower, upper); 
	size_t Size(vec.size());
	for (size_t n=0; n<Size; n++) 
	{
		vec[n]=dis(rng);
	}

}


double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<double> dis(lower, upper);
	return dis(rng);
}


void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd){
	std::normal_distribution<double> dis(mean, sd);
	size_t Size(vec.size());
	for (size_t n=0; n<Size; n++) 
	{
		vec[n]=dis(rng);
	}

}


double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<double> dis(mean, sd);
	return dis(rng);
}


void RandomNumbers::poisson(std::vector<int>& vec, double mean){
	std::poisson_distribution<int> dis(mean);
	size_t Size(vec.size());
	for (size_t n=0; n<Size; n++) 
	{
		vec[n]=dis(rng);
	}
}


int RandomNumbers::poisson(double mean){
	std::poisson_distribution<int> dis(mean);
	return dis(rng);	
}
