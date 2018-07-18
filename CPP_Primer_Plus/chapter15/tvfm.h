#include <iostream>
using std::cout;
using std::endl;

#ifndef TVFM_H_
#define TVFM_H_

class Tv;                       // forward declaration

class Remote
{
public:
	friend class Tv;
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	enum Interactive{ Normal, Interact };
private:
	int mode;
	int interact;
public:
	Remote(int m = TV, int ition = Normal) : mode(m) , interact(ition) {}
	bool volup(Tv & t);         // prototype only
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t, int c);
	void show_tv_status(Tv& t) const;
};

class Tv
{
public:
	friend class Remote;
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void get_involved(Remote& r);
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

// Remote methods as inline functions
inline bool Remote::volup(Tv & t) { return t.volup(); }
inline bool Remote::voldown(Tv & t) { return t.voldown(); }
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) { t.chanup(); }
inline void Remote::chandown(Tv & t) { t.chandown(); }
inline void Remote::set_mode(Tv & t) { t.set_mode(); }
inline void Remote::set_input(Tv & t) { t.set_input(); }
inline void Remote::set_chan(Tv & t, int c) { t.channel = c; }
inline void Remote::show_tv_status(Tv& t) const
{
	cout << "State: " << (t.state == 0 ? "Off" : "On") << endl;
	cout << "Vol: " << t.volume << endl;
	cout << "Max Channel: " << t.maxchannel << endl;
	cout << "Current Channel: " << t.channel << endl;
	cout << "Mode: " << (t.mode == Antenna ? "Antenna" : "Cable") << endl;
	cout << "Input: " << (t.input == DVD ? "DVD" : "TV") << endl;
	cout << "Remote Interaction: " << (interact == Normal ? "Normal" : "Interactive") << endl;
}
#endif
