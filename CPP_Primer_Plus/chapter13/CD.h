#pragma once

class CD
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	CD(const char* s1, const char* s2, int n, double x);
	CD();
	virtual ~CD();
	CD(const CD& d);
	CD& operator=(const CD& d);

	virtual void Report() const;  //output all CD data
};
