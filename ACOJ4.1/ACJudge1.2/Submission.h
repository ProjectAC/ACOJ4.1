#pragma once

#include "Type.h"
#include "Data.h"
#include "Answer.h"
#include "Code.h"

namespace ACJudge
{
	class Submission
	{
	private:
		ID sid;  //�ύ��
		ID tid;  //��Ŀ��
		Array<Answer> data;  //�ύ���⣺��
		Code code;  //���ύ�𰸣�����

	public:

		Return Prepare() const;  //׼��ѡ�ִ�����

		const Array<Answer>& GetData() const { return data; }
		const Code& GetCode() const { return code; }
		const ID& GetID() const { return sid; }
	};
}