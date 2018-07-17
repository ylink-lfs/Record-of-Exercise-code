#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

using namespace std;

class grand
{
private:
	int hold;
public:
	grand(int h = 0) : hold(h) {}
	virtual void speak() const { cout << "I am a grand class\n"; }
	virtual int value() const { return hold; }
};

class superb : public grand
{
public:
	superb(int h = 0) : grand(h) {}
	void speak() const override { cout << "I am a superb class\n"; }
	virtual void say() const { cout << "I hold the superb value of " << value() << std::endl; }
};

class magnificent : public superb
{
private:
	char ch;
public:
	magnificent(int h = 0, char c = 'A') : superb(h), ch(c) {}
	void speak() const override { cout << "I am a magnificent class\n"; }
	void say() const override { cout << "I hold the character " << ch << 
		" and the integer " << value() << std::endl; }
};

grand* getone();

int main(void)
{
	std::srand(std::time(nullptr));
	grand* pg;
	superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = getone();
		cout << "Now processing type " << typeid(*pg).name() << " and raw name is " << typeid(*pg).raw_name()
			<< " and hash code is " << typeid(*pg).hash_code() << ".\n";
		pg->speak();
		if (ps = dynamic_cast<superb*>(pg))
			ps->say();
		if (typeid(magnificent) == typeid(*pg))
			cout << "Yes, you're really magnificent.\n";
	}
	system("pause");
	return 0;
}

grand* getone()
{
	grand* p;
	switch (std::rand() % 3)
	{
	case 0:
		p = new grand(std::rand() % 100);
		break;
	case 1:
		p = new superb(std::rand() % 100);
		break;
	default:
		p = new magnificent(std::rand() % 100, 'A' + std::rand() % 26);
	}
	return p;
}