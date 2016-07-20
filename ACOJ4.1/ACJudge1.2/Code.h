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
		Return Compile(Text file) const;  //БрвыетЗнДњТы
	};
}