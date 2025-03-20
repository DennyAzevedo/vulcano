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
*   Finalidade : Determina Valor do ThresHold para Binariza��o da Imagem       *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntImagem.h"
#include "../include/Funcoes.h"

#include "fntAjusteThreshold.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSegmenta *frmSegmenta;
//---------------------------------------------------------------------------
__fastcall TfrmSegmenta::TfrmSegmenta(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmSegmenta::FormShow(TObject *Sender)
{
  TrckThreshold->Position = 128;
  Posicao->Caption = IntToStr(TrckThreshold->Position);
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSegmenta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  backup(&frmImagem->FigBak,&frmImagem->Figura);
  frmImagem->ImgTrab->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSegmenta::BtnCancelarThresholdClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSegmenta::BtnAjustarThresholdClick(TObject *Sender)
{
  backup(&frmImagem->Figura,&frmImagem->FigBak);
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmSegmenta::TrckThresholdChange(TObject *Sender)
{
  Posicao->Caption = IntToStr(TrckThreshold->Position);
  Application->ProcessMessages();
  kodalith(TrckThreshold->Position,&frmImagem->FigBak,&frmImagem->Figura);
  frmImagem->ImgTrab->Invalidate();
  frmImagem->AtualizarHistograma();
}
//---------------------------------------------------------------------------
