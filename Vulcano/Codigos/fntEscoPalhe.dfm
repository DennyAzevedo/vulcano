object frmEscoPalhe: TfrmEscoPalhe
  Left = 497
  Top = 307
  Width = 301
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
  object Bevel1: TBevel
    Left = 80
    Top = 32
    Width = 202
    Height = 3
    Shape = bsFrame
    Style = bsRaised
  end
  object Label3: TLabel
    Left = 192
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
  object QuadroD1: TShape
    Left = 215
    Top = 68
    Width = 49
    Height = 49
  end
  object lblQuadroD1: TLabel
    Left = 228
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
  object Label5: TLabel
    Left = 192
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
  object QuadroD2: TShape
    Left = 215
    Top = 187
    Width = 49
    Height = 49
  end
  object lblQuadroD2: TLabel
    Left = 228
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
  object Bevel2: TBevel
    Left = 178
    Top = 5
    Width = 3
    Height = 271
    Shape = bsFrame
    Style = bsRaised
  end
  object Label4: TLabel
    Left = 100
    Top = 12
    Width = 66
    Height = 16
    Caption = 'Elemento'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 196
    Top = 12
    Width = 64
    Height = 16
    Caption = 'Diagonal'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
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
    Top = 290
    Width = 293
    Align = alBottom
    AutoSize = True
    ButtonHeight = 30
    ButtonWidth = 31
    Caption = 'ToolBar1'
    Flat = True
    Images = frmImagem.ImageList1
    TabOrder = 3
    object btnSair: TToolButton
      Left = 0
      Top = 0
      Caption = 'btnSair'
      ImageIndex = 10
      OnClick = btnSairClick
    end
  end
  object Ver3: TCheckBox
    Left = 189
    Top = 85
    Width = 16
    Height = 17
    TabOrder = 4
  end
  object Ver4: TCheckBox
    Left = 189
    Top = 203
    Width = 17
    Height = 17
    TabOrder = 5
  end
end
