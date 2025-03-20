object frmHistograma: TfrmHistograma
  Left = 422
  Top = 210
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Histograma'
  ClientHeight = 296
  ClientWidth = 520
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 2
    Top = 2
    Width = 516
    Height = 256
  end
  object ImgHisto: TImage
    Left = 4
    Top = 4
    Width = 512
    Height = 253
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 264
    Width = 520
    Align = alBottom
    AutoSize = True
    ButtonHeight = 30
    ButtonWidth = 31
    Caption = 'ToolBar1'
    Flat = True
    Images = frmImagem.ImageList1
    TabOrder = 0
    object btnSair: TToolButton
      Left = 0
      Top = 0
      Caption = 'btnSair'
      ImageIndex = 10
      OnClick = btnSairClick
    end
  end
end
