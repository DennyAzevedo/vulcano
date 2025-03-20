object frmSplash: TfrmSplash
  Left = 403
  Top = 233
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 406
  ClientWidth = 492
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
  object TmrSplash: TTimer
    Enabled = False
    Interval = 300
    OnTimer = TmrSplashTimer
    Left = 455
    Top = 8
  end
end
