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
*   Finalidade : Determina o endereço base da placa HRT                        *
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
