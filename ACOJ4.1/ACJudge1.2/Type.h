#pragma once

#include "Language.h"
#include "TaskType.h"
#include "Return.h"
#include "Platform.h"
#include <tchar.h>
#include <vector>
#include <string>

namespace ACJudge
{
	typedef unsigned long long ID;
	typedef unsigned int Limit;
	typedef unsigned int Int;
	typedef unsigned int Score;

	template<class T> using Array = std::vector<T>;

#if defined _UNICODE
	typedef std::wstring Text;
	typedef std::wifstream Input;
	typedef std::wofstream Output;
#else
	typedef std::string Text;
	typedef std::ifstream Input;
	typedef std::ofstream Output;
#endif
}