#pragma once

#include "Type.h"

namespace ACJudge
{
	class Code
	{
	private:
		Text code;
		Language language;

	public:
		Return Compile(Text file) const;  //±‡“Î’‚∑›¥˙¬Î
		Return Run(Text name, int &val, Limit time = -1, Limit space = -1, Text error = _T("err"), Text input = _T(""), Text output = _T("")) const;

		Code(Text c, Language l) : code(c), language(l) {}
		Code() {}
	};
}