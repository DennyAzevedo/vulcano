//---------------------------------------------------------------------------
#include "unt_principal.h"
#include <vcl.h>
#pragma hdrstop

#include "unt_splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndSplash *WndSplash;
//---------------------------------------------------------------------------
__fastcall TWndSplash::TWndSplash(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndSplash::FormShow(TObject *Sender)
{
TmrSplash->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TWndSplash::TmrSplashTimer(TObject *Sender)
{
WndPrincipal->Show();
TmrSplash->Enabled = false;
WndSplash->Hide();
}
//---------------------------------------------------------------------------
