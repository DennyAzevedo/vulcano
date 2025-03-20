/*******************************************************************************
*                                                                              *
*   Autores:  Walter da Silva Porto Neto                                       *
*             Alexandre Monteiro de Oliveira                                   *
*             Paulo Rogério da C Santos                                        *
*                                                                              *
*   Título TGI: Aplicativo para Aquisição e Tratamento de Imagens              *
*                                                                              *
*   Orientadores: Francisco Carlos Parquet Bizarria                            *
*                 José Wlater Parquet Bizarria                                 *
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
*   Modificado em : 19/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Exibição do Histograma (Níveis de Cinza) da Imagem            *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntHistograma.h"
#include "fntImagem.h"
#include "../include/Funcoes.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHistograma *frmHistograma;
//---------------------------------------------------------------------------
__fastcall TfrmHistograma::TfrmHistograma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmHistograma::FormShow(TObject *Sender)
{
  ImgHisto->Canvas->FillRect(Rect(0,0,512,253));
  CalcDrawHisto(&frmImagem->Figura,ImgHisto->Canvas->Handle,0,-10,256,552);
  ImgHisto->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfrmHistograma::btnSairClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

