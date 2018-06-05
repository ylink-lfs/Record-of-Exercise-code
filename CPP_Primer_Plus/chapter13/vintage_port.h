#pragma once
#include "port.h"

class vintage_port : public port
{
private:
	char* nickname;
	int year;
public:
	vintage_port();
	vintage_port(const char* br, int b, const char* nn, int y);
	vintage_port(const vintage_port& vp);
	~vintage_port() { delete[]nickname; }
	vintage_port& operator=(const vintage_port& vp);
	void Show() const;
	friend std::ostream& operator<<(std::ostream& os, const vintage_port& vp);
};