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
*   Finalidade : Determina o endere�o base da placa HRT                        *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntConfig.h"
#include "fntCaptura.h"
//#include "../include/funcoestgi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmConfig *frmConfig;
//---------------------------------------------------------------------------
__fastcall TfrmConfig::TfrmConfig(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmConfig::FormCreate(TObject *Sender)
{
  ListaBaseSeg->ItemIndex=5;
}
//---------------------------------------------------------------------------

void __fastcall TfrmConfig::btnCancelarClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmConfig::btnOKClick(TObject *Sender)
{
  switch(ListaBaseSeg->ItemIndex)
    {
    case 0:{frmCaptura->baseseg = 0xc000; break; }
    case 1:{frmCaptura->baseseg = 0xc400; break; }
    case 2:{frmCaptura->baseseg = 0xc800; break; }
    case 3:{frmCaptura->baseseg = 0xcc00; break; }
    case 4:{frmCaptura->baseseg = 0xd000; break; }
    case 5:{frmCaptura->baseseg = 0xd400; break; }
    case 6:{frmCaptura->baseseg = 0xd800; break; }
    case 7:{frmCaptura->baseseg = 0xdc00; break; }
    }
  Close();
}
//---------------------------------------------------------------------------
