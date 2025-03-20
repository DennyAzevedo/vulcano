/*******************************************************************************
*                                                                              *
*   Autores:  Walter da Silva Porto Neto                                       *
*             Alexandre Monteiro de Oliveira                                   *
*             Paulo Rogério da C Santos                                        *
*                                                                              *
*   Título TGI: Aplicativo para Aquisição e Tratamento de Imagens              *
*                                                                              *
*   Orientadores: Francisco Carlos Parquet Bizarria                            *
*                 José Walter Parquet Bizarria                                 *
*                                                                              *
*   Modificado por: Denny Paulista Azevedo Filho                               *
*                                                                              *
*   Tese de Mestrado - Engenharia Mecânica (Automação Industrial)              *
*                                                                              *
*   Título: Técnicas de Vizinhança Aplicadas a Validação Funcional de          *
*           Matriz de Cristal Líquido                                          *
*                                                                              *
*   Orientador: Francisco Carlos Parquet Bizarria                              *
*                                                                              *
*   Colaborador: José Walter Parquet Bizarria                                  *
*                                                                              *
*   Criado em : ??/??/2003                                                     *
*   Modificado em : 20/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Determina Valor do ThresHold para Binarização da Imagem       *
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
