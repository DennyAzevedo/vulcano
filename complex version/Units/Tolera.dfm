object frmTolera: TfrmTolera
  Left = 349
  Top = 596
  Width = 544
  Height = 303
  Caption = 'Ajuste de Toler'#226'ncia na Busca'
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
  object Label1: TLabel
    Left = 24
    Top = 52
    Width = 227
    Height = 23
    Caption = 'Toler'#226'ncia Superior (+)'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Black'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 26
    Top = 153
    Width = 210
    Height = 23
    Caption = 'Toler'#226'ncia Inferior (-)'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Black'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 12
    Width = 228
    Height = 23
    Caption = 'Unidade da Toler'#226'ncia:'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial Black'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object BarTolSup: TTrackBar
    Left = 24
    Top = 100
    Width = 450
    Height = 45
    Max = 255
    Orientation = trHorizontal
    PageSize = 0
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 0
    ThumbLength = 15
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = BarTolSupChange
  end
  object BarTolInf: TTrackBar
    Left = 26
    Top = 197
    Width = 450
    Height = 45
    Max = 255
    Orientation = trHorizontal
    PageSize = 0
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 1
    ThumbLength = 15
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = BarTolInfChange
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 244
    Width = 536
    Align = alBottom
    AutoSize = True
    ButtonHeight = 30
    ButtonWidth = 31
    Caption = 'ToolBar1'
    Flat = True
    Images = WndImagem.ImageList1
    TabOrder = 2
    object Sair: TToolButton
      Left = 0
      Top = 0
      Caption = 'Sair'
      ImageIndex = 10
      OnClick = SairClick
    end
  end
  object edtToSup: TEdit
    Left = 480
    Top = 106
    Width = 41
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    Text = '0'
    OnChange = edtToSupChange
  end
  object edtToInf: TEdit
    Left = 480
    Top = 201
    Width = 41
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    Text = '0'
    OnChange = edtToInfChange
  end
  object rbValor: TRadioButton
    Left = 266
    Top = 16
    Width = 65
    Height = 17
    Caption = 'Valor'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = rbValorClick
  end
  object rbPerc: TRadioButton
    Left = 345
    Top = 16
    Width = 108
    Height = 17
    Caption = 'Percentual'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = rbPercClick
  end
end
