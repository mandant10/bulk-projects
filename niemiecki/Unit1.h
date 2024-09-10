//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TButton *Button1;
        TMemo *Memo1;
        TOpenDialog *OpenDialog1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit3;
        TLabel *Label4;
        TButton *Button9;
        TShape *Shape4;
        TTimer *Timer1;
        TTimer *Timer2;
        TMediaPlayer *MediaPlayer1;
        TMediaPlayer *MediaPlayer2;
        TMediaPlayer *MediaPlayer3;
        TTimer *Timer3;
        TSaveDialog *SaveDialog1;
        TLabel *Label5;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall zczytaj(int wiersz);
        void __fastcall Edit1Click(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall litera(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Edit3Click(TObject *Sender);
        void __fastcall przegrana(bool jed, bool dwa, bool trzy);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer3Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
