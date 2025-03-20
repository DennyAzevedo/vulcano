/*******************************************************************************
*                                                                              *
*   Autor: Denny Paulista Azevedo Filho                                        *
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
*   Criado em : 20/07/2004                                                     *
*   Modificado em : 01/06/2005                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Aramzenamento dos Dados e Informações                         *
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

