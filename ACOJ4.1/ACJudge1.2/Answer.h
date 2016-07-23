#pragma once

#include "Type.h"

namespace ACJudge
{
	class Answer
	{
	private:
		ID sid;  //提交ID
		ID did;  //数据ID

	public:
		void Prepare();  //准备数据点

		Answer(ID s, ID d) : sid(s), did(d) {}
		ID GetID() { return did; }
	};
}