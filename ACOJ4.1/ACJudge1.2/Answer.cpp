#include "Answer.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace ACJudge;

void Answer::Prepare()
{
	TCHAR *s = new TCHAR[1000];
	TCHAR *t = new TCHAR[1000];
	sprintf(s, "%llu", sid);
	sprintf(t, "%llu", did);
	system((_T("copy ../submission/") + Text(s) + _T("/") + Text(t) + _T(".out ./box/sol.out")).c_str());
}