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
#else
	typedef std::string Text;
#endif
}