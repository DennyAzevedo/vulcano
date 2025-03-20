//---------------------------------------------------------------------------
#include <vcl.h>
#include "include/FuncoesTGI.h"
#pragma hdrstop

//----------------------------------------
USEFORM("Units\unt_principal.cpp", WndPrincipal);
USEFORM("Units\unt_config.cpp", WndConfig);
USEFORM("Units\unt_imagem.cpp", WndImagem);
USEFORM("Units\unt_histograma.cpp", WndHistograma);
USEFORM("Units\unt_ajustegamma.cpp", WndGamma);
USEFORM("Units\unt_ajustebrilho.cpp", WndBrilho);
USEFORM("Units\unt_splash.cpp", WndSplash);
USEFORM("Units\unt_ajustethreshold.cpp", WndSegmenta);
USEFORM("Units\unt_conv_matrix.cpp", WndMatrix);
USEFORM("Units\unt_ajuda.cpp", WndAjuda);
USEFORM("Units\EscoPalhe.cpp", frmEscoPalhe);
USEFORM("Units\Tolera.cpp", frmTolera);
USEFORM("Units\fntDados.cpp", dmDados); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
    {
    Application->Initialize();
    Application->Title = "HRT (Mestrado)";
    Application->HelpFile = "C:\\hrt_mestrado\\Help\\Ajuda.hlp";
    Application->CreateForm(__classid(TWndSplash), &WndSplash);
     Application->CreateForm(__classid(TWndPrincipal), &WndPrincipal);
     Application->CreateForm(__classid(TWndImagem), &WndImagem);
     Application->CreateForm(__classid(TWndConfig), &WndConfig);
     Application->CreateForm(__classid(TWndHistograma), &WndHistograma);
     Application->CreateForm(__classid(TWndGamma), &WndGamma);
     Application->CreateForm(__classid(TWndBrilho), &WndBrilho);
     Application->CreateForm(__classid(TWndSegmenta), &WndSegmenta);
     Application->CreateForm(__classid(TWndMatrix), &WndMatrix);
     Application->CreateForm(__classid(TWndAjuda), &WndAjuda);
     Application->CreateForm(__classid(TfrmEscoPalhe), &frmEscoPalhe);
     Application->CreateForm(__classid(TfrmTolera), &frmTolera);
     Application->CreateForm(__classid(TdmDados), &dmDados);
     Application->Run();
    }
  catch (Exception &exception)
    {
    Application->ShowException(&exception);
    }
  catch (...)
    {
    try
      {
      throw Exception("");
      }
    catch (Exception &exception)
      {
      Application->ShowException(&exception);
      }
    }
  return 0;
}
//---------------------------------------------------------------------------
