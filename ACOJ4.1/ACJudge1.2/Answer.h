#pragma once

#include "Type.h"

namespace ACJudge
{
	class Answer
	{
	private:
		ID did;  //数据ID

	public:
		void Prepare();  //准备数据点
		Answer(ID d);

		ID GetID() const { return did; }
	};
}