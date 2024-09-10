object Form1: TForm1
  Left = 511
  Top = 471
  Width = 1334
  Height = 601
  Caption = 'elo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClick = FormClick
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object tresc: TMemo
    Left = 0
    Top = 0
    Width = 1318
    Height = 542
    Align = alClient
    Color = clMenuBar
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    OnKeyDown = trescKeyDown
  end
  object MainMenu1: TMainMenu
    Left = 1184
    Top = 16
    object Plik1: TMenuItem
      Caption = '&Plik'
      object Nowy1: TMenuItem
        Caption = '&Nowy'
        OnClick = Nowy1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Otwrz1: TMenuItem
        Caption = '&Otw'#243'rz'
        OnClick = Otwrz1Click
      end
      object Zapisz1: TMenuItem
        Caption = '&Zapisz   Ctrl+S'
        OnClick = Zapisz1Click
      end
      object Zapiszjako1: TMenuItem
        Caption = 'Zapi&sz jako'
        OnClick = Zapiszjako1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Elo1: TMenuItem
        Caption = '&Elo'
        OnClick = Elo1Click
      end
    end
    object Edycja1: TMenuItem
      Caption = '&Edycja'
      object Wytnij1: TMenuItem
        Caption = '&Wytnij   ctrl+x'
        OnClick = Wytnij1Click
      end
      object kopiuj1: TMenuItem
        Caption = '&kopiuj ctrl+c'
        OnClick = kopiuj1Click
      end
      object Wklejctrlz1: TMenuItem
        Caption = 'W&klej   ctrl+z'
        OnClick = Wklejctrlz1Click
      end
    end
    object Format1: TMenuItem
      Caption = '&Format'
      object Zawijaniewierszy1: TMenuItem
        Caption = '&Zawijanie wierszy'
        Checked = True
        OnClick = Zawijaniewierszy1Click
      end
      object Czcionka1: TMenuItem
        Caption = '&Czcionka'
        OnClick = Czcionka1Click
      end
      object czarny1: TMenuItem
        Caption = 'Czarny motyw'
        OnClick = czarny1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object Informacje1: TMenuItem
        Caption = '&Informacje'
        object Poco1: TMenuItem
          Caption = '&Po co'
          OnClick = Poco1Click
        end
        object zegarkimwnajlepszastrona1: TMenuItem
          Caption = '&zegarkimw najlepsza strona'
          OnClick = zegarkimwnajlepszastrona1Click
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'txt|*.txt|Wszytskie pliki|*.*'
    Left = 1144
    Top = 16
  end
  object SaveDialog1: TSaveDialog
    Filter = 'txt|*.txt|dowolny|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 1104
    Top = 16
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 1072
    Top = 16
  end
end
