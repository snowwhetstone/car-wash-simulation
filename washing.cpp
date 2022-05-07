#include <iostream>
#include <cassert> // Provides assert
#include <cstdlib> // Provides rand, RAND_MAX, size_t
#include "washing.h" // Provides bool_source, averager, washer definitions
using namespace std;
 
bool_source::bool_source(double p)
// Library facilities used: cassert
{
	assert(p >= 0);
	assert(p <= 1);
	probability = p;
}
bool bool_source::query() const
// Library facilities used: cstdlib
{
	return (rand() < probability * RAND_MAX);
}
averager::averager()
{
	count = 0;
	sum = 0;
}
void averager::next_number(double value)
{
	++count;
	sum += value;
}
double averager::average() const
// Library facilities used: cassert
{
	assert(how_many_numbers() > 0);
	return sum / count;
}
washer::washer(unsigned int s)
{
	seconds_for_wash = s;
	wash_time_left = 0;
}
void washer::one_second()
{
	if (is_busy())
		--wash_time_left;
}
void washer::start_washing()
// Library facilities used: cassert 
{
	assert(!is_busy());
	wash_time_left = seconds_for_wash;
}
