object WndHistograma: TWndHistograma
  Left = 197
  Top = 119
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Histograma'
  ClientHeight = 260
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
end
