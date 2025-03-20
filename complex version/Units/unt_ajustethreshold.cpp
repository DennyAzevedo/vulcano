//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unt_imagem.h"
#include "../include/FuncoesTGI.h"

#include "unt_ajustethreshold.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndSegmenta *WndSegmenta;
//---------------------------------------------------------------------------
__fastcall TWndSegmenta::TWndSegmenta(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndSegmenta::FormShow(TObject *Sender)
{
TrckThreshold->Position = 128;
Posicao->Caption = IntToStr(TrckThreshold->Position);
Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TWndSegmenta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//backup(&WndImagem->FigBckup,&WndImagem->Figura);
//WndImagem->ImgFigura->Refresh();
WndImagem->ImgTrab->Invalidate();
WndSegmenta->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndSegmenta::BtnCancelarThresholdClick(TObject *Sender)
{
WndSegmenta->Close();
}
//---------------------------------------------------------------------------

void __fastcall TWndSegmenta::BtnAjustarThresholdClick(TObject *Sender)
{
//backup(&WndImagem->Figura,&WndImagem->FigBckup);
WndSegmenta->Close();
}
//---------------------------------------------------------------------------

void __fastcall TWndSegmenta::TrckThresholdChange(TObject *Sender)
{

Posicao->Caption = IntToStr(TrckThreshold->Position);
Application->ProcessMessages();

//kodalith(TrckThreshold->Position, &WndImagem->FigBckup, &WndImagem->Figura);

//WndImagem->ImgFigura->Refresh();
WndImagem->ImgTrab->Invalidate();

//ConfirmarAtualizacao();
WndImagem->AtualizarHistograma();
}
//---------------------------------------------------------------------------
