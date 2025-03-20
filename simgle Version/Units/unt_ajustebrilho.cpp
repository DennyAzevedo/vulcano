//---------------------------------------------------------------------------

#include <vcl.h>
#include "unt_imagem.h"
#include "../include/FuncoesTGI.h"

#pragma hdrstop

#include "unt_ajustebrilho.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWndBrilho *WndBrilho;
//---------------------------------------------------------------------------
__fastcall TWndBrilho::TWndBrilho(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndBrilho::FormShow(TObject *Sender)
{
TrckBrilho->Position = 200;

Posicao->Caption = IntToStr((TrckBrilho->Position - 200));
Application->ProcessMessages();

}
//---------------------------------------------------------------------------
void __fastcall TWndBrilho::BtnCancelarBrilhoClick(TObject *Sender)
{
WndBrilho->Close();    
}
//---------------------------------------------------------------------------
void __fastcall TWndBrilho::FormClose(TObject *Sender,
      TCloseAction &Action)
{
backup(&WndImagem->FigBckup,&WndImagem->Figura);
//WndImagem->ImgFigura->Refresh();
WndImagem->ImgTrab->Invalidate();
WndBrilho->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndBrilho::BtnAjustarBrilhoClick(TObject *Sender)
{
backup(&WndImagem->Figura,&WndImagem->FigBckup);
WndBrilho->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndBrilho::TrckBrilhoChange(TObject *Sender)
{

Posicao->Caption = IntToStr((TrckBrilho->Position - 200));
Application->ProcessMessages();
//WndGamma->Caption = "Ajuste do Gamma "+IntToStr((TrckGamma->Position/100));

//changebright(20,&Figura,&Figura);
changebright(TrckBrilho->Position - 200,
               &WndImagem->FigBckup,
               &WndImagem->Figura);

//WndImagem->ImgFigura->Refresh();
WndImagem->ImgTrab->Invalidate();

//ConfirmarAtualizacao();
WndImagem->AtualizarHistograma();
}
//---------------------------------------------------------------------------
