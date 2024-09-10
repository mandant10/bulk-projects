//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString nazwapliku="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClick(TObject *Sender)
{
        ;        
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
        if(OpenDialog1 -> Execute())
        {
                try
                {
                     tresc->Lines->LoadFromFile(OpenDialog1->FileName);
                     nazwapliku=OpenDialog1->FileName;
                }
                catch(...)
                {
                        ShowMessage("B³¹d otwarcia pliku");
                }

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
        if(SaveDialog1 -> Execute())
        {
                try
                {
                     tresc->Lines->SaveToFile(SaveDialog1->FileName);
                     nazwapliku=OpenDialog1->FileName;
                }
                catch(...)
                {
                        ShowMessage("B³¹d zapisu pliku");
                }

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if(nazwapliku!="")
        {
                tresc->Lines->SaveToFile(nazwapliku);
        }
        else
        {
             Form1->Zapiszjako1Click(MainMenu1);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        if(Application->MessageBox("czy na pewno utworzyc nowy plik?","Potwierdz",
        MB_YESNOCANCEL | MB_ICONQUESTION)== IDYES)
        {
             tresc->Lines->Clear();
             nazwapliku="";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::trescKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Shift.Contains(ssCtrl))
        {
                if((Key=='s') || (Key=='S'))
                {
                        Form1->Zapisz1Click(MainMenu1);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Elo1Click(TObject *Sender)
{
        if(Application->MessageBox("czy na pewno zamknac?","Potwierdz",
        MB_YESNO | MB_ICONQUESTION)== IDYES)
        {
             Application->Terminate();
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application->MessageBox("czy na pewno zamknac","Potwierdz",
        MB_YESNO| MB_ICONQUESTION)== IDNO)
        {
             Action=caNone;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wytnij1Click(TObject *Sender)
{
        tresc->CutToClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::kopiuj1Click(TObject *Sender)
{
        tresc->CopyToClipboard();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Wklejctrlz1Click(TObject *Sender)
{
        tresc->PasteFromClipboard();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
        if(tresc->WordWrap)
        {
                tresc->WordWrap=0;
                Zawijaniewierszy1->Checked=0;
                tresc->ScrollBars=ssBoth;

        }
        else
        {
                tresc->WordWrap=1;
                Zawijaniewierszy1->Checked=1;
                tresc->ScrollBars=ssVertical;

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
        if(FontDialog1->Execute())
        {
                tresc->Font->Name=FontDialog1->Font->Name;
                tresc->Font->Color=  FontDialog1->Font->Color;
                tresc->Font->Size=FontDialog1->Font->Size;
                tresc->Font->Style=FontDialog1->Font->Style;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::czarny1Click(TObject *Sender)
{
        if(czarny1->Checked)
        {
              tresc->Color=clMenuBar;
              tresc->Font->Color=clBlack;
              czarny1->Checked=0;
        }
        else
        {
                tresc->Color=clNone;
              tresc->Font->Color=clGreen;
              czarny1->Checked=1;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Poco1Click(TObject *Sender)
{
       Form4->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::zegarkimwnajlepszastrona1Click(TObject *Sender)
{
        ShellExecute(NULL,"open","http://zegarkimw.cba.pl/",NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

