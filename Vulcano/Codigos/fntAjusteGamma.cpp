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


