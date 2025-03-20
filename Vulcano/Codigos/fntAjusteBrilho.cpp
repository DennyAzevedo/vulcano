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
*   Finalidade : Ajustar o Brilho da Imagem                                    *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#include "fntImagem.h"
#include "../include/Funcoes.h"

#pragma hdrstop

#include "fntAjusteBrilho.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmBrilho *frmBrilho;
//---------------------------------------------------------------------------
__fastcall TfrmBrilho::TfrmBrilho(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrilho::FormShow(TObject *Sender)
{
  TrckBrilho->Position = 200;
  Posicao->Caption=IntToStr((TrckBrilho->Position - 200));
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrilho::FormClose(TObject *Sender, TCloseAction &Action)
{
  backup(&frmImagem->FigBak,&frmImagem->Figura);
  frmImagem->ImgTrab->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrilho::BtnCancelarBrilhoClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrilho::BtnAjustarBrilhoClick(TObject *Sender)
{
  backup(&frmImagem->Figura,&frmImagem->FigBak);
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmBrilho::TrckBrilhoChange(TObject *Sender)
{
  Posicao->Caption = IntToStr((TrckBrilho->Position - 200));
  Application->ProcessMessages();
  changebright(TrckBrilho->Position-200,&frmImagem->FigBak,&frmImagem->Figura);
  frmImagem->ImgTrab->Invalidate();
  frmImagem->AtualizarHistograma();
}
//---------------------------------------------------------------------------


