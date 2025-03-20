//---------------------------------------------------------------------------
#include "fntCaptura.h"
#include <vcl.h>
#pragma hdrstop

#include "fntsplash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
__fastcall TfrmSplash::TfrmSplash(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmSplash::FormShow(TObject *Sender)
{
TmrSplash->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSplash::TmrSplashTimer(TObject *Sender)
{
frmCaptura->Show();
TmrSplash->Enabled = false;
frmSplash->Hide();
}
//---------------------------------------------------------------------------
