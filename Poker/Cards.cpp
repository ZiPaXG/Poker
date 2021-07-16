#include "Cards.h"
#include <string>

string Cards::getCards()
{
	string s;
	switch (name)
	{
	case 2:
		s = to_string(name);
		break;
	case 3:
		s = to_string(name);
		break;
	case 4:
		s = to_string(name);
		break;
	case 5:
		s = to_string(name);
		break;
	case 6:
		s = to_string(name);
		break;
	case 7:
		s = to_string(name);
		break;
	case 8:
		s = to_string(name);
		break;
	case 9:
		s = to_string(name);
		break;
	case 10:
		s = to_string(name);
		break;
	case 11:
		s = "Валет";
		break;
	case 12:
		s = "Дама";
		break;
	case 13:
		s = "Король";
		break;
	case 14:
		s = "Туз";
		break;
	}
	s += " ";

	switch (suits)
	{
	case 0:
		s += "Буби";
		break;
	case 1:
		s += "Пики";
		break;
	case 2:
		s += "Крести";
		break;
	case 3:
		s += "Черви";
		break;
	}

	return s;
}

int Cards::getName()
{
	return name;
}

int Cards::getSuits()
{
	return suits;
}
