//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unt_ajustegamma.h"
#include "../include/FuncoesTGI.h"
#include "unt_imagem.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndGamma *WndGamma;
//---------------------------------------------------------------------------
__fastcall TWndGamma::TWndGamma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndGamma::TrckGammaChange(TObject *Sender)
{
double valor;

//WndGamma->Caption = "Ajuste do Gamma "+IntToStr((TrckGamma->Position/100));

valor = (TrckGamma->Position * 0.01);

Posicao->Caption = FloatToStr(valor);
Application->ProcessMessages();

gammabrighten(valor,
               &WndImagem->FigBckup,
               &WndImagem->Figura);

//WndImagem->ImgFigura->Refresh();
WndImagem->ImgTrab->Invalidate();

//ConfirmarAtualizacao();
WndImagem->AtualizarHistograma();
}
//---------------------------------------------------------------------------
void __fastcall TWndGamma::FormShow(TObject *Sender)
{
TrckGamma->Position = 100;
Posicao->Caption = IntToStr((long)(TrckGamma->Position * 0.01));
Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall TWndGamma::BtnCancelarClick(TObject *Sender)
{
WndGamma->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndGamma::BtnAjustarClick(TObject *Sender)
{
backup(&WndImagem->Figura,&WndImagem->FigBckup);
WndGamma->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndGamma::FormClose(TObject *Sender, TCloseAction &Action)
{
backup(&WndImagem->FigBckup,&WndImagem->Figura);
//WndImagem->ImgFigura->Refresh();
WndImagem->ImgTrab->Invalidate();
WndGamma->Close();
}
//---------------------------------------------------------------------------
