#pragma once

#include "Type.h"
#include "Data.h"
#include "Code.h"

namespace ACJudge
{
	class Submission
	{
	private:
		ID sid;  //�ύ��
		Array<Data> data;  //�ύ���⣺��
		Code code;  //���ύ�𰸣�����

	public:

		Return Prepare() const;  //׼��ѡ�ִ�����

		const Array<Data>& GetData() const { return data; }
		const Code& GetCode() const { return code; }
		const ID& GetID() const { return sid; }
	};
}