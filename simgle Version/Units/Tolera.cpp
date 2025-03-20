//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tolera.h"
#include "unt_imagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTolera *frmTolera;
int ValMax;
//---------------------------------------------------------------------------
__fastcall TfrmTolera::TfrmTolera(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmTolera::BarTolSupChange(TObject *Sender)
{
  WndImagem->PTolSup=BarTolSup->Position;
  if(BarTolSup->Position != StrToInt(edtToSup->Text))
    edtToSup->Text=IntToStr(BarTolSup->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTolera::BarTolInfChange(TObject *Sender)
{
  WndImagem->PTolInf=BarTolInf->Position;
  if(BarTolInf->Position != StrToInt(edtToInf->Text))
    edtToInf->Text=IntToStr(BarTolInf->Position);
}
//---------------------------------------------------------------------------
void __fastcall TfrmTolera::FormShow(TObject *Sender)
{
  BarTolSup->Position=WndImagem->PTolSup;
  BarTolInf->Position=WndImagem->PTolInf;
  if(WndImagem->Perc)
    {
    rbPerc->Checked=true;
    rbPercClick(Sender);
    }
  else
    {
    rbValor->Checked=true;
    rbValorClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmTolera::SairClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::edtToSupChange(TObject *Sender)
{
  if(StrToInt(edtToSup->Text)>ValMax)
    edtToSup->Text=IntToStr(ValMax);
  if(StrToInt(edtToSup->Text)<0)
    edtToSup->Text='0';
  WndImagem->PTolSup=StrToInt(edtToSup->Text);
  if(BarTolSup->Position != StrToInt(edtToSup->Text))
    BarTolSup->Position=StrToInt(edtToSup->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::edtToInfChange(TObject *Sender)
{
  if(StrToInt(edtToInf->Text)>ValMax)
    edtToInf->Text=IntToStr(ValMax);;
  if(StrToInt(edtToInf->Text)<0)
    edtToInf->Text='0';
  WndImagem->PTolInf=StrToInt(edtToInf->Text);
  if(BarTolInf->Position != StrToInt(edtToInf->Text))
    BarTolInf->Position=StrToInt(edtToInf->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::rbValorClick(TObject *Sender)
{
  WndImagem->Perc=false;
  BarTolSup->Max=255;
  BarTolInf->Max=255;
  ValMax=255;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::rbPercClick(TObject *Sender)
{
  WndImagem->Perc=true;
  BarTolSup->Max=100;
  BarTolInf->Max=100;
  ValMax=100;
}
//---------------------------------------------------------------------------

