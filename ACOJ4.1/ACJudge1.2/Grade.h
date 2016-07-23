#pragma once

#include "Type.h"

namespace ACJudge
{
	class Grade
	{
	private:
	public:
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
		void SetResult(Result r) { result = r; }
		Result GetResult() { return result; }
		ID GetID() { return sid; }
		void Push(Grade g) { grades.push_back(g); }
		Array<Grade> GetGrade() { return grades; }
	};
}