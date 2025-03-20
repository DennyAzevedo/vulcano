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
*   Modificado em : 29/05/2005                                                 *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                                                              *
*   Finalidade : Funções de Tratamento de Imagem                               *
*                Acionamento das funções da Placa de Aquisição                 *
*                Funções da Fila Circular                                      *
*                Funções de Validação Funcional                                *
*                Funções de Busca (por vizinhança)                             *
*                                                                              *
*******************************************************************************/
//---------------------------------------------------------------------------

#include <system.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vcl.h>
#pragma hdrstop

#include "../include/vicdefs.h"
#include "fntImagem.h"
#include "fntCaptura.h"
#include "fntHistograma.h"
#include "fntAjusteGamma.h"
#include "fntAjusteBrilho.h"
#include "fntAjustetHreshold.h"
#include "fntConvMatrix.h"
#include "../include/Funcoes.h"
#include "fntEscoPalhe.h"
#include "fntTolera.h"
#include "fntDados.h"
#include "fntsplash.h"
#include "fntPontoFisico.h"
#include "fntParametros.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma link "JvSwitch"
#pragma link "JvComponent"
#pragma link "JvxCtrls"
#pragma link "JvZoom"
#pragma link "JvTransLED"
#pragma link "JvBalloonHint"
#pragma link "JvTrayIcon"
#pragma link "JvBevel"
#pragma resource "*.dfm"

using namespace std;

int FLef=2,FRig=2;
int AlvoX=0,AlvoY=0,NumPon,SomaX,SomaY;
int HRT_Largura, HRT_Altura;
bool Inspecao,Teste,Parametro;
char TestStatus;

