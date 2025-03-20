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
*   Criado em : 20/03/2004                                                     *
*   Modificado em : 19/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Determinação dos Níveis de Cinza para Valor de Busca          *
*                (ValPad) e Valor de Fundo (VallNull) através da Paleta        *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntEscoPalhe.h"
#include "fntImagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEscoPalhe *frmEscoPalhe;
//---------------------------------------------------------------------------
__fastcall TfrmEscoPalhe::TfrmEscoPalhe(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmEscoPalhe::FormShow(TObject *Sender)
{
  Quadro1->Brush->Color=frmImagem->NCor[frmImagem->ValPad];
  lblQuadro1->Caption=IntToStr(frmImagem->ValPad);
  Quadro2->Brush->Color=frmImagem->NCor[frmImagem->ValNull];
  lblQuadro2->Caption=IntToStr(frmImagem->ValNull);
  QuadroD1->Brush->Color=frmImagem->NCor[frmImagem->ValPadD];
  lblQuadroD1->Caption=IntToStr(frmImagem->ValPadD);
  QuadroD2->Brush->Color=frmImagem->NCor[frmImagem->ValNullD];
  lblQuadroD2->Caption=IntToStr(frmImagem->ValNullD);
}
//---------------------------------------------------------------------------

void __fastcall TfrmEscoPalhe::PonChange(TObject *Sender)
{
  if(Ver1->Checked)
    {
    Quadro1->Brush->Color=Barra->Canvas->Pixels[0][Pon->Position];
    lblQuadro1->Caption=IntToStr(Pon->Position);
    frmImagem->ValPad=Pon->Position;
    }
  if(Ver2->Checked)
    {
    Quadro2->Brush->Color=Barra->Canvas->Pixels[0][Pon->Position];
    lblQuadro2->Caption=IntToStr(Pon->Position);
    frmImagem->ValNull=Pon->Position;
    }
  if(Ver3->Checked)
    {
    QuadroD1->Brush->Color=Barra->Canvas->Pixels[0][Pon->Position];
    lblQuadroD1->Caption=IntToStr(Pon->Position);
    frmImagem->ValPadD=Pon->Position;
    }
  if(Ver4->Checked)
    {
    QuadroD2->Brush->Color=Barra->Canvas->Pixels[0][Pon->Position];
    lblQuadroD2->Caption=IntToStr(Pon->Position);
    frmImagem->ValNullD=Pon->Position;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmEscoPalhe::FormPaint(TObject *Sender)
{
  int c,l;

  for(l=0;l<256;l++)
    for(c=0;c<15;c++)
       Barra->Canvas->Pixels[c][l]=frmImagem->NCor[l];
}
//---------------------------------------------------------------------------

void __fastcall TfrmEscoPalhe::btnSairClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


