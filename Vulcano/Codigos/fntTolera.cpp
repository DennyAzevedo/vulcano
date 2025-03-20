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
*   Criado em : 18/03/2004                                                     *
*   Modificado em : 19/07/2004                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Determinação das Tolerâncias Superior e Inferior dos          *
*                Níveis de Cinza nos processos de Varredura e Busca            *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fntTolera.h"
#include "fntImagem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTolera *frmTolera;
int ValMax;
//---------------------------------------------------------------------------

__fastcall TfrmTolera::TfrmTolera(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::FormShow(TObject *Sender)
{
  BarTolSup->Position=frmImagem->PTolSup;
  BarTolInf->Position=frmImagem->PTolInf;
  if(frmImagem->Perc)
    {
    rbPerc->Checked=true;
    rbPercClick(Sender);
    }
  else
    {
    rbValor->Checked=true;
    rbValorClick(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::rbValorClick(TObject *Sender)
{
  frmImagem->Perc=false;
  BarTolSup->Max=255;
  BarTolInf->Max=255;
  ValMax=255;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::rbPercClick(TObject *Sender)
{
  frmImagem->Perc=true;
  BarTolSup->Max=100;
  BarTolInf->Max=100;
  ValMax=100;
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::BarTolSupChange(TObject *Sender)
{
  frmImagem->PTolSup=BarTolSup->Position;
  if(BarTolSup->Position != StrToInt(edtToSup->Text))
    edtToSup->Text=IntToStr(BarTolSup->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::BarTolInfChange(TObject *Sender)
{
  frmImagem->PTolInf=BarTolInf->Position;
  if(BarTolInf->Position != StrToInt(edtToInf->Text))
    edtToInf->Text=IntToStr(BarTolInf->Position);
}

//---------------------------------------------------------------------------

void __fastcall TfrmTolera::edtToSupChange(TObject *Sender)
{
  if(StrToInt(edtToSup->Text)>ValMax)
    edtToSup->Text=IntToStr(ValMax);
  if(StrToInt(edtToSup->Text)<0)
    edtToSup->Text='0';
  frmImagem->PTolSup=StrToInt(edtToSup->Text);
  if(BarTolSup->Position != StrToInt(edtToSup->Text))
    BarTolSup->Position=StrToInt(edtToSup->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::edtToInfChange(TObject *Sender)
{
  if(StrToInt(edtToInf->Text)>ValMax)
    edtToInf->Text=IntToStr(ValMax);;
  if(StrToInt(edtToInf->Text)<0)
    edtToInf->Text='0';
  frmImagem->PTolInf=StrToInt(edtToInf->Text);
  if(BarTolInf->Position != StrToInt(edtToInf->Text))
    BarTolInf->Position=StrToInt(edtToInf->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::btnSairClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::edtToSupDChange(TObject *Sender)
{
  if(StrToInt(edtToSupD->Text)>100)
    edtToSupD->Text = "100";
  if(StrToInt(edtToSup->Text)<0)
    edtToSupD->Text = '0';
  frmImagem->TolSupP=StrToInt(edtToSupD->Text);
  if(BarTolSupD->Position != StrToInt(edtToSupD->Text))
    BarTolSupD->Position=StrToInt(edtToSupD->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::edtToInfDChange(TObject *Sender)
{
  if (StrToInt(edtToInfD->Text)>100)
    edtToInfD->Text = "100";
  if (StrToInt(edtToInfD->Text)<0)
    edtToInfD->Text = '0';
  frmImagem->TolInfP=StrToInt(edtToInfD->Text);
  if(BarTolInfD->Position != StrToInt(edtToInfD->Text))
    BarTolInfD->Position=StrToInt(edtToInfD->Text);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::BarTolSupDChange(TObject *Sender)
{
  frmImagem->TolSupP=BarTolSupD->Position;
  if(BarTolSupD->Position != StrToInt(edtToSupD->Text))
    edtToSupD->Text=IntToStr(BarTolSupD->Position);
}
//---------------------------------------------------------------------------

void __fastcall TfrmTolera::BarTolInfDChange(TObject *Sender)
{
  frmImagem->TolInfP=BarTolInfD->Position;
  if(BarTolInfD->Position != StrToInt(edtToInfD->Text))
    edtToInfD->Text=IntToStr(BarTolInfD->Position);
}
//---------------------------------------------------------------------------

