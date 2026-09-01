#include <iostream>
#include <string>
#include <cassert>
#include <ctime> 

int int_rand(int x, int y)
{
	return (((rand())%(y-x))+x);
}

using namespace std;

class classhero
{
	int strength = 0;
	int courage = 0;
	string name = "";

	public: classhero(string n)
	{
		name = n;
		strength = int_rand(1, 10);
		courage = int_rand(5, 10);
		cout << name << " has " << strength << " strength and " << courage << " courage." << endl;
	}

	public: void getStronger(int t)
	{
		strength += t;
	}

	public: void getATherapist()
	{
		courage += int_rand(5, 10);
		cout << name << " got therapy! new courage: " << courage << endl;
	}
	
	public: int getStrength()
	{
		return strength;
	}

	public: string getName()
	{
		return name;
	}

	public: void setCourage(int k)
	{
		courage = k;
	}

	public: int getCourage()
	{
		return courage;
	}
};

void sendHeroOnQuest(classhero& h)
{
	if (h.getStrength() - 10 < int_rand(0, h.getStrength()+1))
	{
		int rand = int_rand(0, 50);
		int newc = h.getCourage() - rand;
		h.setCourage(newc);
		cout << h.getName() << " failure! new courage: " << h.getCourage() << endl;
		cout << rand << ", " << newc << endl;
	}
	else if (h.getStrength()/2 - 10 < int_rand(0, h.getStrength()+1))
	{
		int rand = int_rand(0, 25);
		int newc = h.getCourage() - rand;
		h.setCourage(newc);
		cout << h.getName() << " survival! new courage: " << h.getCourage() << endl;
		cout << rand << ", " << newc << endl;
	}
	else
	{
		int rand = int_rand(0, 12);
		int newc = h.getCourage() + rand;
		h.setCourage(newc);
		cout << h.getName() << " success! new courage: " << h.getCourage() << endl;
		cout << rand << ", " << newc << endl;
	}
}

int main()
{
	srand(time(0));
	classhero burger = classhero("burger");
	classhero bingle = classhero("bingle");
	classhero floppa = classhero("floppa");
	classhero dubious = classhero("incredibly dubious individual");
	burger.getATherapist();
	bingle.getATherapist();
	floppa.getStronger(20);
	dubious.getStronger(100);
	for (int i = 0; i < 20; i++)
	{
		sendHeroOnQuest(burger);
		sendHeroOnQuest(bingle);
		sendHeroOnQuest(floppa);
		sendHeroOnQuest(dubious);
	}
}