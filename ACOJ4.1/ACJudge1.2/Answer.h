#pragma once

#include "Type.h"

namespace ACJudge
{
	class Answer
	{
	private:
		ID sid;  //�ύID
		ID did;  //����ID

	public:
		void Prepare();  //׼�����ݵ�

		Answer(ID s, ID d) : sid(s), did(d) {}
		ID GetID() { return did; }
	};
}