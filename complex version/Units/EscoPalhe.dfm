object frmEscoPalhe: TfrmEscoPalhe
  Left = 497
  Top = 307
  Width = 229
  Height = 356
  Caption = 'Escolher Cor - Palheta'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Quadro1: TShape
    Left = 111
    Top = 68
    Width = 49
    Height = 49
  end
  object Quadro2: TShape
    Left = 111
    Top = 187
    Width = 49
    Height = 49
  end
  object Label1: TLabel
    Left = 88
    Top = 40
    Width = 72
    Height = 16
    Caption = 'Cor Busca'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 88
    Top = 159
    Width = 72
    Height = 16
    Caption = 'Cor Fundo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Barra: TPaintBox
    Left = 24
    Top = 20
    Width = 15
    Height = 256
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
  end
  object lblQuadro1: TLabel
    Left = 124
    Top = 124
    Width = 21
    Height = 16
    Alignment = taRightJustify
    Caption = '000'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblQuadro2: TLabel
    Left = 124
    Top = 244
    Width = 21
    Height = 16
    Alignment = taRightJustify
    Caption = '000'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Pon: TTrackBar
    Left = 40
    Top = 11
    Width = 45
    Height = 274
    LineSize = 0
    Max = 255
    Orientation = trVertical
    PageSize = 0
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 0
    ThumbLength = 15
    TickMarks = tmTopLeft
    TickStyle = tsManual
    OnChange = PonChange
  end
  object Ver1: TCheckBox
    Left = 85
    Top = 85
    Width = 16
    Height = 17
    TabOrder = 1
  end
  object Ver2: TCheckBox
    Left = 85
    Top = 203
    Width = 17
    Height = 17
    TabOrder = 2
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 297
    Width = 221
    Align = alBottom
    AutoSize = True
    ButtonHeight = 30
    ButtonWidth = 31
    Caption = 'ToolBar1'
    Flat = True
    Images = WndImagem.ImageList1
    TabOrder = 3
    object Sair: TToolButton
      Left = 0
      Top = 0
      Caption = 'Sair'
      ImageIndex = 10
      OnClick = SairClick
    end
  end
end
