//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntPontoFisico.h"
#include "fntImagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "JvComponent"
#pragma link "JvxCtrls"
#pragma resource "*.dfm"
TfrmPontoFisico *frmPontoFisico;
//---------------------------------------------------------------------------
__fastcall TfrmPontoFisico::TfrmPontoFisico(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPontoFisico::btnSairClick(TObject *Sender)
{
  frmImagem->ColunaF = edtColuna->Value;
  frmImagem->LinhaF  = edtLinha->Value ;
  Close();
}
//---------------------------------------------------------------------------
