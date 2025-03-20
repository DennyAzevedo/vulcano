//---------------------------------------------------------------------------
#include <vcl.h>
#include "include/Funcoes.h"
#pragma hdrstop

//----------------------------------------
USEFORM("Codigos\fntCaptura.cpp", frmCaptura);
USEFORM("Codigos\fntConfig.cpp", frmConfig);
USEFORM("Codigos\fntImagem.cpp", frmImagem);
USEFORM("Codigos\fntHistograma.cpp", frmHistograma);
USEFORM("Codigos\fntAjusteGamma.cpp", frmGamma);
USEFORM("Codigos\fntAjusteBrilho.cpp", frmBrilho);
USEFORM("Codigos\fntAjusteThreshold.cpp", frmSegmenta);
USEFORM("Codigos\fntConvMatrix.cpp", frmMatrix);
USEFORM("Codigos\fntEscoPalhe.cpp", frmEscoPalhe);
USEFORM("Codigos\fntDados.cpp", dmDados); /* TDataModule: File Type */
USEFORM("Codigos\fntSobre.cpp", frmSobre);
USEFORM("Codigos\fntTolera.cpp", frmTolera);
USEFORM("Codigos\fntParametros.cpp", frmParametros);
USEFORM("Codigos\fntPontoFisico.cpp", frmPontoFisico);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
    {
    Application->Initialize();
    Application->Title = "Vulcano";
                 Application->HelpFile = "";
     Application->CreateForm(__classid(TfrmImagem), &frmImagem);
     Application->CreateForm(__classid(TfrmCaptura), &frmCaptura);
     Application->CreateForm(__classid(TfrmConfig), &frmConfig);
     Application->CreateForm(__classid(TfrmHistograma), &frmHistograma);
     Application->CreateForm(__classid(TfrmGamma), &frmGamma);
     Application->CreateForm(__classid(TfrmBrilho), &frmBrilho);
     Application->CreateForm(__classid(TfrmSegmenta), &frmSegmenta);
     Application->CreateForm(__classid(TfrmMatrix), &frmMatrix);
     Application->CreateForm(__classid(TfrmEscoPalhe), &frmEscoPalhe);
     Application->CreateForm(__classid(TdmDados), &dmDados);
     Application->CreateForm(__classid(TfrmSobre), &frmSobre);
     Application->CreateForm(__classid(TfrmTolera), &frmTolera);
     Application->CreateForm(__classid(TfrmParametros), &frmParametros);
     Application->CreateForm(__classid(TfrmPontoFisico), &frmPontoFisico);
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

