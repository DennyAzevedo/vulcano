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
*   Finalidade : Determina os Valores para a Matriz de Convolução              *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntConvMatrix.h"
#include "fntImagem.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMatrix *frmMatrix;
//---------------------------------------------------------------------------
__fastcall TfrmMatrix::TfrmMatrix(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmMatrix::FormCreate(TObject *Sender)
{
  matrix[0] = mtrx1;
  matrix[1] = mtrx2;
  matrix[2] = mtrx3;
  matrix[3] = mtrx4;
  matrix[4] = mtrx5;
  matrix[5] = mtrx6;
  matrix[6] = mtrx7;
  matrix[7] = mtrx8;
  matrix[8] = mtrx9;
  matrix[9] = mtrx10;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMatrix::FormShow(TObject *Sender)
{
  int i;
  for(i=0;i<10;i++)
    {
    matrix[i]->Text = IntToStr(frmImagem->Kern[i]);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMatrix::mtrx1KeyPress(TObject *Sender, char &Key)
{
/*if ( ( Key >= '0' ) && ( Key <= '9' ) )
    {
//    item->Text += Key;
    }
else if ( Key == '\b' ) ;
else if ( Key == '-' )  ;
else Key = NULL;*/
  if(!(((Key >= '0')&&(Key <= '9'))||(Key == '\b')||(Key == '-')))
    Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMatrix::BtnOKClick(TObject *Sender)
{
  int aux, i;
  char *K;

  for(i=0;i<10;i++)
    {
    if (matrix[i]->Text == NULL)
      matrix[i]->Text = '0';
    aux = StrToInt(matrix[i]->Text);
    frmImagem->Kern[i] = aux;
    }
  K = frmImagem->Kern;
  matrixconv(K, &frmImagem->Figura, &frmImagem->Figura);
  Close();
}
//---------------------------------------------------------------------------

