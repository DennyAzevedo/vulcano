/*******************************************************************************
*                                                                              *
*   Autor: Denny Paulista Azevedo Filho                                        *
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
*   Criado em : 20/07/2004                                                     *
*   Modificado em : 01/06/2005                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Aramzenamento dos Dados e Informa��es                         *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntDados.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmDados *dmDados;
//---------------------------------------------------------------------------
__fastcall TdmDados::TdmDados(TComponent* Owner)
  : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TdmDados::tbElemParaCalcFields(TDataSet *DataSet)
{
  tbElemParaProp->Value=tbElemParaDistElem->Value/tbElemParaDistDiag->Value;
}
//---------------------------------------------------------------------------

void __fastcall TdmDados::tbElemenCalcFields(TDataSet *DataSet)
{
  tbElemenProp->Value=tbElemenDistElem->Value/tbElemenDistDiag->Value;
}
//---------------------------------------------------------------------------

