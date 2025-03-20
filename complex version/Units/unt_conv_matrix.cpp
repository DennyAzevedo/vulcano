//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unt_conv_matrix.h"
#include "unt_imagem.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndMatrix *WndMatrix;
//---------------------------------------------------------------------------
__fastcall TWndMatrix::TWndMatrix(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TWndMatrix::mtrx1KeyPress(TObject *Sender, char &Key)
{

if ( ( Key >= '0' ) && ( Key <= '9' ) )
    {
//    item->Text += Key;
    }
else if ( Key == '\b' ) ;
else if ( Key == '-' )  ;
else Key = NULL;

}
//---------------------------------------------------------------------------
void __fastcall TWndMatrix::FormShow(TObject *Sender)
{
int i;
for(i=0;i<10;i++)
  {
  matrix[i]->Text = IntToStr(WndImagem->Kern[i]);
  }

}
//---------------------------------------------------------------------------

void __fastcall TWndMatrix::FormCreate(TObject *Sender)
{
matrix[0] = mtrx1;
matrix[1] = mtrx2;
matrix[2] = mtrx3;
matrix[3] = mtrx4;
matrix[4] = mtrx5;
matrix[5] = mtrx6;
matrix[6] = mtrx7;
matrix[7] = mtrx8;
matrix[8] = mtrx9;
matrix[9] = mtrx10;
}
//---------------------------------------------------------------------------

void __fastcall TWndMatrix::BtnOKClick(TObject *Sender)
{
int aux, i;
char *K;

for(i=0;i<10;i++)
  {
  if (matrix[i]->Text == NULL) matrix[i]->Text = '0';
  aux = StrToInt(matrix[i]->Text);
  WndImagem->Kern[i] = aux;
  }

K = WndImagem->Kern;

matrixconv(K, &WndImagem->Figura, &WndImagem->Figura);

WndMatrix->Close();
}
//---------------------------------------------------------------------------

