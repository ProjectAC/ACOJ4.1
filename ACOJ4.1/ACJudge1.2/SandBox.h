#pragma once

#include "Type.h"
#include "Platform.h"

#if defined WINDOWS
	#include <Windows.h>
#endif

namespace ACJudge
{
	class SandBox
	{
#if defined WINDOWS
		JOBOBJECT_EXTENDED_LIMIT_INFORMATION Limits(Limit time, Limit space);
		JOBOBJECT_BASIC_UI_RESTRICTIONS Restrictions();
		STARTUPINFO StartUpInfo(Text input, Text Output, Text error);
#endif

	public:
		Return Run(Text name, int &val, Limit time = -1, Limit space = -1, Text error = _T("err"), Text input = _T(""), Text output = _T(""));  //ÔËÐÐ
	};
};