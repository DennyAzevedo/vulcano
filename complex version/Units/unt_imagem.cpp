/*******************************************************************************
*                                                                              *
*   Autores : Walter da Silva Porto Neto                                       *
*             Alexandre Monteiro de Oliveira                                   *
*             Paulo Rogério da C Santos                                        *
*                                                                              *
*   Modificado por : Denny Paulista Azevedo Filho                              *
*                                                                              *
*   Tese de Mestrado - Engenharia Mecânica (Automação Industrial)              *
*   Orientador : Francisco Carlos Parquet Bizarria                             *
*                José Wlater Parquet Bizarria                                  * 
*                                                                              *
*   Finalidade : Funções do Formulário de Imagem                               *
*                Acionamento das funções da Placa de Aquisição                 *
*                Funções da Fila Circular                                      *
*                Funções de Varredura de Imagem                                *
*                Funções de Busca (por vizinhança)                             *
*                                                                              *
*   Criado em : ??/??/2003                                                     *
*   Modificado em : 12/04/2004                                                 *
*                                                                              *
*******************************************************************************/



//---------------------------------------------------------------------------

#include <system.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vcl.h>
#pragma hdrstop

#include "unt_imagem.h"
#include "unt_principal.h"
#include "unt_histograma.h"
#include "unt_ajustegamma.h"
#include "unt_ajustebrilho.h"
#include "unt_ajustethreshold.h"
#include "unt_conv_matrix.h"
#include "unt_ajuda.h"
#include "../include/FuncoesTGI.h"
#include "EscoPalhe.h"
#include "Tolera.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvSwitch"
#pragma link "JvComponent"
#pragma link "JvxCtrls"
#pragma link "JvZoom"
#pragma link "JvTransLED"
#pragma resource "*.dfm"

using namespace std;

int FLef=1,FRig=1;
bool Alvo=false,Pintar=true;
int AlvoX=0,AlvoY=0,NumPon,SomaX,SomaY;
TRect MyRect, MyOther;

