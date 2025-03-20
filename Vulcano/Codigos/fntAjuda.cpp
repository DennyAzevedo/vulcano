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
*   Finalidade : Mostrar Arquivo de Ajuda                                      *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntAjuda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TfrmAjuda *frmAjuda;
//---------------------------------------------------------------------------
__fastcall TfrmAjuda::TfrmAjuda(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
