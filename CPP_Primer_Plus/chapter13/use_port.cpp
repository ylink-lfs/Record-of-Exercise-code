#include <iostream>
#include <cstdlib>
#include "port.h"
#include "vintage_port.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	port* assemble_pt[10];
	assemble_pt[0] = new port("shit", "fuck", 5);
	assemble_pt[1] = new vintage_port("fly", 25, "The Noble", 55);
	assemble_pt[2] = new port(*assemble_pt[0]);
	assemble_pt[0]->Show();
	assemble_pt[1]->Show();
	assemble_pt[2]->Show();
	cout << *assemble_pt[0] << *assemble_pt[1] << *assemble_pt[2] << endl;

	system("pause");
	return 0;
}