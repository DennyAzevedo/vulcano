//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EscoPalhe.h"
#include "unt_imagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEscoPalhe *frmEscoPalhe;
//---------------------------------------------------------------------------
__fastcall TfrmEscoPalhe::TfrmEscoPalhe(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmEscoPalhe::PonChange(TObject *Sender)
{
  if(Ver1->Checked)
  {
    Quadro1->Brush->Color=Barra->Canvas->Pixels[0][Pon->Position];
    lblQuadro1->Caption=IntToStr(Pon->Position);
    WndImagem->ValPad=Pon->Position;
  }
  if(Ver2->Checked)
  {
    Quadro2->Brush->Color=Barra->Canvas->Pixels[0][Pon->Position];
    lblQuadro2->Caption=IntToStr(Pon->Position);
    WndImagem->ValNull=Pon->Position;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmEscoPalhe::FormShow(TObject *Sender)
{
  Quadro1->Brush->Color=WndImagem->NCor[WndImagem->ValPad];
  lblQuadro1->Caption=IntToStr(WndImagem->ValPad);
  Quadro2->Brush->Color=WndImagem->NCor[WndImagem->ValNull];
  lblQuadro2->Caption=IntToStr(WndImagem->ValNull);
}
//---------------------------------------------------------------------------
void __fastcall TfrmEscoPalhe::FormPaint(TObject *Sender)
{
  int c,l;

  for(l=0;l<256;l++)
    for(c=0;c<15;c++)
       Barra->Canvas->Pixels[c][l]=WndImagem->NCor[l];  
}
//---------------------------------------------------------------------------
void __fastcall TfrmEscoPalhe::SairClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

