#pragma once

#include "Type.h"

namespace ACJudge
{
	class Data
	{
	private:
		ID did;  //����ID
		Limit time;  //ʱ������
		Limit space;  //�ռ�����
		Score score;  //���Ե�÷�

	public:
		void Prepare();  //׼�����ݵ�
		Data(ID d, Limit t, Limit s, Score sc);

		ID GetID() const { return did; }
		Limit GetTime() const { return time; }
		Limit GetSpace() const { return space; }
		Score GetScore() const { return score; }
	};
}