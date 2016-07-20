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
		Score score;  //���Ե�÷�

	public:
		void Prepare(Text file);  //׼�����ݵ�

		ID GetID() const { return did; }
		Limit GetTime() const { return time; }
		Limit GetSpace() const { return space; }
		Score GetScore() const { return score; }
	};
}