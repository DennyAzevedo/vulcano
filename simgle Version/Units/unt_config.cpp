//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unt_config.h"
#include "unt_principal.h"
//#include "../include/funcoestgi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndConfig *WndConfig;
//---------------------------------------------------------------------------
__fastcall TWndConfig::TWndConfig(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndConfig::BtCancelarClick(TObject *Sender)
{
WndConfig->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndConfig::FormCreate(TObject *Sender)
{
ListaBaseSeg->ItemIndex=5;
}
//---------------------------------------------------------------------------
void __fastcall TWndConfig::BtOKClick(TObject *Sender)
{
switch(ListaBaseSeg->ItemIndex)
    {
    case 0:{ WndPrincipal->baseseg = 0xc000; break; }
    case 1:{ WndPrincipal->baseseg = 0xc400; break; }
    case 2:{ WndPrincipal->baseseg = 0xc800; break; }
    case 3:{ WndPrincipal->baseseg = 0xcc00; break; }
    case 4:{ WndPrincipal->baseseg = 0xd000; break; }
    case 5:{ WndPrincipal->baseseg = 0xd400; break; }
    case 6:{ WndPrincipal->baseseg = 0xd800; break; }
    case 7:{ WndPrincipal->baseseg = 0xdc00; break; }
    }
WndConfig->Close();
}
//---------------------------------------------------------------------------
