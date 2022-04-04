
#include <ctime>
#include "Zoo.h"

int main()
{

	time_t t;
	time(&t);
	srand(t);

	Zoo z;
	z.run();
	
	return 0;
}