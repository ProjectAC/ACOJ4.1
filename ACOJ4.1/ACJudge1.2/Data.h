#pragma once

#include "Type.h"

namespace ACJudge
{
	class Data
	{
	private:
		ID did;  //����ID
		Text in;  //�����ļ�����
		Text out;  //����ļ�����
		Limit time;  //ʱ������
		Limit space;  //�ռ�����

	public:
		void Init(ID i, Database db);  //�����ݿ��м���
		void Prepare(Text file);  //׼�����ݵ�

		Limit get_time();
		Limit get_space();
	};
}