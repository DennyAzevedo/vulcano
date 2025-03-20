//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmDados *dmDados;
//---------------------------------------------------------------------------
__fastcall TdmDados::TdmDados(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