TWndImagem *WndImagem;
//---------------------------------------------------------------------------
__fastcall TWndImagem::TWndImagem(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWndImagem::Fechar1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndImagem::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  freeimage(&Figura);
  WndHistograma->Close();
}
//---------------------------------------------------------------------------
void __fastcall TWndImagem::FormPaint(TObject *Sender)
{
  if(Pintar)
    {
    viewimage(ImgOrg->Canvas,ImgOrg->Canvas->Handle,&Palleta,0,0,&ImageOrg);
    viewimage(ImgTrab->Canvas,ImgTrab->Canvas->Handle,&Palleta,0,0,&Figura);
    //ImgTrab->Canvas->CopyRect(MyOther,ImgOrg->Canvas,MyRect);
    }
  else
    ImgTrab->Canvas->CopyRect(MyOther,RImage->Canvas,MyRect);
}
//---------------------------------------------------------------------------
void __fastcall TWndImagem::Histograma1Click(TObject *Sender)
{
  Pintar=true;
  WndHistograma->Show();
}
//---------------------------------------------------------------------------
void __fastcall TWndImagem::Salvar1Click(TObject *Sender)
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
void __fastcall TWndImagem::Mirror1Click(TObject *Sender)
{
  espelho(&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::N8bpp1bpp1Click(TObject *Sender)
{
  int L,C;

  Pintar=true;
  WndSegmenta->ShowModal();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Gamma1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  WndGamma->ShowModal();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::N1bpp8bpp1Click(TObject *Sender)
{
  int erro;

  allocimage(&timage, HRTcol, HRTlin, 8);
  setimagearea(&Figura, 0, 0,HRTcol-1, HRTlin-1);
  erro = convert1bitto8bit(&Figura,&timage);
  if (erro == NO_ERROR)
    {
    freeimage(&Figura);
    copyimgdes(&timage, &Figura);
    }
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Equalizar1Click(TObject *Sender)
{
  histoequalize(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------


void __fastcall TWndImagem::AtualizarHistograma()
{
  WndHistograma->ImgHisto->Canvas->FillRect(Rect(0,0,512,253));
  CalcDrawHisto(&Figura,WndHistograma->ImgHisto->Canvas->Handle,0,-10,256,552);
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::ConfirmarAtualizacao()
{
  int resposta;
  resposta = Application->MessageBoxA("Deseja manter as alterações ?","Questão!",32|MB_YESNO);
  if (resposta != IDYES)
    {
    //backup(&FigBckup,&Figura);
    ImgTrab->Invalidate();
    }
}
//---------------------------------------------------------------------------


void __fastcall TWndImagem::Blur1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  blur(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Sharpen1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  sharpen(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Brilho1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  WndBrilho->ShowModal();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::ToolButton4Click(TObject *Sender)
{
  //backup(&FigBckup,&Figura);
  //ImgTrab->Canvas->CopyRect(MyOther,ImgOrg->Canvas, MyRect);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
// convertpaltorgb(imgdes far *srcimg, imgdes far *desimg);
// removenoise(&Image, &Image);


//---------------------------------------------------------------------------

void __fastcall TWndImagem::Converter8bpptoRGB1Click(TObject *Sender)
{
  imgdes timage;
  struct ponto_colorido *ponto;
  int i;

  //backup(&Figura,&FigBckup);
  allocimage(&timage, HRTcol, HRTlin, 24);
  convertpaltorgb(&Figura, &timage);
  copyimgdes(&timage, &Figura);
  ponto =(struct ponto_colorido *) Figura.ibuff;
  for(i=0;i<(HRTcol*HRTlin);i++)
    {
    AjustaCor(ponto);
    ponto++;
    }
  ImgTrab->Invalidate();;
}
//---------------------------------------------------------------------------



void __fastcall TWndImagem::EAND1Click(TObject *Sender)
{
  OperacaoLogica(1);
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::OUEXCLUSIVOXOR1Click(TObject *Sender)
{
  OperacaoLogica(3);
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::OUOR1Click(TObject *Sender)
{
  OperacaoLogica(2);
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::NoOUNOR1Click(TObject *Sender)
{
  OperacaoLogica(4);
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::OperacaoLogica(int tipo_operacao)
{
  imgdes cover;

  //backup(&Figura,&FigBckup);
  if (tipo_operacao != 4)
    {
    if ( AbrirArquivo->Execute() )
        {
        if ( AbrirArquivo->FileName != NULL )
            {
            allocimage(&cover, HRTcol, HRTlin, 8);
            loadjpg(AbrirArquivo->FileName.c_str(), &cover);
            }
        else tipo_operacao = 0;
        }
    else tipo_operacao = 0;
    }
  switch(tipo_operacao)
    {
    case 1: {andimage(&Figura,&cover,&Figura); break;}
    case 2: {orimage(&Figura,&cover,&Figura); break;}
    case 3: {xorimage(&Figura,&cover,&Figura); break;}
    case 4: {negative(&Figura,&Figura); break;}
    }
  if ( (tipo_operacao > 0) && (tipo_operacao < 4) ) freeimage(&cover);
  WndImagem->Show();
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Outline1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  outline(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::RemoverRuido1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  removenoise(&Figura,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Pixellize1Click(TObject *Sender)
{
  //backup(&Figura,&FigBckup);
  pixellize(5, &Figura, &Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------



void __fastcall TWndImagem::AjustaCor(struct ponto_colorido *ponto)
{
  unsigned int valor;
  int porcentagem;
  int aux;

  aux = ponto->blue & 0xFF;
  if (aux<16) {ponto->blue = 0;ponto->green = 0;ponto->red = 0;} //0
  if ((aux>=16)&&(aux<32)) {ponto->blue = 128;ponto->green = 0;ponto->red = 0;} //1
  if ((aux>=32)&&(aux<48)) {ponto->blue = 0;ponto->green = 128;ponto->red = 0;} //2
  if ((aux>=48)&&(aux<64)) {ponto->blue = 128;ponto->green = 128;ponto->red = 0;} //3
  if ((aux>=64)&&(aux<80)) {ponto->blue = 0;ponto->green = 0;ponto->red = 128;} //4
  if ((aux>=80)&&(aux<96)) {ponto->blue = 128;ponto->green = 0;ponto->red = 128;} //5
  if ((aux>=96)&&(aux<112)) {ponto->blue = 0;ponto->green = 128;ponto->red = 128;} //6
  if ((aux>=112)&&(aux<128)) {ponto->blue = 128;ponto->green = 128;ponto->red = 128;} //7
  if ((aux>=128)&&(aux<144)) {ponto->blue = 64;ponto->green = 64;ponto->red = 64;} //8
  if ((aux>=144)&&(aux<160)) {ponto->blue = 0xff;ponto->green = 0;ponto->red = 0;} //9
  if ((aux>=160)&&(aux<176)) {ponto->blue = 0;ponto->green = 0xff;ponto->red = 0;} //10
  if ((aux>=176)&&(aux<192)) {ponto->blue = 0xff;ponto->green = 0xff;ponto->red = 0;} //11
  if ((aux>=192)&&(aux<208)) {ponto->blue = 0;ponto->green = 0;ponto->red = 0xff;} //12
  if ((aux>=208)&&(aux<224)) {ponto->blue = 0xff;ponto->green = 0;ponto->red = 0xff;} //13
  if ((aux>=224)&&(aux<240)) {ponto->blue = 0;ponto->green = 0xff;ponto->red = 0xff;} //14
  if ( aux>=240 ) {ponto->blue = 0xff;ponto->green = 0xff;ponto->red = 0xff;} //15
  /*porcentagem = (100 * aux) / 0xFF;
  valor = (porcentagem * 0xFFFFFF) / 100;
  ponto->blue = valor & 0xFF;
  ponto->green = (valor>>8) & 0xFF;
  ponto->red = (valor>>16) & 0xFF;*/
}

void __fastcall TWndImagem::MatrizConvoluo1Click(TObject *Sender)
{
  Pintar=true;
  //backup(&Figura,&FigBckup);
  WndMatrix->ShowModal();
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::FormCreate(TObject *Sender)
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
  fig=1;
  NElem=0;
  TolInf=0;
  TolSup=0;
  PTolInf=0;
  PTolSup=0;
  ValPad=0;
  ValNull=255;
  Perc=false;
  Kern[0] =  0;
  Kern[1] = -2;
  Kern[2] = 0;
  Kern[3] = 1;
  Kern[4] = 1;
  Kern[5] = 1;
  Kern[6] = 0;
  Kern[7] = -2;
  Kern[8] = 1;
  Kern[9] = 1;
  Kern[10] = 0;
  Kern[11] = 0 ;
  Screen->Cursors[crMyCursor] = LoadCursor(HInstance, "NewCursor");
  Screen->Cursors[crTarget] = LoadCursor(HInstance, "TARGET");
  MyRect = Rect(0,0,512,460);
  MyOther = Rect(0,0,512,460);
}
//---------------------------------------------------------------------------


void __fastcall TWndImagem::Desfazer1Click(TObject *Sender)
{
  //backup(&FigBckup,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::RestaurarOriginal1Click(TObject *Sender)
{
  //backup(&Original,&Figura);
  ImgTrab->Invalidate();
  AtualizarHistograma();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::Contedo1Click(TObject *Sender)
{
  AnsiString url;
  wchar_t pagina[100];

  url = "file://c:/hrt_Mestrado/help/ajuda_imagem.html";
  url.WideChar(pagina,100);
  WndAjuda->BrowserAjuda->Navigate(pagina,0,0,0,0);
  WndAjuda->Show();
}


void __fastcall TWndImagem::SairClick(TObject *Sender)
{
  Pintar=true;
  Close();
}
//---------------------------------------------------------------------------


/*******************************************************************************
*                                                                              *
*   Autor : Denny Paulista Azevedo Filho                                       *
*                                                                              *
*   Tese de Mestrado - Engenharia Mecânica (Automação Industrial)              *
*   Orientador : Francisco Carlos Parquet Bizarria                             *
*                                                                              *
*   Finalidade : Funções da Fila Circular                                      *
*                Funções de Varredura de Imagem                                *
*                Funções de Busca (por vizinhança)                             *
*                                                                              *
*   Criado em : 08/01/2004                                                     *
*   Modificado em : 07/02/2004                                                 *
*                                                                              *
*******************************************************************************/

//---------------------------------------------------------------------------


void __fastcall TWndImagem::btnIniciarClick(TObject *Sender)
{
  int l,c;

  Pintar=false;
  lblNumEle->Visible=True;
  lblNumEle->Refresh();
  lblElem->Visible=True;
  btnIniciar->Enabled=0;
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
  NElem=0;
  lblElem->Caption=IntToStr(NElem);
  lblElem->Refresh();
  Varredura();
  btnIniciar->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::PaletaClick(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  frmEscoPalhe->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::btnToleClick(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  frmTolera->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::PegImgClick(TObject *Sender)
{
  Pintar=false;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  if(lblNumEle->Visible)
    {
    lblNumEle->Visible=false;
    lblElem->Visible=false;
    }
  lblCorFun->Visible=true;
  lblCorBus->Visible=true;
  Quadro1->Visible=true;
  Quadro2->Visible=true;
  lblQuadro1->Visible=true;
  lblQuadro2->Visible=true;
  ImgTrab->Cursor=crMyCursor;
  PegImg->Enabled=False;
  FLef=0;
  FRig=0;
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::QInit(void)
{
  Fila.Total=0;
  Fila.Comeco=0;
  Fila.Final=0;
}

int __fastcall TWndImagem::QisEmpty(void)
{
  return(Fila.Total==0);
}

int __fastcall TWndImagem::QisFull(void)
{
  return(Fila.Total==MAX);
}

int __fastcall TWndImagem::adc(int i)
{
  i++;
  if(i>(MAX))
    i=0;
  return(i);
}

void __fastcall TWndImagem::Enqueue(int Col, int Lin)
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

Ponto __fastcall TWndImagem::Dequeue(void)
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

void __fastcall TWndImagem::Varredura(void)
{
  int Ind1Pon=0;

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
  tblTeste->Insert();
  tblTesteData->Value=Date();
  tblTesteHora->Value=Time();
  tblTesteCorBusca->Value=ColorToString(NCor[ValPad]);
  tblTesteIndCorBusca->Value=ValPad;
  tblTesteCorFundo->Value=ColorToString(NCor[ValNull]);
  tblTesteIndCorFundo->Value=ValNull;
  tblTesteTolSup->Value=PTolSup;
  tblTesteTolInf->Value=PTolInf;
  tblTestePerc->Value=Perc;
  tblTeste->Post();
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
        tblElemento->Insert();
        tblElementoCodTeste->Value=tblTesteCodigo->Value;
        tblElementoNumElem->Value=NElem;
        tblElemento->Post();
        GuardaDados(Coluna,Linha);
        SomaX=0;
        SomaY=0;
        Busca();
        tblElemento->Edit();
        tblElementoNumPontos->Value=NumPon;
        tblElementoDMGCol->Value=(SomaX/NumPon);
        tblElementoDMGLin->Value=(SomaY/NumPon);
        tblElemento->Post();
        lblElem->Caption=IntToStr(NElem);
        lblElem->Refresh();
        }
      }
    }
}

void __fastcall TWndImagem::Busca(void)
{
  int l,c,x;
  Ponto Local;

  while(Fila.Total!=0)
    {
    Local=Dequeue();
    SomaX+=Local.Coluna;
    SomaY+=Local.Linha;
    ImgTrab->Canvas->Pixels[Local.Coluna][Local.Linha]=NCor[ValNull];
    if(btnPasso->Down)
      for(x=0;x<=1000000;x++);
    for(l=Local.Linha-1;l<=Local.Linha+1;l++)
      for(c=Local.Coluna-1;c<=Local.Coluna+1;c++)
        if(((l>=0)&&(l<HRTlin))&&((c>=0)&&(c<HRTcol)))
          if((ImgTrab->Canvas->Pixels[c][l]>=NCor[TolInf])&&(ImgTrab->Canvas->Pixels[c][l]<=NCor[TolSup]))
            {
            LinPonto=l;
            Enqueue(c,l);
            GuardaDados(c,l);
            }
    }
}

void __fastcall TWndImagem::GuardaDados(int Col, int Lin)
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
    tblPontos->Insert();
    tblPontosCodTeste->Value=tblTesteCodigo->Value;
    tblPontosNumElem->Value=NElem;
    tblPontosNuPonto->Value=NumPon;
    tblPontosColuna->Value=Col;
    tblPontosLinha->Value=Lin;
    tblPontosCor->Value=ColorToString(CorFig);
    tblPontosIndice->Value=iCor;
    tblPontos->Post();
    }
}

void __fastcall TWndImagem::ImgTrabMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  TColor CorFig;
  int Cont,iCor=0;

  if(Button==mbMiddle)
    {
    FLef=1;
    FRig=1;
    }
  if((FLef!=1)||(FRig!=1))
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
      ValPad=iCor;
      FLef=1;
      }
    if(Button==mbRight)
      {
      ValNull=iCor;
      FRig=1;
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::ImgTrabMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if(Alvo)
    {
    AlvoX=X;
    AlvoY=Y;
    ImgTrab->Cursor=crDefault;
    btnAlvo->Enabled=true;
    lblBaseX->Visible=false;
    lblBaseY->Visible=false;
    lblAlvoX->Visible=false;
    lblAlvoY->Visible=false;
    Alvo=false;
    }
  if((FLef==1)&&(FRig==1))
    {
    lblCorFun->Visible=false;
    lblCorBus->Visible=false;
    Quadro1->Visible=false;
    Quadro2->Visible=false;
    lblQuadro1->Visible=false;
    lblQuadro2->Visible=false;
    PegImg->Enabled=True;
    ImgTrab->Cursor=crDefault;
    }
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::ImgTrabMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  TColor CorFig;
  int Cont,iCor=0;

  if(Alvo)
    {
    lblAlvoX->Caption=IntToStr(X);
    lblAlvoY->Caption=IntToStr(Y);
    }
  else
    {
    if((FLef!=1)||(FRig!=1))
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
      if(FLef!=1)
        {
        Quadro1->Brush->Color=NCor[iCor];
        lblQuadro1->Caption=IntToStr(iCor);
        }
      if(FRig!=1)
        {
        Quadro2->Brush->Color=NCor[iCor];
        lblQuadro2->Caption=IntToStr(iCor);
        }
      }
    }
}
//---------------------------------------------------------------------------


void __fastcall TWndImagem::btnAlvoClick(TObject *Sender)
{
  Pintar=false;
  Alvo=true;
  RImage->Canvas->CopyRect(MyOther,ImgTrab->Canvas, MyRect);
  lblBaseX->Visible=true;
  lblBaseY->Visible=true;
  lblAlvoX->Visible=true;
  lblAlvoY->Visible=true;
  btnAlvo->Enabled=false;
  ImgTrab->Cursor=crTarget;
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::btnCentroideClick(TObject *Sender)
{
  int EleBase, BaseX, BaseY;
  bool Achou;
  Variant Alvos[2];
  TLocateOptions Opts;

  Pintar=false;
  Opts.Clear();
  //localizar o elemento base
  tblTeste->Last();
  Achou=false;
  Alvos[0]=Variant(AlvoX);
  Alvos[1]=Variant(AlvoY);
  tblElemento->First();
  while(!tblElemento->Eof)
    {
    tblPontos->First();
    if(tblPontos->Locate("Coluna;Linha",VarArrayOf(Alvos,1),Opts))
      {
      Achou=true;
      EleBase=tblPontosNumElem->Value;
      BaseX=tblElementoDMGCol->Value;
      BaseY=tblElementoDMGLin->Value;
      }
    /*while(!tblPontos->Eof)
      {
      if((tblPontosColuna->Value==AlvoX)||(tblPontosLinha->Value==AlvoY))
        {
        Achou=true;
        EleBase=tblPontosNumElem->Value;
        BaseX=tblElementoDMGCol->Value;
        BaseY=tblElementoDMGLin->Value;
        }
      if(Achou)
        tblPontos->Last();
      else
        tblPontos->Next();
      }*/
    if(Achou)
      tblElemento->Last();
    else
      tblElemento->Next();
    }
  ImgTrab->Canvas->Pen->Color=clRed;
  tblElemento->First();
  while(!tblElemento->Eof)
    {
    if(tblElementoNumElem->Value!=EleBase)
      {
      ImgTrab->Canvas->MoveTo(BaseX,BaseY);
      ImgTrab->Canvas->LineTo(tblElementoDMGCol->Value,tblElementoDMGLin->Value);
      }
    tblElemento->Next();
    }
}
//---------------------------------------------------------------------------



void __fastcall TWndImagem::btnAjustarClick(TObject *Sender)
{
  int C,L,Cont;

  Pintar=true;
  btnAjustar->Enabled=false;
  for(L=0;L<HRTlin;L++)
    {
    for(C=0;C<HRTcol;C++)
      {
      for(Cont=0;Cont<255;Cont++)
        if((NCor[Cont]<ImgTrab->Canvas->Pixels[C][L])&&(NCor[Cont+1]>ImgTrab->Canvas->Pixels[C][L]))
          {
          ImgTrab->Canvas->Pixels[C][L]=NCor[Cont+1];
          break;
          }
      }
    }
  btnAjustar->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TWndImagem::swtAmpliaClick(TObject *Sender)
{
  if(swtAmplia->StateOn)
    Zoom->Active=true;
  else
    Zoom->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
  if(swtAmplia->StateOn)
    if(Zoom->ZoomLevel<150)
      Zoom->ZoomLevel+=10;
}
//---------------------------------------------------------------------------

void __fastcall TWndImagem::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
  if(swtAmplia->StateOn)
    if(Zoom->ZoomLevel>10)
      Zoom->ZoomLevel-=10;
}
//---------------------------------------------------------------------------

