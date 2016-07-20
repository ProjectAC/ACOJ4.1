#pragma once

#include "Type.h"

namespace ACJudge
{
	class SandBox
	{
	public:
		Return Run(Text executable, Text input, Text output, Text error);
	};
};