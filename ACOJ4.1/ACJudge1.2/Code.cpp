#include "Code.h"
#include "SandBox.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace ACJudge;

Return Code::Compile(Text file) const
{
	system((_T("copy ../") + code + _T(" ./box/") + file + _T(".src")).c_str());

	SandBox box;
	int ret;

	switch (language)
	{
	case Language::C:
		return box.Run(_T("gcc ./box/") + file + _T(".src -o ./box/") + file + _T(" -Wall -lm --static -std=c99 -DONLINE_JUDGE"), ret, 10000, -1, _T("err"));
	case Language::CPP:
		return box.Run(_T("g++ ./box/") + file + _T(".src -o ./box/") + file + _T(" -Wall -lm --static -O2 -DONLINE_JUDGE"), ret, 10000, -1, _T("err"));
	case Language::CPP11:
		return box.Run(_T("g++ ./box/") + file + _T(".src -o ./box/") + file + _T(" -Wall -lm --static -O2 -std=c++11 -DONLINE_JUDGE"), ret, 10000, -1, _T("err"));
	}

	return Return::FAIL;
}

Return Code::Run(Text name, int &val, Limit time, Limit space, Text error, Text input, Text output) const
{
	SandBox box;
	switch (language)
	{
	case Language::C:
	case Language::CPP:
	case Language::CPP11:
		return box.Run((_T("./box/") + name), val, time, space, error, input, output);
	}

	return Return::FAIL;
}