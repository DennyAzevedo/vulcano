/*******************************************************************************
*                                                                              *
*   Autores:  Walter da Silva Porto Neto                                       *
*             Alexandre Monteiro de Oliveira                                   *
*             Paulo Rog�rio da C Santos                                        *
*                                                                              *
*   T�tulo TGI: Aplicativo para Aquisi��o e Tratamento de Imagens              *
*                                                                              *
*   Orientadores: Francisco Carlos Parquet Bizarria                            *
*                 Jos� Wlater Parquet Bizarria                                 *
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
*   Modificado em : 19/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Exibi��o do Histograma (N�veis de Cinza) da Imagem            *
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

