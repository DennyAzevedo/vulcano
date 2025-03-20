//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntModelo.h"
#include "fntDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvDBCtrl"
#pragma link "JvLookup"
#pragma resource "*.dfm"
TfrmModelo *frmModelo;
//---------------------------------------------------------------------------
__fastcall TfrmModelo::TfrmModelo(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
