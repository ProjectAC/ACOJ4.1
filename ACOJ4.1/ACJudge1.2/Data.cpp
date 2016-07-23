#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace ACJudge;

void Data::Prepare()
{
	TCHAR *s = new TCHAR[1000];
	sprintf(s, "%llu", did);
	system((_T("copy ../data/") + Text(s) + _T("/*.* ./box/")).c_str());
}

Data::Data(ID d, Limit t, Limit s, Score sc)
{
	did = d;
	time = t;
	space = s;
	score = sc;
}