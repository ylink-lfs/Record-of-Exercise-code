#include <iostream>
#include <cstdlib>
#include <cstring>
#include <new>

struct chaff
{
	char dross[20];
	int slag;
};

char buffer[100];

int main(void)
{
	using std::cout;
	using std::endl;
	chaff* pt = new(buffer) chaff[2];
	strcpy(pt[0].dross, "test1");
	strcpy(pt[1].dross, "fuck2");
	pt[0].slag = 3;
	pt[1].slag = 5;
	for (int i = 0; i < 2; i++)
	{
		cout << pt[i].dross << '\t' << pt[i].slag << endl;
	}
	system("pause");
	return 0;
}
