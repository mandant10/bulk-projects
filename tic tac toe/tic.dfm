object Form1: TForm1
  Left = 619
  Top = 205
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'K'#243#322'ko i krzy'#380'yk'
  ClientHeight = 506
  ClientWidth = 837
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object p4: TImage
    Left = 96
    Top = 192
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p4Click
  end
  object p2: TImage
    Left = 200
    Top = 88
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p2Click
  end
  object p3: TImage
    Left = 304
    Top = 88
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p3Click
  end
  object p1: TImage
    Left = 96
    Top = 88
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p1Click
  end
  object p5: TImage
    Left = 200
    Top = 192
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p5Click
  end
  object p6: TImage
    Left = 304
    Top = 192
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p6Click
  end
  object p7: TImage
    Left = 96
    Top = 296
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p7Click
  end
  object p8: TImage
    Left = 200
    Top = 296
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p8Click
  end
  object p9: TImage
    Left = 304
    Top = 296
    Width = 100
    Height = 100
    Cursor = crHandPoint
    OnClick = p9Click
  end
  object tura: TLabel
    Left = 512
    Top = 88
    Width = 236
    Height = 46
    Caption = 'Ruch gracza:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object min: TImage
    Left = 608
    Top = 160
    Width = 30
    Height = 30
  end
  object Button1: TButton
    Left = 536
    Top = 264
    Width = 193
    Height = 49
    Cursor = crHandPoint
    Caption = 'Restart'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
end
