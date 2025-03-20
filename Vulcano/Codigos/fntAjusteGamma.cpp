/*******************************************************************************
*                                                                              *
*   Autores:  Walter da Silva Porto Neto                                       *
*             Alexandre Monteiro de Oliveira                                   *
*             Paulo Rog�rio da C Santos                                        *
*                                                                              *
*   T�tulo TGI: Aplicativo para Aquisi��o e Tratamento de Imagens              *
*                                                                              *
*   Orientadores: Francisco Carlos Parquet Bizarria                            *
*                 Jos� Walter Parquet Bizarria                                 *
*                                                                              *
*   Modificado por: Denny Paulista Azevedo Filho                               *
*                                                                              *
*   Tese de Mestrado - Engenharia Mec�nica (Automa��o Industrial)              *
*                                                                              *
*   T�tulo: T�cnicas de Vizinhan�a Aplicadas a Valida��o Funcional de          *
*           Matriz de Cristal L�quido                                          *
*                                                                              *
*   Orientador: Francisco Carlos Parquet Bizarria                              *
*                                                                              *
*   Colaborador: Jos� Walter Parquet Bizarria                                  *
*                                                                              *
*   Criado em : ??/??/2003                                                     *
*   Modificado em : 20/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Ajustar o Gamma da Imagem (Contraste)                         *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntAjusteGamma.h"
#include "../include/Funcoes.h"
#include "fntImagem.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGamma *frmGamma;
//---------------------------------------------------------------------------
__fastcall TfrmGamma::TfrmGamma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmGamma::FormShow(TObject *Sender)
{
  TrckGamma->Position = 100;
  Posicao->Caption = IntToStr((long)(TrckGamma->Position * 0.01));
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGamma::FormClose(TObject *Sender, TCloseAction &Action)
{
  backup(&frmImagem->FigBak,&frmImagem->Figura);
  frmImagem->ImgTrab->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGamma::TrckGammaChange(TObject *Sender)
{
  double valor;

  valor = (TrckGamma->Position * 0.01);
  Posicao->Caption = FloatToStr(valor);
  Application->ProcessMessages();
  gammabrighten(valor,&frmImagem->FigBak,&frmImagem->Figura);
  frmImagem->ImgTrab->Invalidate();
  frmImagem->AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGamma::BtnCancelarClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGamma::BtnAjustarClick(TObject *Sender)
{
  backup(&frmImagem->Figura,&frmImagem->FigBak);
  Close();
}
//---------------------------------------------------------------------------


