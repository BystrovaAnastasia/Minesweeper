//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

int Field[12][12] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int Bombs[12][12] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int Mines;
int Opened;
int i;
int j;
int FreeCell;
TPicture *MyCell;
TPicture *MyEmptyCell;
TPicture *MyBomb;
TPicture *My1;
TPicture *My2;
TPicture *My3;
TPicture *My4;
TPicture *My5;
TPicture *My6;
TPicture *My7;
TPicture *My8;
TPicture *MyBombBad;
TPicture *MyFlag;

void clearCells(int i, int j)
{
	if (i < 0 || j < 0 || i > 11 || j > 11) return;
	if (Bombs[i][j] == 2 && Field[i][j] == 0 ) {
		Field[i][j] = Bombs[i][j];
		Opened++;
		clearCells(i+1, j+1);
		clearCells(i+1, j);
		clearCells(i+1, j-1);
		clearCells(i-1, j+1);
		clearCells(i-1, j);
		clearCells(i-1, j-1);
		clearCells(i, j+1);
		clearCells(i, j-1);
	}
}

void NewGame (){
	int k;
	int m;
	randomize();
	Mines = 0;
	//GameOver = false;

    //?????? ??? ???
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			if (random(8)==0) {
				Bombs[i][j] = 1; //????? ????
				Mines = Mines + 1; //??????? ????
			}
			else {
				Bombs[i][j] = 2; //????? ???
			}
		}
	}
	FreeCell = 144 - Mines;
	//??????? ???? ?????? ??????
	for (i = 0; i < 12; i++) {
		 for (j = 0; j < 12; j++) {
			if (j==0) { //?????????? ??? ??????? ???????
				if (i==0) {
					if (Bombs[i][j]==1) { //???? ? ?????? ???? ?????
						for (k = i; k < i+2; k++) {
							for (m = j; m < j+2; m++) {
								if (Bombs[k][m]!=1) { //?? ?????? ?????? ? ?????? ? ????????, ??? ???? ?? ???????? ?????? ????? ????????? ??????
									Bombs[k][m]++; //???? ??????? ?????? ????? +1
								};
							};
						};
					};
				}
				else if (i==11) {
						if (Bombs[i][j]==1) {
							for (k = i-1; k < i+1; k++) {
								for (m = j; m < j+2; m++) {
									if (Bombs[k][m]!=1) {
										Bombs[k][m]++;
									};
								};
							};
						};
					 }
					 else {
						if (Bombs[i][j]==1) {
							for (k = i-1; k < i+2; k++) {
								for (m = j; m < j+2; m++) {
									if (Bombs[k][m]!=1) {
										Bombs[k][m]++;
									};
								};
							};
						};
					 }
			}
			else if (j==11) { //?????????? ??? ?????????? ???????
				if (i==0) {
					if (Bombs[i][j]==1) {
						for (k = i; k < i+2; k++) {
							for (m = j-1; m < j+1; m++) {
								if (Bombs[k][m]!=1) {
									Bombs[k][m]++;
								};
							};
						};
					};
				}
				else if (i==11) {
						if (Bombs[i][j]==1) {
							for (k = i-1; k < i+1; k++) {
								for (m = j-1; m < j+1; m++) {
									if (Bombs[k][m]!=1) {
										Bombs[k][m]++;
									};
								};
							};
						};
					 }
					 else {
						if (Bombs[i][j]==1) {
							for (k = i-1; k < i+2; k++) {
								for (m = j-1; m < j+1; m++) {
									if (Bombs[k][m]!=1) {
										Bombs[k][m]++;
									};
								};
							};
						};
					 }
			}
				else{ //??????????? ??????
					if (Bombs[i][j]==1) {
						for (k = i-1; k < i+2; k++) {
							for (m = j-1; m < j+2; m++) {
								if (Bombs[k][m]!=1) {
									Bombs[k][m]++;
								};
							};
						};
					};
				};
		 };
	};
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			Field[i][j] = 0;
		}
	}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	NewGame();
	MyCell = new TPicture;
	MyEmptyCell = new TPicture;
	MyBomb = new TPicture;
	My1 = new TPicture;
	My2 = new TPicture;
	My3 = new TPicture;
	My4 = new TPicture;
	My5 = new TPicture;
	My6 = new TPicture;
	My7 = new TPicture;
	My8 = new TPicture;
	MyBombBad = new TPicture;
	MyFlag = new TPicture;
	MyCell->LoadFromFile("mycell.png");
	MyEmptyCell->LoadFromFile("myemptycell.png");
	MyBomb->LoadFromFile("mybomb.png");
	My1->LoadFromFile("my1.png");
	My2->LoadFromFile("my2.png");
	My3->LoadFromFile("my3.png");
	My4->LoadFromFile("my4.png");
	My5->LoadFromFile("my5.png");
	My6->LoadFromFile("my6.png");
	My7->LoadFromFile("my7.png");
	My8->LoadFromFile("my8.png");
	MyBombBad->LoadFromFile("mybombbad.png");
	MyFlag->LoadFromFile("myflag.png");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
    DrawGrid1->ColCount =12;
	DrawGrid1->RowCount =12;
	DrawGrid1->DefaultColWidth = DrawGrid1->ClientWidth / DrawGrid1->ColCount -1;    //?????? ?? ????
	DrawGrid1->DefaultRowHeight = DrawGrid1->ClientHeight / DrawGrid1->RowCount -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	//??? ??????????
	switch (Field[ARow][ACol]) {
	case 0: //mycell
		DrawGrid1->Canvas->StretchDraw(Rect,MyCell->Graphic);
		break;
	case 1: //mybomb
		DrawGrid1->Canvas->StretchDraw(Rect,MyBomb->Graphic);
		break;
	case 2: //myemptycell
		DrawGrid1->Canvas->StretchDraw(Rect,MyEmptyCell->Graphic);
		break;
	case 3: //my1
		DrawGrid1->Canvas->StretchDraw(Rect,My1->Graphic);
		break;
	case 4: //my2
		DrawGrid1->Canvas->StretchDraw(Rect,My2->Graphic);
		break;
	case 5: //my3
		DrawGrid1->Canvas->StretchDraw(Rect,My3->Graphic);
		break;
	case 6: //my4
		DrawGrid1->Canvas->StretchDraw(Rect,My4->Graphic);
		break;
	case 7: //my5
		DrawGrid1->Canvas->StretchDraw(Rect,My5->Graphic);
		break;
	case 8: //my6
		DrawGrid1->Canvas->StretchDraw(Rect,My6->Graphic);
		break;
	case 9: //my7
		DrawGrid1->Canvas->StretchDraw(Rect,My7->Graphic);
		break;
	case 10: //my8
		DrawGrid1->Canvas->StretchDraw(Rect,My8->Graphic);
		break;
	case 11: //mybombbad
		DrawGrid1->Canvas->StretchDraw(Rect,MyBombBad->Graphic);
		break;
	case 12: //myflag
		DrawGrid1->Canvas->StretchDraw(Rect,MyFlag->Graphic);
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
	if (Field[ARow][ACol] == 12) return;
	switch (Bombs[ARow][ACol]) {
	case 1: //???? ?????
		Field[ARow][ACol] = 11;
		Bombs[ARow][ACol] = 11;
		//ShowMessage("????? ????! ?? ?????????!");
		Form4->Show();
		//Close();
		break;
	case 2: //???? ?????? ??????
		clearCells(ARow, ACol);
		DrawGrid1->Repaint();
		if (Opened == FreeCell) {
			//ShowMessage("?? ????????!");
			Form5->Show();
			//Close();
		};
		break;
	case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: //???? ?????
		Field[ARow][ACol] = Bombs[ARow][ACol];
		Opened++;
		if (Opened == FreeCell) {
			//ShowMessage("?? ????????!");
			 Form5->Show();
			//Close();
		};
		break;
	case 11:  //???? ????
		Field[ARow][ACol] = 12;
		DrawGrid1->Repaint(); //??????????
		break;
	};

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	//????? ????
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			Field[i][j] = 0;
			Bombs[i][j] = 0;
		}
	}
	NewGame();
	DrawGrid1->Repaint(); //??????????
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	//?????????? ?????? ?? ??????
	delete MyCell;
	delete MyEmptyCell;
	delete MyBomb;
	delete My1;
	delete My2;
	delete My3;
	delete My4;
	delete My5;
	delete My6;
	delete My7;
	delete My8;
	delete MyBombBad;
	delete MyFlag;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
    Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	int CellX, CellY;
	if (Button == mbRight) {
		CellX = X/ DrawGrid1->DefaultColWidth;
		CellY = Y/ DrawGrid1->DefaultRowHeight;
		if (Field[CellY][CellX] != 0 && Field[CellY][CellX] != 12) return;
		Field[CellY][CellX] = Field[CellY][CellX] == 12  ?  0 : 12;
		DrawGrid1->Repaint();
	}

}
//---------------------------------------------------------------------------

