#pragma once

#include "Type.h"

namespace ACJudge
{
	class Answer
	{
	private:
		ID did;  //����ID

	public:
		void Prepare();  //׼�����ݵ�
		Answer(ID d);

		ID GetID() const { return did; }
	};
}