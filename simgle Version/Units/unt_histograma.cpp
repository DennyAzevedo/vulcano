//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unt_histograma.h"
#include "unt_imagem.h"
#include "../include/FuncoesTGI.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndHistograma *WndHistograma;
//---------------------------------------------------------------------------
__fastcall TWndHistograma::TWndHistograma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndHistograma::FormShow(TObject *Sender)
{

ImgHisto->Canvas->FillRect(Rect(0,0,512,253));

CalcDrawHisto(&WndImagem->Figura,ImgHisto->Canvas->Handle,0,-10,256,552);

ImgHisto->Refresh();
}
//---------------------------------------------------------------------------


