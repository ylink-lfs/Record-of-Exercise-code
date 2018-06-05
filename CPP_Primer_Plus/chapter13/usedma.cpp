#include <iostream>
#include <cstdlib>
#include "dma.h"

int main(void)
{
	using std::cout;
	using std::endl;

	abcDMA* shirt = new baseDMA("Portabelly", 8);
	abcDMA* balloon = new lacksDMA("red", "Blimpo", 4);
	abcDMA* map = new hasDMA("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";
	shirt->View();
	cout << "Displaying lacksDMA object:\n";
	balloon->View();
	cout << "Displaying hasDMA object:\n";
	map->View();
	abcDMA* balloon2 = new lacksDMA(*balloon);
	cout << "Result of lacksDMA copy:\n";
	balloon2->View();
	abcDMA* map2 = new baseDMA();
	*map2 = *map;
	cout << "Result of hasDMA assignment:\n";
	map2->View();
	delete shirt;
	delete balloon;
	delete map;
	delete map2;
	system("pause");
	return 0;
}