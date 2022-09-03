#include "Champion.hpp"

int	main()
{
	Champion	zac("zac", Status(2000, 1000));
	Champion	cain("cain", Status(1500, 1100));

	// event
	zac.LevelUp(Status(3000, 1500));
	cain.LevelUp(Status(2000, 1500));
	std::cout << zac << std::endl;
	std::cout << cain << std::endl;

	return (0);
}