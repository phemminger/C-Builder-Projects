//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ClickCount = 0;
	std::vector<int> A (8);
	std::vector<int> B (8);
	std::vector<int> C (8);
	std::vector<int> D (18);
	std::vector<int> E (8);
	std::vector<int> F (0);

	A[0] = -1;
	A[1] =  3;
	A[2] = -4;
	A[3] =  5;
	A[4] =  1;
	A[5] = -6;
	A[6] =  2;
	A[7] =  1;

	B[0] = 0;
	B[1] =  0;
	B[2] = 0;
	B[3] =  0;
	B[4] =  0;
	B[5] = 0;
	B[6] =  0;
	B[7] =  0;

	C[0] = 0;
	C[1] =  0;
	C[2] = 1;
	C[3] =  1;
	C[4] =  0;
	C[5] = 0;
	C[6] =  -1;
	C[7] =  -1;

	D[0] =  1;
	D[1] =  1;
	D[2] = 1;
	D[3] = 0;
	D[4] =  0;
	D[5] = 0;
	D[6] =  -1;
	D[7] =  -1;
	D[8] =  -1;
	D[9] =  1;
	D[10] =  1;
	D[11] =  1;
	D[12] = 0;
	D[13] = 0;
	D[14] =  0;
	D[15] = -1;
	D[16] =  -1;
	D[17] =  -1;

	E[0] = 0;
	E[1] =  0;
	E[2] = 1;
	E[3] =  1;
	E[4] =  -1;
	E[5] = -1;
	E[6] =  1;
	E[7] = 1;

    Label1->Text = UnicodeString(2 % 4);

//	solution(A, Label1);
//	solution(B, Label2);
//	solution(C, Label3);
//	solution(D, Label4);
//	solution(E, Label5);
//	solution(F, Label6);

}
//---------------------------------------------------------------------------

int TForm1::solution(std::vector<int> &A, TLabel *Label) {
	int Size, Index, EquibIndex, i, Jump;
	long SumPre, SumPost, FullSum;
	Size = A.size();
	if(Size == 0)
		return -1;
	EquibIndex = -2;

	FullSum = 0, SumPre = 0, SumPost = 0;
	for(i = 0; i < Size; ++i)
		FullSum += A[i];
	for(i = 0; i < Size; ++i) {
		SumPost = FullSum - SumPre - A[i];
		if(SumPre == SumPost) {
			EquibIndex = i;
			break;
		}
		SumPre += A[i];
	}


	UnicodeString S = "";

	for(int i = 0; i < A.size(); ++i)
		S += IntToStr(A[i]) + ", ";
	S += "\n";
	S += "EquibIndex = " + IntToStr(EquibIndex);
	Label->Text = S;

	return EquibIndex;
}
