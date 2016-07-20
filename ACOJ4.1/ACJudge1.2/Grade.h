#pragma once

#include "Type.h"

namespace ACJudge
{
	class Grade
	{
	private:
		ID sid;  //�ύ��
		ID did;  //���ݺ�
		Score score;  //���
		Result result;  //����������
		Text msg;  //���ش�����Ϣ

	public:
		Grade(Result r, Score s, ID si, ID di)
			:result(r), score(s), sid(si), did(di) {}
	};

	class Grades
	{
		Array<Grade> grades;
		Result result;
		ID sid;

	public:
		void SetResult(Result);
		void Push(Grade);
	};
}