TfrmImagem *frmImagem;
//---------------------------------------------------------------------------
__fastcall TfrmImagem::TfrmImagem(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::FormCreate(TObject *Sender)
{
  allocimage(&Figura, HRTcol, HRTlin, 8);
  allocimage(&FigBak, HRTcol, HRTlin, 8);
  allocimage(&ImageOrg,461,414,8);
  HRT_Largura = HRTcol;
  HRT_Altura  = HRTlin;
  Alvo   = false;
  Pintar = false;
  TolInf = 0;
  TolSup = 0;
  MontaPaleta();
  fig=1;
  Screen->Cursors[crMyCursor] = LoadCursor(HInstance, "NewCursor");
  Screen->Cursors[crTarget]   = LoadCursor(HInstance, "TARGET")   ;
  MyRect  = Rect(0,0,512,460);
  MyOther = Rect(0,0,512,460);
  if (dmDados->tbInspecao->RecordCount!=0)
    {
    dmDados->tbInspecao->Last();
    TestStatus = dmDados->tbInspecaoStatus->Value[0];
    /***************************************************************************
    *  STATUS:                                               Cor:              *
    *         A - Inspeção Aberta,mas não possui parametros      Azul          *
    *         E - Inspeção em Andamento (Execução)               Amarelo       *
    *         C - Inspeção Cancelada                             Vermelho      *
    *         T - Inspeção Terminada                             Verde         *
    ***************************************************************************/
    switch (TestStatus)
      {
      case 'A':
        //Inpeção aberta, sem parametro
        StatusLed->Color  = clBlue;
        StatusPeca->Color = clAqua;
        btnIniInsp->Enabled  = false;
        btnTerInsp->Enabled  = true ;
        btnCanInsp->Enabled  = true ;
        btnIniTeste->Enabled = true ;
        btnIniPara->Enabled  = true ;
        Inspecao  = false;
        Teste     = false;
        Parametro = false;
        Equa      = false;
        Conv      = true ;
        Bina      = false;
        swtEqua->StateOn  = Equa;
        swtConvo->StateOn = Conv;
        swtBina->StateOn  = Bina;
        NivelBina = -1   ;
        NElem     = 0    ;
        PTolInf   = 15   ;
        PTolSup   = 15   ;
        ValPad    = 0    ;
        ValPadD   = 0    ;
        ValNull   = 255  ;
        ValNullD  = 255  ;
        /***********************************************************************
        *  Diagonal (TDiag) :                Elemento Diagonal (BDiag) :       *
        *          P - Positivo (\)                      S - Superior          *
        *          N - Negatio  (/)                      I - Inferior          *
        ***********************************************************************/
        TDiag     = 'P'  ;
        BDiag     = 'S'  ;
        TolSupP   = 15   ;
        TolInfP   = 15   ;
        TolFalha  = 3    ;
        Perc      = false;
        Kern[0]   = '1'  ;
        Kern[1]   = '1'  ;
        Kern[2]   = '1'  ;
        Kern[3]   = '1'  ;
        Kern[4]   = '1'  ;
        Kern[5]   = '1'  ;
        Kern[6]   = '1'  ;
        Kern[7]   = '1'  ;
        Kern[8]   = '1'  ;
        Kern[9]   = '9'  ;
        break;
      case 'E':
        //Inspeção em Andamento
        StatusLed->Color = clYellow;
        btnIniInsp->Enabled = false;
        btnTerInsp->Enabled = true ;
        btnCanInsp->Enabled = true ;
        Inspecao  = true ;
        Teste     = false;
        Parametro = false;
        dmDados->tbParamet->Last();
        Equa      = dmDados->tbParametEqualizado->Value ;
        Conv      = dmDados->tbParametConvolucao->Value ;
        Bina      = dmDados->tbParametBinarizado->Value ;
        NivelBina = dmDados->tbParametNiveBin->Value    ;
        PTolInf   = dmDados->tbParametTolInf->Value     ;
        PTolSup   = dmDados->tbParametTolSup->Value     ;
        ValPad    = dmDados->tbParametCorBusca->Value   ;
        ValPadD   = dmDados->tbParametCorBDiag->Value   ;
        ValNull   = dmDados->tbParametCorFundo->Value   ;
        ValNullD  = dmDados->tbParametCorFDiag->Value   ;
        TDiag     = dmDados->tbParametTipoDiag->Value[0];
        BDiag     = dmDados->tbParametBaseDiag->Value[0];
        TolSupP   = dmDados->tbParametTolSupProp->Value ;
        TolInfP   = dmDados->tbParametTolInfProp->Value ;
        TolFalha  = dmDados->tbParametTolFalhas->Value  ;
        Perc      = dmDados->tbParametPerc->Value       ;
        Kern[0]   = dmDados->tbParametMat0->Value[0]    ;
        Kern[1]   = dmDados->tbParametMat1->Value[0]    ;
        Kern[2]   = dmDados->tbParametMat2->Value[0]    ;
        Kern[3]   = dmDados->tbParametMat3->Value[0]    ;
        Kern[4]   = dmDados->tbParametMat4->Value[0]    ;
        Kern[5]   = dmDados->tbParametMat5->Value[0]    ;
        Kern[6]   = dmDados->tbParametMat6->Value[0]    ;
        Kern[7]   = dmDados->tbParametMat7->Value[0]    ;
        Kern[8]   = dmDados->tbParametMat8->Value[0]    ;
        Kern[9]   = dmDados->tbParametMat9->Value[0]    ;
        swtEqua->StateOn  = Equa;
        swtConvo->StateOn = Conv;
        swtBina->StateOn  = Bina;
        //Ajusta o interruptor de Tolerância de Busca
        if ((PTolInf>0)&&(PTolSup>0))
          swtTolBusca->StateOn = true;
        else
          swtTolBusca->StateOn = false;
        //Ajusta o interruptor de Tolerância da Diagonal
        if ((TolSupP>0)&&(TolInfP>0))
          swtTolDiag->StateOn = true ;
        else
          swtTolDiag->StateOn = false;
        pnlMascara1->Visible  = false;
        pnlElemento->Visible  = true ;
        //verfica se peça ainda está em Inspeção
        if (dmDados->tbPeca->RecordCount!=0)
          {
          dmDados->tbPeca->Last();
          if (dmDados->tbPecaStatus->Value=='I')
            {
            //Verifica se existe elemntos verificados
            if (dmDados->tbElemen->RecordCount!=0)
              {
              dmDados->tbElemen->Last();
              NElem = dmDados->tbElemenNumElem->Value;
              lblAtu->Caption = IntToStr(NElem);
              TLocateOptions Loc;
              Loc.Clear();
              dmDados->tbElemPara->First();
              dmDados->tbElemPara->Locate("NumElem",NElem,Loc);
              lblLinF->Caption = IntToStr(dmDados->tbElemParaLinFis->Value) ;
              lblColF->Caption = IntToStr(dmDados->tbElemParaColFis->Value) ;
              dmDados->tbElemPara->Next();
              lblProx->Caption = IntToStr(dmDados->tbElemParaNumElem->Value);
              StatusPeca->Color = clYellow;
              btnCapturar->Enabled = true;
              btnTerPeca->Enabled  = true;
              }
            else
              {
              NElem=0;
              lblAtu->Caption  = IntToStr(NElem);
              dmDados->tbElemPara->First();
              lblLinF->Caption = IntToStr(dmDados->tbElemParaLinFis->Value) ;
              lblColF->Caption = IntToStr(dmDados->tbElemParaColFis->Value) ;
              lblProx->Caption = IntToStr(dmDados->tbElemParaNumElem->Value);
              StatusPeca->Color = clYellow;
              btnCapturar->Enabled = true;
              btnTerPeca->Enabled  = true;
              }
            }
          else
            {
            NElem=0;
            btnIniPeca->Enabled = true;
            if (dmDados->tbPecaStatus->Value=='A')
              StatusPeca->Color = clGreen;
            else
              StatusPeca->Color = clRed;
            }
          }
        break;
      case 'C':
        //Inspeção Cancelada
        StatusLed->Color  = clRed ;
        StatusPeca->Color = clAqua;
        Inspecao  = false;
        Teste     = false;
        Parametro = false;
        Equa      = false;
        Conv      = true ;
        Bina      = false;
        swtEqua->StateOn  = Equa;
        swtConvo->StateOn = Conv;
        swtBina->StateOn  = Bina;
        NivelBina = -1   ;
        NElem     = 0    ;
        PTolInf   = 15   ;
        PTolSup   = 15   ;
        ValPad    = 0    ;
        ValPadD   = 0    ;
        ValNull   = 255  ;
        ValNullD  = 255  ;
        TDiag     = 'P'  ;
        BDiag     = 'S'  ;
        TolSupP   = 15   ;
        TolInfP   = 15   ;
        TolFalha  = 3    ;
        Perc      = false;
        Kern[0]   = '1'  ;
        Kern[1]   = '1'  ;
        Kern[2]   = '1'  ;
        Kern[3]   = '1'  ;
        Kern[4]   = '1'  ;
        Kern[5]   = '1'  ;
        Kern[6]   = '1'  ;
        Kern[7]   = '1'  ;
        Kern[8]   = '1'  ;
        Kern[9]   = '9'  ;
        break;
      case 'T':
        //Inspeção Terminada
        StatusLed->Color  = clGreen;
        StatusPeca->Color = clAqua ;
        dmDados->tbParamet->Last();
        NElem     = 0;
        btnIniInsp->Enabled = false;
        btnTerInsp->Enabled = true ;
        btnCanInsp->Enabled = true ;
        Inspecao  = true ;
        Teste     = false;
        Parametro = false;
        Equa      = dmDados->tbParametEqualizado->Value ;
        Conv      = dmDados->tbParametConvolucao->Value ;
        Bina      = dmDados->tbParametBinarizado->Value ;
        NivelBina = dmDados->tbParametNiveBin->Value    ;
        PTolInf   = dmDados->tbParametTolInf->Value     ;
        PTolSup   = dmDados->tbParametTolSup->Value     ;
        ValPad    = dmDados->tbParametCorBusca->Value   ;
        ValPadD   = dmDados->tbParametCorBDiag->Value   ;
        ValNull   = dmDados->tbParametCorFundo->Value   ;
        ValNullD  = dmDados->tbParametCorFDiag->Value   ;
        TDiag     = dmDados->tbParametTipoDiag->Value[0];
        BDiag     = dmDados->tbParametBaseDiag->Value[0];
        TolSupP   = dmDados->tbParametTolSupProp->Value ;
        TolInfP   = dmDados->tbParametTolInfProp->Value ;
        TolFalha  = dmDados->tbParametTolFalhas->Value  ;
        Perc      = dmDados->tbParametPerc->Value       ;
        Kern[0]   = dmDados->tbParametMat0->Value[0]    ;
        Kern[1]   = dmDados->tbParametMat1->Value[0]    ;
        Kern[2]   = dmDados->tbParametMat2->Value[0]    ;
        Kern[3]   = dmDados->tbParametMat3->Value[0]    ;
        Kern[4]   = dmDados->tbParametMat4->Value[0]    ;
        Kern[5]   = dmDados->tbParametMat5->Value[0]    ;
        Kern[6]   = dmDados->tbParametMat6->Value[0]    ;
        Kern[7]   = dmDados->tbParametMat7->Value[0]    ;
        Kern[8]   = dmDados->tbParametMat8->Value[0]    ;
        Kern[9]   = dmDados->tbParametMat9->Value[0]    ;
        swtEqua->StateOn  = Equa;
        swtConvo->StateOn = Conv;
        swtBina->StateOn  = Bina;
        //Ajusta o interruptor de Tolerância de Busca
        if ((PTolInf>0)&&(PTolSup>0))
          swtTolBusca->StateOn = true ;
        else
          swtTolBusca->StateOn = false;
        //Ajusta o interruptor de Tolerância da Diagonal
        if ((TolSupP>0)&&(TolInfP>0))
          swtTolDiag->StateOn = true ;
        else
          swtTolDiag->StateOn = false;
        break;
      default :
        StatusLed->Color  = clAqua;
        StatusPeca->Color = clAqua;
        Inspecao  = false;
        Teste     = false;
        Parametro = false;
        Equa      = false;
        Conv      = true ;
        Bina      = false;
        swtEqua->StateOn  = Equa;
        swtConvo->StateOn = Conv;
        swtBina->StateOn  = Bina;
        NivelBina = -1   ;
        NElem     = 0    ;
        PTolInf   = 15   ;
        PTolSup   = 15   ;
        ValPad    = 0    ;
        ValPadD   = 0    ;
        ValNull   = 255  ;
        ValNullD  = 255  ;
        TDiag     = 'P'  ;
        BDiag     = 'S'  ;
        TolSupP   = 15   ;
        TolInfP   = 15   ;
        TolFalha  = 3    ;
        Perc      = false;
        Kern[0]   = '1'  ;
        Kern[1]   = '1'  ;
        Kern[2]   = '1'  ;
        Kern[3]   = '1'  ;
        Kern[4]   = '1'  ;
        Kern[5]   = '1'  ;
        Kern[6]   = '1'  ;
        Kern[7]   = '1'  ;
        Kern[8]   = '1'  ;
        Kern[9]   = '9'  ;
        break;
      }
    }
  else
    {
    StatusLed->Color  = clAqua;
    StatusPeca->Color = clAqua;
    Inspecao  = false;
    Teste     = false;
    Parametro = false;
    Equa      = false;
    Conv      = true ;
    Bina      = false;
    swtEqua->StateOn  = Equa;
    swtConvo->StateOn = Conv;
    swtBina->StateOn  = Bina;
    NivelBina = -1   ;
    NElem     = 0    ;
    PTolInf   = 15   ;
    PTolSup   = 15   ;
    ValPad    = 0    ;
    ValPadD   = 0    ;
    ValNull   = 255  ;
    ValNullD  = 255  ;
    TDiag     = 'P'  ;
    BDiag     = 'S'  ;
    TolSupP   = 15   ;
    TolInfP   = 15   ;
    TolFalha  = 3    ;
    Perc      = false;
    Kern[0]   = '1'  ;
    Kern[1]   = '1'  ;
    Kern[2]   = '1'  ;
    Kern[3]   = '1'  ;
    Kern[4]   = '1'  ;
    Kern[5]   = '1'  ;
    Kern[6]   = '1'  ;
    Kern[7]   = '1'  ;
    Kern[8]   = '1'  ;
    Kern[9]   = '9'  ;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::FormPaint(TObject *Sender)
{
  if(Pintar)
    {
    viewimage(ImgOrg->Canvas,ImgOrg->Canvas->Handle,&Palleta,0,0,&ImageOrg);
    viewimage(RImage->Canvas,RImage->Canvas->Handle,&Palleta,0,0,&Figura);
    ImgTrab->Canvas->CopyRect(MyOther,RImage->Canvas, MyRect);
    RImage->Visible = false;
    }
  else
    ImgTrab->Canvas->CopyRect(MyOther,RImage->Canvas,MyRect);
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
  if(swtAmplia->StateOn)
    if(Zoom->ZoomLevel<150)
      Zoom->ZoomLevel+=10;
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
  if(swtAmplia->StateOn)
    if(Zoom->ZoomLevel>10)
      Zoom->ZoomLevel-=10;
}
//---------------------------------------------------------------------------
/*******************************************************************************
*                                                                              *
*                   Funções de Tratamento de Imagem                            *
*                                                                              *
*******************************************************************************/

void __fastcall TfrmImagem::MatrizConvoluo1Click(TObject *Sender)
{
  Pintar=true;
  backup(&Figura,&FigBak);
  frmMatrix->ShowModal();
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Equalizar1Click(TObject *Sender)
{
  histoequalize(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Binarizar1Click(TObject *Sender)
{
  int L,C;

  Pintar=true;
  backup(&Figura,&FigBak);
  frmSegmenta->ShowModal();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Brilho1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  frmBrilho->ShowModal();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Gamma1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  frmGamma->ShowModal();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Outline1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  outline(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::RemoverRuido1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  removenoise(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Pixellize1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  pixellize(5, &Figura, &Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Blur1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  blur(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Sharpen1Click(TObject *Sender)
{
  backup(&Figura,&FigBak);
  sharpen(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Histograma1Click(TObject *Sender)
{
  Pintar=true;
  frmHistograma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::AtualizarHistograma()
{
  frmHistograma->ImgHisto->Canvas->FillRect(Rect(0,0,512,253));
  CalcDrawHisto(&Figura,frmHistograma->ImgHisto->Canvas->Handle,0,-10,256,552);
}
//---------------------------------------------------------------------------
/*******************************************************************************
*                                                                              *
*                   Funções do Menu e Speed Bar - Gerais                       *
*                                                                              *
*******************************************************************************/

void __fastcall TfrmImagem::Desfazer1Click(TObject *Sender)
{
  backup(&FigBak,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::RestaurarOriginal1Click(TObject *Sender)
{
  Pintar = true;
  copyimage(&frmCaptura->imagem,&Figura);
  //resize(&ImageOrg,&Figura);
  viewimage(ImgTrab->Canvas,ImgTrab->Canvas->Handle,&Palleta,0,0,&Figura);
  ImgTrab->Invalidate();

  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Fechar1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnSairClick(TObject *Sender)
{
  Pintar=true;
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Salvar1Click(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas,MyRect);
  if (DlgSalvar->Execute())
    if(DlgSalvar->FileName != NULL)
      {
      RImage->Picture->SaveToFile(DlgSalvar->FileName);
      }
  RImage->Picture->Bitmap->FreeImage();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnCapturarClick(TObject *Sender)
{
  AnsiString vProx;
  if (Inspecao)
    {
    if (dmDados->tbElemPara->Eof)
      vProx="X";
    else
      vProx=IntToStr(dmDados->tbElemParaNumElem->Value)+1;
    lblAtu->Caption  = IntToStr(NElem)                           ;
    lblProx->Caption = vProx                                     ;
    lblLinF->Caption = IntToStr(dmDados->tbElemParaLinFis->Value);
    lblColF->Caption = IntToStr(dmDados->tbElemParaColFis->Value);
    }
  else
    if (Parametro)
      frmPontoFisico->ShowModal();
    else
      if (Teste)
        {
        Imagem1->Enabled     = true;
        Filtros1->Enabled    = true;
        btnVoltar->Enabled   = true;
        btnOriginal->Enabled = true;
        btnHisto->Enabled    = true;
        btnGamma->Enabled    = true;
        btnBrilho->Enabled   = true;
        btnConv->Enabled     = true;
        btnEqua->Enabled     = true;
        btnTolera->Enabled   = true;
        btnPaleta->Enabled   = true;
        btnPegImg->Enabled   = true;
        }
  btnIniciar->Enabled  = true ;
  btnSalvar->Enabled   = true ;
  Pintar = true ;
  frmCaptura->ShowModal();
  ImgTrab->Invalidate();
  ImgOrg->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnIniInspClick(TObject *Sender)
{
  dmDados->tbInspecao->Last();
  if ((dmDados->tbInspecaoStatus->Value=='T')||
      (dmDados->tbInspecaoStatus->Value=='C')||
      (dmDados->tbInspecao->RecNo==0))
    {
    dmDados->tbInspecao->Append();
    dmDados->tbInspecaoDtInicio->Value = Date();
    dmDados->tbInspecaoHrInicio->Value = Time();
    dmDados->tbInspecaoStatus->Value   = 'A'   ;
    dmDados->tbInspecao->Post();
    StatusLed->Color = clBlue;
    TestStatus = 'A'  ;
    Inspecao   = false;
    Teste      = false;
    Parametro  = false;
    pnlElemento->Visible  = true ;
    pnlMascara1->Visible  = false;
    Imagem1->Enabled      = false;
    Filtros1->Enabled     = false;
    btnSalvar->Enabled    = false;
    btnVoltar->Enabled    = false;
    btnOriginal->Enabled  = false;
    btnCapturar->Enabled  = false;
    btnHisto->Enabled     = false;
    btnGamma->Enabled     = false;
    btnBrilho->Enabled    = false;
    btnConv->Enabled      = false;
    btnEqua->Enabled      = false;
    btnIniInsp->Enabled   = false;
    btnTerInsp->Enabled   = true ;
    btnCanInsp->Enabled   = true ;
    btnIniTeste->Enabled  = true ;
    btnTerTeste->Enabled  = false;
    btnIniPara->Enabled   = false;
    btnTerPara->Enabled   = false;
    btnPaleta->Enabled    = false;
    btnPegImg->Enabled    = false;
    btnTolera->Enabled    = false;
    btnIniPeca->Enabled   = false;
    btnIniciar->Enabled   = false;
    btnCentroide->Enabled = false;
    btnTerPeca->Enabled   = false;
    }
  else
    {
    ShowMessage(AnsiString("Já existe uma Inspeção em andamento.\n")+
                AnsiString("Ela deve ser terminada ou cancelada primeiro"));
    btnTerInsp->Enabled   = true ;
    btnCanInsp->Enabled   = true ;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnTerInspClick(TObject *Sender)
{
  dmDados->tbInspecao->Last();
  if (dmDados->tbPeca->RecordCount > 0)
    {
    Inspecao  = false;
    Teste     = false;
    Parametro = false;
    pnlElemento->Visible  = false;
    pnlMascara1->Visible  = true ;
    Imagem1->Enabled      = false;
    Filtros1->Enabled     = false;
    btnSalvar->Enabled    = false;
    btnVoltar->Enabled    = false;
    btnOriginal->Enabled  = false;
    btnCapturar->Enabled  = false;
    btnHisto->Enabled     = false;
    btnGamma->Enabled     = false;
    btnBrilho->Enabled    = false;
    btnConv->Enabled      = false;
    btnEqua->Enabled      = false;
    btnIniInsp->Enabled   = true ;
    btnTerInsp->Enabled   = false;
    btnCanInsp->Enabled   = false;
    btnIniTeste->Enabled  = false;
    btnTerTeste->Enabled  = false;
    btnIniPara->Enabled   = false;
    btnTerPara->Enabled   = false;
    btnPaleta->Enabled    = false;
    btnPegImg->Enabled    = false;
    btnTolera->Enabled    = false;
    btnIniPeca->Enabled   = false;
    btnIniciar->Enabled   = false;
    btnCentroide->Enabled = false;
    btnTerPeca->Enabled   = false;
    dmDados->tbInspecao->Last();
    dmDados->tbInspecao->Edit();
    dmDados->tbInspecaoDtTermino->Value = Date();
    dmDados->tbInspecaoHrTermino->Value = Time();
    dmDados->tbInspecaoStatus->Value    = 'T'   ;
    dmDados->tbInspecao->Post();
    StatusLed->Color = clGreen;
    }
  else
    ShowMessage(AnsiString("Não existe PEÇAS inspecionadas.\n")+
                AnsiString("Cancelar a Inpeção"));

}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnCanInspClick(TObject *Sender)
{
  Inspecao  = false;
  Teste     = false;
  Parametro = false;
  pnlElemento->Visible  = false;
  pnlMascara1->Visible  = true ;
  Imagem1->Enabled      = false;
  Filtros1->Enabled     = false;
  btnSalvar->Enabled    = false;
  btnVoltar->Enabled    = false;
  btnOriginal->Enabled  = false;
  btnCapturar->Enabled  = false;
  btnHisto->Enabled     = false;
  btnGamma->Enabled     = false;
  btnBrilho->Enabled    = false;
  btnConv->Enabled      = false;
  btnEqua->Enabled      = false;
  btnIniInsp->Enabled   = true ;
  btnTerInsp->Enabled   = false;
  btnCanInsp->Enabled   = false;
  btnIniTeste->Enabled  = false;
  btnTerTeste->Enabled  = false;
  btnIniPara->Enabled   = false;
  btnTerPara->Enabled   = false;
  btnPaleta->Enabled    = false;
  btnPegImg->Enabled    = false;
  btnTolera->Enabled    = false;
  btnIniPeca->Enabled   = false;
  btnIniciar->Enabled   = false;
  btnCentroide->Enabled = false;
  btnTerPeca->Enabled   = false;
  dmDados->tbInspecao->Last();
  dmDados->tbInspecao->Edit();
  dmDados->tbInspecaoDtTermino->Value = Date();
  dmDados->tbInspecaoHrTermino->Value = Time();
  dmDados->tbInspecaoStatus->Value    = 'C'   ;
  dmDados->tbInspecao->Post();
  StatusLed->Color = clRed;
  Equa      = false;
  Conv      = true ;
  Bina      = false;
  swtEqua->StateOn  = Equa;
  swtConvo->StateOn = Conv;
  swtBina->StateOn  = Bina;
  NivelBina = -1   ;
  NElem     = 0    ;
  PTolInf   = 15   ;
  PTolSup   = 15   ;
  ValPad    = 0    ;
  ValPadD   = 0    ;
  ValNull   = 255  ;
  ValNullD  = 255  ;
  TDiag     = 'P'  ;
  BDiag     = 'S'  ;
  TolSupP   = 15   ;
  TolInfP   = 15   ;
  TolFalha  = 3    ;
  Perc      = false;
  Kern[0]   = '1'  ;
  Kern[1]   = '1'  ;
  Kern[2]   = '1'  ;
  Kern[3]   = '1'  ;
  Kern[4]   = '1'  ;
  Kern[5]   = '1'  ;
  Kern[6]   = '1'  ;
  Kern[7]   = '1'  ;
  Kern[8]   = '1'  ;
  Kern[9]   = '9'  ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnIniTesteClick(TObject *Sender)
{
  Inspecao  = false;
  Teste     = true ;
  Parametro = false;
  NElem     = 0    ;
  Imagem1->Enabled      = false;
  Filtros1->Enabled     = false;
  btnSalvar->Enabled    = false;
  btnVoltar->Enabled    = false;
  btnOriginal->Enabled  = false;
  btnCapturar->Enabled  = true ;
  btnHisto->Enabled     = false;
  btnGamma->Enabled     = false;
  btnBrilho->Enabled    = false;
  btnConv->Enabled      = false;
  btnEqua->Enabled      = false;
  btnIniInsp->Enabled   = false;
  btnTerInsp->Enabled   = true ;
  btnCanInsp->Enabled   = true ;
  btnIniTeste->Enabled  = false;
  btnTerTeste->Enabled  = true ;
  btnIniPara->Enabled   = false;
  btnTerPara->Enabled   = false;
  btnPaleta->Enabled    = false;
  btnPegImg->Enabled    = false;
  btnTolera->Enabled    = false;
  btnIniPeca->Enabled   = false;
  btnIniciar->Enabled   = false;
  btnCentroide->Enabled = false;
  btnTerPeca->Enabled   = false;
  //Limpa as tabelas de Teste
  dmDados->tbPontosTeste->Close();
  dmDados->tbPoDiagTeste->Close();
  dmDados->tbDiagTeste->Close();
  dmDados->tbElemTeste->Close();
  dmDados->tbTeste->Close();
  dmDados->tbPontosTeste->Exclusive = true ;
  dmDados->tbPoDiagTeste->Exclusive = true ;
  dmDados->tbDiagTeste->Exclusive   = true ;
  dmDados->tbElemTeste->Exclusive   = true ;
  dmDados->tbTeste->Exclusive       = true ;
  dmDados->tbPontosTeste->Open();
  dmDados->tbPoDiagTeste->Open();
  dmDados->tbDiagTeste->Open();
  dmDados->tbElemTeste->Open();
  dmDados->tbTeste->Open();
  dmDados->tbPontosTeste->EmptyTable();
  dmDados->tbPoDiagTeste->EmptyTable();
  dmDados->tbDiagTeste->EmptyTable();
  dmDados->tbElemTeste->EmptyTable();
  dmDados->tbTeste->EmptyTable();
  dmDados->tbPontosTeste->Close();
  dmDados->tbPoDiagTeste->Close();
  dmDados->tbDiagTeste->Close();
  dmDados->tbElemTeste->Close();
  dmDados->tbTeste->Close();
  dmDados->tbPontosTeste->Exclusive = false;
  dmDados->tbPoDiagTeste->Exclusive = false;
  dmDados->tbDiagTeste->Exclusive   = false;
  dmDados->tbElemTeste->Exclusive   = false;
  dmDados->tbTeste->Exclusive       = false;
  dmDados->tbPontosTeste->Open();
  dmDados->tbPoDiagTeste->Open();
  dmDados->tbDiagTeste->Open();
  dmDados->tbElemTeste->Open();
  dmDados->tbTeste->Open();
  //Cria Registro para amarzenamento de dados do Teste
  dmDados->tbTeste->Append();
  dmDados->tbTeste->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnTerTesteClick(TObject *Sender)
{
  Inspecao  = false;
  Teste     = false;
  Parametro = false;
  Imagem1->Enabled      = false;
  Filtros1->Enabled     = false;
  btnSalvar->Enabled    = false;
  btnVoltar->Enabled    = false;
  btnOriginal->Enabled  = false;
  btnCapturar->Enabled  = false;
  btnHisto->Enabled     = false;
  btnGamma->Enabled     = false;
  btnBrilho->Enabled    = false;
  btnConv->Enabled      = false;
  btnEqua->Enabled      = false;
  btnIniInsp->Enabled   = false;
  btnTerInsp->Enabled   = true ;
  btnCanInsp->Enabled   = true ;
  btnIniTeste->Enabled  = false;
  btnTerTeste->Enabled  = false;
  btnIniPara->Enabled   = true ;
  btnTerPara->Enabled   = false;
  btnPaleta->Enabled    = false;
  btnPegImg->Enabled    = false;
  btnTolera->Enabled    = false;
  btnIniPeca->Enabled   = false;
  btnIniciar->Enabled   = false;
  btnCentroide->Enabled = false;
  btnTerPeca->Enabled   = false;
  frmParametros->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnIniParaClick(TObject *Sender)
{
  btnIniPara->Enabled   = false;
  btnTerPara->Enabled   = true ;
  btnCapturar->Enabled  = true ;
  Inspecao  = false;
  Teste     = false;
  Parametro = true ;
  NElem     = 0   ;
  dmDados->tbParamet->Append();
  dmDados->tbParametEqualizado->Value = Equa     ;
  dmDados->tbParametConvolucao->Value = Conv     ;
  dmDados->tbParametBinarizado->Value = Bina     ;
  dmDados->tbParametNiveBin->Value    = NivelBina;
  dmDados->tbParametTolInf->Value     = PTolInf  ;
  dmDados->tbParametTolSup->Value     = PTolSup  ;
  dmDados->tbParametCorBusca->Value   = ValPad   ;
  dmDados->tbParametCorBDiag->Value   = ValPadD  ;
  dmDados->tbParametCorFundo->Value   = ValNull  ;
  dmDados->tbParametCorFDiag->Value   = ValNullD ;
  dmDados->tbParametTipoDiag->Value   = TDiag    ;
  dmDados->tbParametBaseDiag->Value   = BDiag    ;
  dmDados->tbParametTolSupProp->Value = TolSupP  ;
  dmDados->tbParametTolInfProp->Value = TolInfP  ;
  dmDados->tbParametTolFalhas->Value  = TolFalha ;
  dmDados->tbParametPerc->Value       = Perc     ;
  dmDados->tbParametMat0->Value       = Kern[0]  ;
  dmDados->tbParametMat1->Value       = Kern[1]  ;
  dmDados->tbParametMat2->Value       = Kern[2]  ;
  dmDados->tbParametMat3->Value       = Kern[3]  ;
  dmDados->tbParametMat4->Value       = Kern[4]  ;
  dmDados->tbParametMat5->Value       = Kern[5]  ;
  dmDados->tbParametMat6->Value       = Kern[6]  ;
  dmDados->tbParametMat7->Value       = Kern[7]  ;
  dmDados->tbParametMat8->Value       = Kern[8]  ;
  dmDados->tbParametMat9->Value       = Kern[9]  ;
  dmDados->tbParamet->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnTerParaClick(TObject *Sender)
{
  Inspecao  = false;
  Teste     = false;
  Parametro = false;
  btnIniPeca->Enabled   = true ;
  btnTerPara->Enabled   = false;
  btnCapturar->Enabled  = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnIniPecaClick(TObject *Sender)
{
  dmDados->tbParamet->First();
  dmDados->tbElemPara->First();
  Inspecao  = true ;
  Teste     = false;
  Parametro = false;
  btnIniPeca->Enabled   = false;
  btnTerPeca->Enabled   = true ;
  btnCapturar->Enabled  = true ;
  NElem = 0;
  dmDados->tbPeca->Append();
  dmDados->tbPecaData->Value = Date();
  dmDados->tbPecaHora->Value = Time();
  dmDados->tbPeca->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnTerPecaClick(TObject *Sender)
{
  int ContFalha=0;

  btnCapturar->Enabled = false;
  btnTerPeca->Enabled  = false;
  btnIniPeca->Enabled  = true ;
  dmDados->tbElemen->First();
  while (dmDados->tbElemen->Eof)
    {
    if (dmDados->tbElemenStatus->Value == 'R')
      ContFalha++;
    dmDados->tbElemen->Next();
    }
  dmDados->tbPeca->Edit();
  /*****************************************************************************
  *  STATUS :                                                 COR:             *
  *          A - Aceito                                           Verde        *
  *          R - Rejeitado                                        Vermelho     *
  *****************************************************************************/
  if (ContFalha <= TolFalha)
    {
    dmDados->tbPecaStatus->Value = 'A';
    StatusPeca->Color = clGreen;
    }
  else
    {
    dmDados->tbPecaStatus->Value = 'R';
    StatusPeca->Color = clRed;
    }
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*                       Funções da Fila Circular                               *
*                                                                              *
*                                                                              *
*    Conversão de código Pascal para C/C++                                     *
*    Fonte:                                                                    *
*    PEREIRA, S. L., Estrutura de Dados Fundamentais: Conceitos e Aplicações,  *
*       São Paulo: Editora Érica, 1996,p.65-66, 69-72.                         *
*                                                                              *
*******************************************************************************/

void __fastcall TfrmImagem::QInit(void)
{
  Fila.Total=0;
  Fila.Comeco=0;
  Fila.Final=0;
}
//---------------------------------------------------------------------------

int __fastcall TfrmImagem::QisEmpty(void)
{
  return(Fila.Total==0);
}
//---------------------------------------------------------------------------

int __fastcall TfrmImagem::QisFull(void)
{
  return(Fila.Total==MAX);
}
//---------------------------------------------------------------------------

int __fastcall TfrmImagem::adc(int i)
{
  i++;
  if(i>(MAX))
    i=0;
  return(i);
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::Enqueue(int Col, int Lin)
{
  int p,EnFlag;

  EnFlag=1;
  if(!QisFull())
    {
    p=Fila.Comeco;
    while(p!=Fila.Final)
      {
      if((Fila.Memo[p].Coluna==Col)&&(Fila.Memo[p].Linha==Lin))
        EnFlag=0;
      p=adc(p);
      }
    if(EnFlag==1)
      {
      Fila.Memo[Fila.Final].Coluna=Col;
      Fila.Memo[Fila.Final].Linha=Lin;
      Fila.Final=adc(Fila.Final);
      Fila.Total+=1;
      }
    }
}
//---------------------------------------------------------------------------

Ponto __fastcall TfrmImagem::Dequeue(void)
{
  int i;

  i=Fila.Comeco;
  if(!QisEmpty())
    {
    Fila.Comeco=adc(Fila.Comeco);
    Fila.Total-=1;
    }
  return(Fila.Memo[i]);
}
//---------------------------------------------------------------------------
/*******************************************************************************
*                                                                              *
*                  Funções da Validação Funcional                              *
*                                                                              *
*******************************************************************************/

void __fastcall TfrmImagem::btnToleraClick(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  frmTolera->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnPaletaClick(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  frmEscoPalhe->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnPegImgClick(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  pnlMascara2->Visible = false;
  pnlCores->Visible    = true ;
  pnlIniciar->Visible  = false;
  ImgTrab->Cursor=crMyCursor;
  btnPegImg->Enabled=False;
  FLef=0;
  FRig=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::ImgTrabMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  TColor CorFig;
  int Cont,iCor=0;

  if(Button==mbMiddle)
    {
    FLef=2;
    FRig=2;
    }
  if((FLef!=2)||(FRig!=2))
    {
    CorFig=ImgTrab->Canvas->Pixels[X][Y];
    for(Cont=0;Cont<256;Cont++)
      {
      if(NCor[Cont]==CorFig)
        iCor=Cont;
      else
        if(Cont<=254)
          if((NCor[Cont]<CorFig)&&(NCor[Cont+1]>CorFig))
            iCor=Cont;
      }
    if(Button==mbLeft)
      {
      if (FLef==0)
        {
        ValPad=iCor;
        FLef=1;
        }
      else
        {
        ValPadD=iCor;
        FLef=2;
        }
      }
    if(Button==mbRight)
      {
      if (FRig==0)
        {
        ValNull=iCor;
        FRig=1;
        }
      else
        {
        ValNullD=iCor;
        FRig=2;
        }
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::ImgTrabMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if((FLef==2)&&(FRig==2))
    {
    pnlMascara2->Visible = true ;
    pnlCores->Visible    = false;
    pnlIniciar->Visible  = false;
    btnPegImg->Enabled=True;
    ImgTrab->Cursor=crDefault;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::ImgTrabMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  TColor CorFig;
  int Cont,iCor=0;
  if((FLef!=2)||(FRig!=2))
    {
    CorFig=ImgTrab->Canvas->Pixels[X][Y];
    for(Cont=0;Cont<256;Cont++)
      {
      if(NCor[Cont]==CorFig)
        iCor=Cont;
      else
        if(Cont<=254)
          if((NCor[Cont]<CorFig)&&(NCor[Cont+1]>CorFig))
            iCor=Cont;
      }
    if(FLef==0)
      {
      Quadro1->Brush->Color=NCor[iCor];
      lblQuadro1->Caption=IntToStr(iCor);
      }
    if(FRig==0)
      {
      Quadro2->Brush->Color=NCor[iCor];
      lblQuadro2->Caption=IntToStr(iCor);
      }
    if(FLef==1)
      {
      QuadroD1->Brush->Color=NCor[iCor];
      lblQuadroD1->Caption=IntToStr(iCor);
      }
    if(FRig==1)
      {
      QuadroD2->Brush->Color=NCor[iCor];
      lblQuadroD2->Caption=IntToStr(iCor);
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnIniciarClick(TObject *Sender)
{
  int l,c,Controle;

  Pintar   = false;
  Controle = NElem;
  pnlMascara2->Visible = false;
  pnlCores->Visible    = false;
  pnlIniciar->Visible  = true ;
  btnIniciar->Enabled  = false;
  btnCapturar->Enabled = false;
  if (Teste)
    {
    Imagem1->Enabled     = false;
    Filtros1->Enabled    = false;
    btnVoltar->Enabled   = false;
    btnOriginal->Enabled = false;
    btnHisto->Enabled    = false;
    btnGamma->Enabled    = false;
    btnBrilho->Enabled   = false;
    btnConv->Enabled     = false;
    btnEqua->Enabled     = false;
    btnTolera->Enabled   = false;
    btnPaleta->Enabled   = false;
    btnPegImg->Enabled   = false;
    }
  else
    {
    if (swtConvo->StateOn)
      {
      char *K;
      K      = Kern;
      Pintar = true;
      matrixconv(K,&Figura,&Figura);
      ImgTrab->Invalidate();
      Pintar = false;
      }
    if (swtEqua->StateOn)
      {
      Pintar = true;
      histoequalize(&Figura,&Figura);
      ImgTrab->Invalidate();
      Pintar = false;
      }
    if (swtBina->StateOn)
      {
      Pintar = true;
      kodalith(NivelBina,&Figura,&Figura);
      ImgTrab->Invalidate();
      Pintar = false;
      }
    }
  if (Inspecao)
    StatusEle->Color = clAqua;
  // Procura por Elemento
  for(l=0;l<HRTlin;l++)
    for(c=0;c<HRTcol;c++)
      {
      MDados[c][l].Linha=-1;
      MDados[c][l].Coluna=-1;
      }
  for(c=0;c<=MAX;c++)
    {
    Fila.Memo->Coluna=-1;
    Fila.Memo->Linha=-1;
    }
  QInit(); //inicializa a Fila Circular
  lblElem->Caption=IntToStr(NElem);
  lblElem->Refresh();
  Varredura();
  // Procura pelos Pontos Diagonal
  if (NElem == (Controle+1))
    {
    for(l=0;l<HRTlin;l++)
      for(c=0;c<HRTcol;c++)
        {
        MDados[c][l].Linha=-1;
        MDados[c][l].Coluna=-1;
        }
    for(c=0;c<=MAX;c++)
      {
      Fila.Memo->Coluna=-1;
      Fila.Memo->Linha=-1;
      }
    QInit(); //inicializa a Fila Circular
    NDiag = 0;
    lblDiag->Caption=IntToStr(NDiag);
    lblDiag->Refresh();
    VarreduraD();
    btnCentroide->Enabled  = true ;
    }
  else
    if (NElem == Controle)
      if (Inspecao)
        {
        NElem++;
        /***********************************************************************
        *  STATUS :                                           COR:             *
        *          A - Aceito                                     Verde        *
        *          R - Rejeitado                                  Vermelho     *
        ***********************************************************************/
        dmDados->tbElemen->Append();
        dmDados->tbElemenNumElem->Value   = NElem;
        dmDados->tbElemenNumPontos->Value = 0    ;
        dmDados->tbElemenCenCol->Value    = 0    ;
        dmDados->tbElemenCenLin->Value    = 0    ;
        dmDados->tbElemenDistDiag->Value  = 0    ;
        dmDados->tbElemenDistElem->Value  = 0    ;
        dmDados->tbElemenStatus->Value    = 'R'  ;
        dmDados->tbElemen->Post();
        StatusEle->Color = clRed;
        }
      else
        ShowMessage(AnsiString("Nenhum elemento foi detectado!!!\n")+
                    AnsiString("Verifique os dados de PARAMETRIZAÇÃO"));
    else
      ShowMessage(AnsiString("Vários elementos foram detectados!!!\n")+
                  AnsiString("Verifique os dados de PARAMETRIZAÇÃO"));
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*                 Função de VARREDURA dos ELEMENTOS da peça                    *
*                                                                              *
*******************************************************************************/
void __fastcall TfrmImagem::Varredura(void)
{
  int Ind1Pon=0;

  if(swtTolBusca->StateOn)
    {
    if(Perc)
      {
      TolInf=ValPad-(ValPad*(PTolInf/100));
      TolSup=ValPad+(ValPad*(PTolSup/100));
      }
    else
      {
      TolInf=ValPad-PTolInf;
      TolSup=ValPad+PTolSup;
      }
    if(TolInf<0)
      TolInf=0;
    if(TolSup>255)
      TolSup=255;
    }
  else
    {
    TolInf=ValPad;
    TolSup=ValPad;
    }
  for(Linha=0;Linha<=HRTlin;Linha++)
    {
    for(Coluna=0;Coluna<=HRTcol;Coluna++)
      {
      if((ImgTrab->Canvas->Pixels[Coluna][Linha]>=NCor[TolInf])&&
         (ImgTrab->Canvas->Pixels[Coluna][Linha]<=NCor[TolSup]))
        {
        if(Ind1Pon==0)
          {
          Lin1Pon=Linha;
          Ind1Pon=1;
          }
        LinPonto=Linha;
        Enqueue(Coluna,Linha);
        NumPon=0;
        NElem++;
        if (Inspecao)
          {
          dmDados->tbElemen->Append();
          dmDados->tbElemenNumElem->Value = NElem;
          dmDados->tbElemen->Post();
          }
        else
          if (Parametro)
            {
            dmDados->tbElemPara->Append();
            dmDados->tbElemParaNumElem->Value = NElem  ;
            dmDados->tbElemParaColFis->Value  = ColunaF;
            dmDados->tbElemParaLinFis->Value  = LinhaF ;
            dmDados->tbElemPara->Post();
            }
          else
            if (Teste)
              {
              dmDados->tbElemTeste->Append();
              dmDados->tbElemTesteNumElem->Value = NElem;
              dmDados->tbElemTeste->Post();
              }
        GuardaDados(Coluna,Linha);
        SomaX=0;
        SomaY=0;
        Busca();
        if (Inspecao)
          {
          dmDados->tbElemen->Edit();
          dmDados->tbElemenNumPontos->Value = NumPon        ;
          dmDados->tbElemenCenCol->Value    = (SomaX/NumPon);
          dmDados->tbElemenCenLin->Value    = (SomaY/NumPon);
          dmDados->tbElemen->Post();
          }
        else
          if (Parametro)
            {
            dmDados->tbElemPara->Edit();
            dmDados->tbElemParaNumPontos->Value = NumPon        ;
            dmDados->tbElemParaCenCol->Value    = (SomaX/NumPon);
            dmDados->tbElemParaCenLin->Value    = (SomaY/NumPon);
            dmDados->tbElemPara->Post();
            }
          else
            if (Teste)
              {
              dmDados->tbElemTeste->Edit();
              dmDados->tbElemTesteNumPontos->Value = NumPon        ;
              dmDados->tbElemTesteCenCol->Value    = (SomaX/NumPon);
              dmDados->tbElemTesteCenLin->Value    = (SomaY/NumPon);
              dmDados->tbElemTeste->Post();
              }
        lblElem->Caption=IntToStr(NElem);
        lblElem->Refresh();
        }
      }
    }
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*                  Função de VARREDURA da DIAGONAL da peça                     *
*                                                                              *
*******************************************************************************/
void __fastcall TfrmImagem::VarreduraD(void)
{
  int Ind1Pon=0;

  if(swtTolBusca->StateOn)
    {
    if(Perc)
      {
      TolInf=ValPadD-(ValPadD*(PTolInf/100));
      TolSup=ValPadD+(ValPadD*(PTolSup/100));
      }
    else
      {
      TolInf=ValPadD-PTolInf;
      TolSup=ValPadD+PTolSup;
      }
    if(TolInf<0)
      TolInf=0;
    if(TolSup>255)
      TolSup=255;
    }
  else
    {
    TolInf=ValPadD;
    TolSup=ValPadD;
    }
  for(Linha=0;Linha<=HRTlin;Linha++)
    {
    for(Coluna=0;Coluna<=HRTcol;Coluna++)
      {
      if((ImgTrab->Canvas->Pixels[Coluna][Linha]>=NCor[TolInf])&&
         (ImgTrab->Canvas->Pixels[Coluna][Linha]<=NCor[TolSup]))
        {
        if(Ind1Pon==0)
          {
          Lin1Pon=Linha;
          Ind1Pon=1;
          }
        LinPonto=Linha;
        Enqueue(Coluna,Linha);
        NumPon=0;
        NDiag++;
        if (Inspecao)
          {
          dmDados->tbDiag->Append();
          dmDados->tbDiagNuDiag->Value = NDiag;
          dmDados->tbDiag->Post();
          }
        else
          if (Parametro)
            {
            dmDados->tbDiagPara->Append();
            dmDados->tbDiagParaNuDiag->Value = NDiag;
            dmDados->tbDiagPara->Post();
            }
          else
            if (Teste)
              {
              dmDados->tbDiagTeste->Append();
              dmDados->tbDiagTesteNuDiag->Value = NDiag;
              dmDados->tbDiagTeste->Post();
              }
        GuardaDadosD(Coluna,Linha);
        SomaX=0;
        SomaY=0;
        BuscaD();
        if (Inspecao)
          {
          dmDados->tbDiag->Edit();
          dmDados->tbDiagCenCol->Value = (SomaX/NumPon);
          dmDados->tbDiagCenLin->Value = (SomaY/NumPon);
          dmDados->tbDiag->Post();
          }
        else
          if (Parametro)
            {
            dmDados->tbDiagPara->Edit();
            dmDados->tbDiagParaCenCol->Value = (SomaX/NumPon);
            dmDados->tbDiagParaCenLin->Value = (SomaY/NumPon);
            dmDados->tbDiagPara->Post();
            }
          else
            if (Teste)
              {
              dmDados->tbDiagTeste->Edit();
              dmDados->tbDiagTesteCenCol->Value = (SomaX/NumPon);
              dmDados->tbDiagTesteCenLin->Value = (SomaY/NumPon);
              dmDados->tbDiagTeste->Post();
              }
        lblDiag->Caption=IntToStr(NDiag);
        lblDiag->Refresh();
        }
      }
    }
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*                   Função de BUSCA dos ELEMENTOS da peça                      *
*                                                                              *
*******************************************************************************/
void __fastcall TfrmImagem::Busca(void)
{
  int l,c,x;
  Ponto Local;

  while(Fila.Total!=0)
    {
    Local=Dequeue();
    SomaX+=Local.Coluna;
    SomaY+=Local.Linha;
    ImgTrab->Canvas->Pixels[Local.Coluna][Local.Linha]=NCor[ValNull];
    //reduz velocidade de processamento - visualizar execução
    if(swtDelay->StateOn)
      for(x=0;x<=1000000;x++);
    for(l=Local.Linha-1;l<=Local.Linha+1;l++)
      for(c=Local.Coluna-1;c<=Local.Coluna+1;c++)
        if(((l>=0)&&(l<HRTlin))&&((c>=0)&&(c<HRTcol)))
          if((ImgTrab->Canvas->Pixels[c][l]>=NCor[TolInf])&&
             (ImgTrab->Canvas->Pixels[c][l]<=NCor[TolSup]))
            {
            LinPonto=l;
            Enqueue(c,l);
            GuardaDados(c,l);
            }
    }
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*                    Função de BUSCA da DIAGONAL da peça                       *
*                                                                              *
*******************************************************************************/
void __fastcall TfrmImagem::BuscaD(void)
{
  int l,c,x;
  Ponto Local;

  while(Fila.Total!=0)
    {
    Local=Dequeue();
    SomaX+=Local.Coluna;
    SomaY+=Local.Linha;
    ImgTrab->Canvas->Pixels[Local.Coluna][Local.Linha]=NCor[ValNullD];
    //reduz velocidade de processamento - visualizar execução
    if(swtDelay->StateOn)
      for(x=0;x<=1000000;x++);
    for(l=Local.Linha-1;l<=Local.Linha+1;l++)
      for(c=Local.Coluna-1;c<=Local.Coluna+1;c++)
        if(((l>=0)&&(l<HRTlin))&&((c>=0)&&(c<HRTcol)))
          if((ImgTrab->Canvas->Pixels[c][l]>=NCor[TolInf])&&
             (ImgTrab->Canvas->Pixels[c][l]<=NCor[TolSup]))
            {
            LinPonto=l;
            Enqueue(c,l);
            GuardaDadosD(c,l);
            }
    }
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*           Função de ARMAZENAMENTO DE PONTOS dos ELEMENTOS da peça            *
*                                                                              *
*******************************************************************************/
void __fastcall TfrmImagem::GuardaDados(int Col, int Lin)
{
  int C,Flag;
  int Cont,iCor=0;
  TColor CorFig;

  Flag=1;
  LinDado=LinPonto-Lin1Pon;
  C=0;
  while(MDados[C][LinDado].Coluna!= -1)
    {
    if((MDados[C][LinDado].Coluna==Col)&&(MDados[C][LinDado].Linha==Lin))
      Flag=0;
    C++;
    if(C>=HRTcol)
      break;
    }
  if(Flag==1)
    {
    NumPon++;
    MDados[C][LinDado].Coluna=Col;
    MDados[C][LinDado].Linha=Lin;
    CorFig=ImgTrab->Canvas->Pixels[Col][Lin];
    for(Cont=0;Cont<256;Cont++)
      if(NCor[Cont]==CorFig)
        iCor=Cont;
    if (Inspecao)
      {
      dmDados->tbPontos->Append();
      dmDados->tbPontosPonto->Value  = NumPon;
      dmDados->tbPontosColuna->Value = Col   ;
      dmDados->tbPontosLinha->Value  = Lin   ;
      dmDados->tbPontosCor->Value    = iCor  ;
      dmDados->tbPontos->Post();
      }
    else
      if (Parametro)
        {
        dmDados->tbPontosPara->Append();
        dmDados->tbPontosParaPonto->Value  = NumPon;
        dmDados->tbPontosParaColuna->Value = Col   ;
        dmDados->tbPontosParaLinha->Value  = Lin   ;
        dmDados->tbPontosParaCor->Value    = iCor  ;
        dmDados->tbPontosPara->Post();
        }
      else
        if (Teste)
          {
          dmDados->tbPontosTeste->Append();
          dmDados->tbPontosTestePonto->Value  = NumPon;
          dmDados->tbPontosTesteColuna->Value = Col   ;
          dmDados->tbPontosTesteLinha->Value  = Lin   ;
          dmDados->tbPontosTesteCor->Value    = iCor  ;
          dmDados->tbPontosTeste->Post();
          }
    }
}
//---------------------------------------------------------------------------

/*******************************************************************************
*                                                                              *
*            Função de ARMAZENAMENTO DE PONTOS da DIAGONAL da peça             *
*                                                                              *
*******************************************************************************/
void __fastcall TfrmImagem::GuardaDadosD(int Col, int Lin)
{
  int C,Flag;
  int Cont,iCor=0;
  TColor CorFig;

  Flag=1;
  LinDado=LinPonto-Lin1Pon;
  C=0;
  while(MDados[C][LinDado].Coluna!= -1)
    {
    if((MDados[C][LinDado].Coluna==Col)&&(MDados[C][LinDado].Linha==Lin))
      Flag=0;
    C++;
    if(C>=HRTcol)
      break;
    }
  if(Flag==1)
    {
    NumPon++;
    MDados[C][LinDado].Coluna=Col;
    MDados[C][LinDado].Linha=Lin;
    CorFig=ImgTrab->Canvas->Pixels[Col][Lin];
    for(Cont=0;Cont<256;Cont++)
      if(NCor[Cont]==CorFig)
        iCor=Cont;
    if (Inspecao)
      {
      dmDados->tbPoDiag->Append();
      dmDados->tbPoDiagPonto->Value  = NumPon;
      dmDados->tbPoDiagColuna->Value = Col   ;
      dmDados->tbPoDiagLinha->Value  = Lin   ;
      dmDados->tbPoDiagCor->Value    = iCor  ;
      dmDados->tbPoDiag->Post();
      }
    else
      if (Parametro)
        {
        dmDados->tbPoDiagPara->Append();
        dmDados->tbPoDiagParaPonto->Value  = NumPon;
        dmDados->tbPoDiagParaColuna->Value = Col   ;
        dmDados->tbPoDiagParaLinha->Value  = Lin   ;
        dmDados->tbPoDiagParaCor->Value    = iCor  ;
        dmDados->tbPoDiagPara->Post();
        }
      else
        if (Teste)
          {
          dmDados->tbPoDiagTeste->Append();
          dmDados->tbPoDiagTestePonto->Value  = NumPon;
          dmDados->tbPoDiagTesteColuna->Value = Col   ;
          dmDados->tbPoDiagTesteLinha->Value  = Lin   ;
          dmDados->tbPoDiagTesteCor->Value    = iCor  ;
          dmDados->tbPoDiagTeste->Post();
          }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::btnCentroideClick(TObject *Sender)
{

  int BaseC, BaseL, DCol, DLin, ECol, ELin;
  double DistD, DistE, DistDP, DistEP, VSup, VInf, Prop, PropPara;
  Variant Alvos[1];
  TLocateOptions Opts;

  if (Inspecao)
    {
    if (BDiag == 'S')
      {
      dmDados->tbDiag->First();
      BaseC = dmDados->tbDiagCenCol->Value;
      BaseL = dmDados->tbDiagCenLin->Value;
      dmDados->tbDiag->Next();
      DCol  = dmDados->tbDiagCenCol->Value;
      DLin  = dmDados->tbDiagCenLin->Value;
      }
    else
      {
      dmDados->tbDiag->Last();
      BaseC = dmDados->tbDiagCenCol->Value;
      BaseL = dmDados->tbDiagCenLin->Value;
      dmDados->tbDiag->Prior();
      DCol  = dmDados->tbDiagCenCol->Value;
      DLin  = dmDados->tbDiagCenLin->Value;
      }
    ECol = dmDados->tbElemenCenCol->Value;
    ELin = dmDados->tbElemenCenLin->Value;
    }
  else
    if (Parametro)
      {
      if (BDiag == 'S')
        {
        dmDados->tbDiagPara->First();
        BaseC = dmDados->tbDiagParaCenCol->Value;
        BaseL = dmDados->tbDiagParaCenLin->Value;
        dmDados->tbDiagPara->Next();
        DCol  = dmDados->tbDiagParaCenCol->Value;
        DLin  = dmDados->tbDiagParaCenLin->Value;
        }
      else
        {
        dmDados->tbDiagPara->Last();
        BaseC = dmDados->tbDiagParaCenCol->Value;
        BaseL = dmDados->tbDiagParaCenLin->Value;
        dmDados->tbDiagPara->Prior();
        DCol  = dmDados->tbDiagParaCenCol->Value;
        DLin  = dmDados->tbDiagParaCenLin->Value;
        }
      ECol = dmDados->tbElemParaCenCol->Value;
      ELin = dmDados->tbElemParaCenLin->Value;
      }
    else
      if (Teste)
        {
        if (BDiag == 'S')
          {
          dmDados->tbDiagTeste->First();
          BaseC = dmDados->tbDiagTesteCenCol->Value;
          BaseL = dmDados->tbDiagTesteCenLin->Value;
          dmDados->tbDiagTeste->Next();
          DCol  = dmDados->tbDiagTesteCenCol->Value;
          DLin  = dmDados->tbDiagTesteCenLin->Value;
          }
        else
          {
          dmDados->tbDiagTeste->Last();
          BaseC = dmDados->tbDiagTesteCenCol->Value;
          BaseL = dmDados->tbDiagTesteCenLin->Value;
          dmDados->tbDiagTeste->Prior();
          DCol  = dmDados->tbDiagTesteCenCol->Value;
          DLin  = dmDados->tbDiagTesteCenLin->Value;
          }
        ECol = dmDados->tbElemTesteCenCol->Value;
        ELin = dmDados->tbElemTesteCenLin->Value;
        }
    if (TDiag == 'P')
      {
      if (BDiag == 'S')
        {
        DistD = sqrt(pow((DCol-BaseC),2)+pow((DLin-BaseL),2));
        DistE = sqrt(pow((ECol-BaseC),2)+pow((ELin-BaseL),2));
        }
      else
        {
        DistD = sqrt(pow((BaseC-DCol),2)+pow((BaseL-DLin),2));
        DistE = sqrt(pow((BaseC-ECol),2)+pow((BaseL-ELin),2));
        }
      }
    else
      {
      if (BDiag == 'S')
        {
        DistD = sqrt(pow((BaseC-DCol),2)+pow((DLin-BaseL),2));
        DistE = sqrt(pow((BaseC-ECol),2)+pow((ELin-BaseL),2));
        }
      else
        {
        DistD = sqrt(pow((DCol-BaseC),2)+pow((BaseL-DLin),2));
        DistE = sqrt(pow((ECol-BaseC),2)+pow((BaseL-ELin),2));
        }
      }
  if (Inspecao)
    {
    Opts.Clear();
    Alvos[0] = dmDados->tbElemenNumElem->Value;
    dmDados->tbElemPara->Locate("NumElem",VarArrayOf(Alvos,1),Opts);
    DistEP = dmDados->tbElemParaDistElem->Value;
    DistEP = dmDados->tbElemParaDistDiag->Value;
    Prop     = DistE / DistD                  ;
    PropPara = DistEP / DistDP                ;
    VSup     = (Prop) * (1 + (TolFalha / 100));
    VInf     = (Prop) * (1 - (TolFalha / 100));
    dmDados->tbElemen->Edit();
    dmDados->tbElemenDistDiag->Value = DistD;
    dmDados->tbElemenDistElem->Value = DistE;
    if ((PropPara <= VSup) && (PropPara >= VInf))
      {
      dmDados->tbElemenStatus->Value = 'A';
      StatusEle->Color = clGreen;
      }
    else
      {
      dmDados->tbElemenStatus->Value = 'R';
      StatusEle->Color = clRed;
      }
    dmDados->tbElemen->Post();
    }
  else
    if (Parametro)
      {
      dmDados->tbElemPara->Edit();
      dmDados->tbElemParaDistDiag->Value = DistD;
      dmDados->tbElemParaDistElem->Value = DistE;
      dmDados->tbElemPara->Post();
      }
    else
      if (Teste)
        {
        dmDados->tbElemTeste->Edit();
        dmDados->tbElemTesteDistDiag->Value = DistD;
        dmDados->tbElemTesteDistElem->Value = DistE;
        dmDados->tbElemTeste->Post();
        ImgTrab->Canvas->Pen->Color=clRed;
        ImgTrab->Canvas->MoveTo(BaseC,BaseL);
        ImgTrab->Canvas->LineTo(DCol,DLin);
        ImgTrab->Canvas->Pen->Color=clGreen;
        ImgTrab->Canvas->MoveTo(BaseC,BaseL);
        ImgTrab->Canvas->LineTo(ECol,ELin);
        }
  btnCapturar->Enabled  = true ;
  btnCentroide->Enabled = false;

}
//---------------------------------------------------------------------------
/*******************************************************************************
*                                                                              *
*                          Funções Gerais                                      *
*                                                                              *
*******************************************************************************/

void __fastcall TfrmImagem::swtAmpliaOn(TObject *Sender)
{
  Zoom->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::swtAmpliaOff(TObject *Sender)
{
  Zoom->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::MontaPaleta(void)
{
  int c,H1,H2;
  AnsiString S,P1,P2;

  H1=0;
  H2=0;
  for(c=0;c<256;c++)
  {
    S="0x00";
    if(H1<=9)
      P1=IntToStr(H1);
    if(H1==10)
      P1='a';
    if(H1==11)
      P1='b';
    if(H1==12)
      P1='c';
    if(H1==13)
      P1='d';
    if(H1==14)
      P1='e';
    if(H1==15)
    {
      P1='f';
      H1=-1;
      H2++;
    }
    if(H2<=9)
      P2=IntToStr(H2);
    if(H2==10)
      P2='a';
    if(H2==11)
      P2='b';
    if(H2==12)
      P2='c';
    if(H2==13)
      P2='d';
    if(H2==14)
      P2='e';
    if(H2==15)
      P2='f';
    S=S+P2+P1+P2+P1+P2+P1;
    NCor[c]=StringToColor(S);
    H1++;
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmImagem::Ativar1Click(TObject *Sender)
{
  Show();  
}
//---------------------------------------------------------------------------

void __fastcall TfrmImagem::JvTrayIcon1Click(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  Show();  
}
//---------------------------------------------------------------------------

