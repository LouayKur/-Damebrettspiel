#include<iostream>
#include<string>
#include<array>
/**
*Die klasse spiel dient dazu, das spieldfeld, Kugeln,wer dran ist,der Aktuelle Zug und Ergibnisse der Spieler abzuspeichern
*Die klasse spiel prüft die Gültigkeit einen Zug in bestimmter Richtung 
*Die klasse verschiebt die Kugeln in das Feld
*/
class spiel
{
public:
  spiel(std::string w,std::string s,std::string p);
  unsigned int getv1();
  unsigned int getv2();
  unsigned int getz1();
  unsigned int getz2();
  bool get_turn() ;
  void print() const;
  void set_zug(unsigned int vonZeile,unsigned int vonSpalte,unsigned int zuZeile,unsigned int zuSpalte);
  void wechselturn();

  std::string get_element(unsigned int zeile , unsigned int spalte);
  std::string get_weisskugel();
  std::string get_schwarzkugel();
  std::string get_punkt();
	
  unsigned int nachLenks();
  unsigned int nachRechts();
  unsigned int nachOben();
  unsigned int nachUnten();
  unsigned int gueltigkeit(std::string eintrag,unsigned int kugelzahl,unsigned int stapel,unsigned int Richtung);
  unsigned int get_weisscore ();
  unsigned int get_schwarzscore();
  void nachRechtsSchieben();
  void nachLenksSchieben();
  void nachUntenSchieben();
  void nachObenSchieben();
  void spielSpeichern();
  void spielWiederherstellen();
private:
  std::string const weisskugel;     ///speichert die Buchstabe der Weißer Spieler
  std::string const schwarzkugel;   ///speichert die Buchstabe der schwarzer Spieler
  std::string const punkt;          ///speichert die Buchstabe,die als leere Platz vorgesehen wird
  unsigned int weisscore;           ///speichert das Ergibnis des weißen Spieler
  unsigned int schwarzscore;        ///speichert das Ergibnis des schwarzen Spieler 
/**
*Die Eigenschaft 'v1' speichert ab , von welcher Zeile der Zug ist
*Die Eigenschaft 'v2' speichert ab , von welcher Spalte der Zug ist
*Die Eigenschaft 'z1' speichert ab , zu welcher Zeile der Zug ist
*Die Eigenschaft 'z2' speichert ab , zu welcher Spalte der Zug ist
*/
  unsigned int v1,v2,z1,z2;         ///speicher den aktuellen Zug
  std::array<std::array<std::string,9>,8>spielfeld; //Das Spielfeld mit 8 zeilen und 9 Spalten
  bool turn;   //bezeichnet, wer dran ist
  char s_padding[7]; //zur vermeidung ein warning 'size padding'    

};
