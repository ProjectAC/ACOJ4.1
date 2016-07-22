#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace ACJudge;

void Data::Prepare()
{

}

Data::Data(ID d, Limit t, Limit s, Score sc)
{
	did = d;
	time = t;
	space = s;
	score = sc;
}