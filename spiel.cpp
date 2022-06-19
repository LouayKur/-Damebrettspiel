#include"spiel.hpp"
#include <iostream>
#include<string>
#include<array>
#include<fstream>

/**
*Die Klasse 'InvalidInfOrmation' dient zur Erstellung der Objekte , die zur Fehler Werfen benötigen.
*/
class InvalidInfOrmation{};
/**
*Der Konstruktor instialiesiert ein Objekt mit aller Eigenschaften der Klasse.
*/
spiel::spiel(std::string w,std::string s,std::string p):weisskugel(w),schwarzkugel(s),punkt(p)
{   //intialisierung des Spielfeldes
        for(size_t zeile=0;zeile<8;zeile++)
        {
            for(size_t spalte=0;spalte<9;spalte++)
                {
                    if((zeile==0) & (spalte==0))
		     {
                        spielfeld[zeile][spalte]="  ";
                     }else if((zeile==0) & (spalte!=0))
                        {
                        spielfeld[zeile][spalte]=char(48+spalte);
                        }else if((zeile!=0) & (spalte==0))
                            {
                                spielfeld[zeile][spalte]=char(64+zeile);
                                spielfeld[zeile][spalte]+=" ";
                            }else if((zeile>=1)&&((spalte==1)||(spalte==2)))
                                {
                                    spielfeld[zeile][spalte]=weisskugel;
                                }else if((zeile>=1)&&((spalte==7)||(spalte==8)))
                                    {
                                        spielfeld[zeile][spalte]=schwarzkugel;
                                    }else
                                        {
                                            spielfeld[zeile][spalte]=punkt;
                                        }
                   }
           }
  weisscore=0;
  schwarzscore=0;
  turn=true;
}
/**
*Die Methode 'getv1' gibt zurück, von welcher Zeile der Zug ist.
*@return weist der Wert von der Eigenschaft 'v1' zu.
*/
unsigned int spiel::getv1()
{
/// Die Eigenschaft v1 des Objektes.
    return v1;
}
/**
*Die Methode 'getv2' gibt zurück, von welcher Spalte der Zug ist
*@return weist der Wert von der Eigenschaft 'v2' zu
*/
unsigned int spiel::getv2()
{
/// Die Eigenschaft v2 des Objektes.
    return v2;
}
/**
*Die Methode 'getz1' gibt zurück, zu welcher Zeile der Zug ist
*@return weist der Wert von der Eigenschaft 'z1' zu
*/
unsigned int spiel::getz1()
{
  /// Die Eigenschaft z1 des Objektes.
    return z1;
}
/**
*Die Methode 'getz2' gibt zurück, zu welcher Spalte der Zug ist
*@return weist der Wert von der Eigenschaft 'z2' zu
*/
unsigned int spiel::getz2()
{
/// Die Eigenschaft z2 des Objektes.
    return z2;
}
/**
*Die Methode 'get_turn' gibt zurück, wer dran ist
*@return weist der boolsche Wert von der Eigenschaft 'turn' zu   
*/
bool spiel::get_turn()
{
/// Die Eigenschaft turn des Objektes.
    return turn;
}
/**
*Die methode 'print' gibt die Ergibnisse der Spieler , das Spielfeld und wer dran ist aus
*/
void spiel::print() const 
{
  std::cout<<"___________________________________\n";
  std::cout<<"weissscore: "<<weisscore<<std::endl;
  std::cout<<"schwarzscore: "<<schwarzscore<<std::endl;
   for(size_t zeile=0;zeile<8;zeile++)
        {
            for(size_t spalte=0;spalte<9;spalte++)
                {
                    std::cout<<spielfeld[zeile][spalte];
                }
                std::cout<<'\n';
        }
    if(turn==true)
        {
            std::cout<<"Weiss ist dran!\n";
        }else
          {
            std::cout<<"Schwarz ist dran!\n";
          }
}
/**
*Die Methode 'set_zug' speichert die aktuelle zug in der Eigenschaften des objektes v1,v2,z1,z2 ab .
*/
void spiel::set_zug(unsigned int vonZeile,unsigned int vonSpalte,unsigned int zuZeile,unsigned int zuSpalte)
{
/// Zug des Objektes.
    v1=vonZeile;
    v2=vonSpalte;
    z1=zuZeile;
    z2=zuSpalte;
}
/**
*Die Methode 'wechselturn' ändert die boolsche wert 'turn' des Objektes 
*/
void spiel::wechselturn()
{
   if(turn==true)
    {
      turn=false;
    }else
    {
      turn=true;
    }
}
/**
*Die Methode get_element gibt ein Elemnt aus dem Spielfeld zurück
*
*@param zeile bezeichnet eine zeile des spielfeldes
*
*@param spalte bezeichnet eine spalte des spielfeldes
*
*@return weist das Element des spielfeldes zu.
*/
std::string spiel::get_element(unsigned int zeile , unsigned int spalte)
{
  return spielfeld[zeile][spalte];
}
/**
*Die Methode get_weisskugel gibt die Eigenschaft zurück.
*@return weist die Eigenschaft weisskugel zu.
*/
std::string spiel::get_weisskugel()
{
 return weisskugel;
}
/**
*Die Methode get_schwarzkugel gibt die Eigenschaft zurück.
*@return weist die Eigenschaft schwarzkugel zu.
*/
std::string spiel::get_schwarzkugel()
{
  return schwarzkugel;
}
/**
*Die Methode get_punkt gibt die Eigenschaft zurück.
*@return weist die Eigenschaft punkt zu.
*/
std::string spiel::get_punkt()
{
  return punkt;
}

/**
*Die Methode 'nachRechts' hat die Aufgabe ab dem Element des gewünschten Zug des Spielfelds bis zum Rechten Rand zu prüfen,
*ob das element des Feldes ein Kugel ist
*und zählt wie viele Kugeln in dieser Richtung gibt und wie viele Kugeln gerade nach die eigene Kugel stehen.
*
*@var eintrag speichert das element des Feldes ab
*@var kugelzahl zählt wie viele Kugeln in dieser richtung gibt
*@var stapel zählt wie viele Kugeln in dieser Richtung gerade nach dem eigenen Kugel stehen
*@return ruft die Methode gueltigkeit auf und liefert ihr die Ergibnisse mit der vordefinierten Richtung '0'
*'0=gewünschte Verschiebung nach Rechts' 
*/
unsigned int spiel::nachRechts()
{
  std::string eintrag;
  unsigned int kugelzahl=0;
  unsigned int stapel=0;
  eintrag=spielfeld[v1][v2];
  if((eintrag==weisskugel)||(eintrag==schwarzkugel))
    {
      for(size_t i=v2;i<=8;i++)  //eine for schleife läuft ab dem Element des Feldes in der selben Zeile bis zum Rechten Rand
        {
          if(spielfeld[v1][i]!=punkt)
            {
              kugelzahl+=1;
            }
        }
        for(size_t i=v2;i<=8;i++)
        {
          if(spielfeld[v1][i]!=punkt) // eine for schleife zum zählen die Kugeln nach dem eigenen Kugel.
            {
              stapel+=1;
            }else
              {
                break;
              }
        }
    }else
      {
	  std::cout<<"hier gibt's kein Kugel!";
          throw InvalidInfOrmation();
      }
  return gueltigkeit(eintrag,kugelzahl,stapel,0);
}
/**
*Die Methode 'nachOben' hat die Aufgabe ab dem Element des gewünschten Zug des Spielfelds bis zum oberen Rand zu prüfen,
*ob das element des Feldes ein Kugel ist
*und zählt wie viele Kugeln in dieser Richtung gibt und wie viele Kugeln gerade nach die eigene Kugel stehen.
*
*@var eintrag speichert das element des Feldes ab.
*@var kugelzahl zählt wie viele Kugeln in dieser richtung gibt.
*@var stapel zählt wie viele Kugeln in dieser Richtung gerade nach dem eigenen Kugel stehen.
*@return ruft die Methode gueltigkeit auf und liefert ihr die Ergibnisse mit der vordefinierten Richtung '2'.
*'2=gewünschte Verschiebung nach Oben' 
*/
unsigned int spiel::nachOben()
{
  std::string eintrag;
  unsigned int kugelzahl=0;
  unsigned int stapel=0;
  eintrag=spielfeld[v1][v2];
  if((eintrag==weisskugel)||(eintrag==schwarzkugel))
    {
      for(size_t i=v1;i>=1;i--) //eine for schleife läuft ab dem Element des Feldes in der selben Spalte bis zum oberen Rand
        {
          if(spielfeld[i][v2]!=punkt)
            {
              kugelzahl+=1;
            }
        }
        for(size_t i=v1;i>=1;i--)  // eine for schleife zum zählen die Kugeln nach dem eigenen Kugel.
          {
            if(spielfeld[i][v2]!=punkt)
              {
                stapel+=1;
              }else
                {
                  break;
                }
          }

    }else
      {
	std::cout<<"hier gibt's kein Kugel!";
        throw InvalidInfOrmation();
      }
  return gueltigkeit(eintrag,kugelzahl,stapel,2);
}
/**
*Die Methode 'nachUnten' hat die Aufgabe ab dem Element des gewünschten Zug des Spielfelds bis zum unteren Rand zu prüfen, 
*ob das element des Feldes ein Kugel ist
*und zählt wie viele Kugeln in dieser Richtung gibt und wie viele Kugeln gerade nach die eigene Kugel stehen.
*
*@var eintrag speichert das element des Feldes ab.
*@var kugelzahl zählt wie viele Kugeln in dieser richtung gibt.
*@var stapel zählt wie viele Kugeln in dieser Richtung gerade nach dem eigenen Kugel stehen.
*@return ruft die Methode gueltigkeit auf und liefert ihr die Ergibnisse mit der vordefinierten Richtung '3'.
*'3=gewünschte Verschiebung nach Unten' 
*/
unsigned int spiel::nachUnten()
{
  std::string eintrag;
  unsigned int kugelzahl=0;
  unsigned int stapel=0;
  eintrag=spielfeld[v1][v2];
  if((eintrag==weisskugel)||(eintrag==schwarzkugel))
    {
      for(size_t i=v1;i<=7;i++)  //eine for schleife läuft ab dem Element des Feldes in der selben Spalte bis zum unteren Rand
        {
          if(spielfeld[i][v2]!=punkt)
            {
              kugelzahl+=1;
            }
        }
        for(size_t i=v1;i<=7;i++)  // eine for schleife zum zählen die Kugeln nach dem eigenen Kugel.
         {
           if(spielfeld[i][v2]!=punkt)
             {
               stapel+=1;
             }else
                 {
                  break;
                 }
         }
    }else
        {
	  std::cout<<"hier gibt's kein Kugel!";
          throw InvalidInfOrmation();
        }
  return gueltigkeit(eintrag,kugelzahl,stapel,3);
}
/**
*Die Methode 'gueltigkeit' prüft, ob die Verschiebung in dieser Richtung anhand der Anzahl der Kugeln möglich ist
*und prüft, ob zu verschiebenen Kugel zu der , der dran ist, gehört.
*
*@param eintrag bezeichnet der zu verschiebenen  Kugel.
*@param kugelzahl ist die Anzahl der Kugeln in dieser Richtung.
*@param stapel ist die Anzahl der Kugeln gerade nach dem eigenen Kugel in dieser Richtung.
*@param Richtung ist die vordifinierten Richtung von der aufgerufenen Funktion.
*@return weist der vordifinierten Richtung zu.
*/
unsigned int spiel::gueltigkeit(std::string eintrag,unsigned int kugelzahl,unsigned int stapel,unsigned int Richtung)
{
  if((kugelzahl>=2)&&(stapel<=3))
  {
    if((eintrag==weisskugel) && (turn==true))
      {
        return Richtung;  
      }else if((eintrag==schwarzkugel)&&(turn==false))
        {
          return Richtung;
        }else
             {
	        std::cout<<"Sie können nur Ihre Kugeln bewegen!";
                throw InvalidInfOrmation();
             }
   }else
      {
	if(kugelzahl==1) ///es gibt nur die eigene Kugel.
	  {
 	     std::cout<<"in dieser Richtung gibt's keine Kugeln!";
	  }else
		{
		  std::cout<<"Sie können Maximal 2 Kugeln verschieben!";
		}
        throw InvalidInfOrmation(); 
      }    
}
/*
*Die Methode 'get_weisscore' gibt das Ergibnis des weißen Spieler zurück.
*
*@return weist der Wert der Eigenschaft weisscore des objektes zurück.
*/
unsigned int spiel::get_weisscore ()
{  
    return weisscore;
}
/*
*Die Methode 'get_schwarzscore' gibt das Ergibnis des schwarzen Spieler zurück.
*
*@return weist der Wert der Eigenschaft schwarzscore des objektes zurück.
*/
unsigned int spiel::get_schwarzscore()
{
    return schwarzscore;
}
/**
*Die Methode 'nachRechtsSchieben' hat die Aufgabe die Elemente in der selben Zeile vom Spielfeld nach Rechts zu verschieben
*und prüft, ob ein Kugel aus dem rechren Rand geworfen wurde und erhöht das Ergibnis der Spieler anhand des geworfenen Kugel
*und ruft die Funktion 'wechselturn' zum ändern der boolschen Wert des Objektes.
*
*@var tmp1 dient zur Verschiebung durch der Zeile und ist mit der Eigenschaft des leeren Element immer intialisiert.
*@var tmp2 dient zur Verschiebung durch der Zeile und zum Speichern der Wert vom nachstehenden Element.
*@pre tmp1!="." ein Kugel wurde ersetzt.
*@pre z2+i<=8 stellt fest, ob der Kugel am rechten Rand ist.
*/
void spiel::nachRechtsSchieben()
{
  std::string tmp1,tmp2;
  tmp1=punkt;
  tmp2=spielfeld[v1][z2];
  spielfeld[v1][z2]=spielfeld[v1][v2];  ///erste Verschiebung zum Ziel Platz ist immer gültig
  spielfeld[v1][v2]=tmp1;
  tmp1=tmp2;
///eine for Schleife von mindestens 2 Dürchlaüfe ist zur weitere Verschiebung und nachprüfen,ob ein Kugel raus ist, ausreichend
  for(size_t i=1;i<=2;i++) ///den rechten Rand
  {
    if(tmp1!=punkt)
    {
      if(z2+i<=8)
        {
          tmp2=spielfeld[v1][z2+i];
          spielfeld[v1][z2+i]=tmp1;
          tmp1=tmp2;
        }else
            {
              if(tmp1==weisskugel)
                {
                  std::cout<<"Weiss geworfen!\n";
                  schwarzscore+=1;
                }else
                    {
                        std::cout<<"Schwarz geworfen!\n";
                      weisscore+=1;
                    }
               break;
             }
    }
  }
    wechselturn();
}
/**
*Die Methode 'nachLenksSchieben' hat die Aufgabe die Elemente in der selben Zeile vom Spielfeld nach Links zu verschieben
*und prüft, ob ein Kugel aus dem lenken Rand geworfen wurde und erhöht das Ergibnis der Spieler anhand des geworfenen Kugel
*und ruft die Funktion 'wechselturn' zum ändern der boolschen Wert des Objektes.
*
*@var tmp1 dient zur Verschiebung durch der Zeile und ist mit der Eigenschaft des leeren Element immer intialisiert.
*@var tmp2 dient zur Verschiebung durch der Zeile und zum Speichern der Wert vom nachstehenden Element.
*pre tmp1!="." ein Kugel wurde ersetzt.  
*@pre z2-i>=1 stellt fest, ob der Kugel am lenken Rand ist.
*/
void spiel::nachLenksSchieben()
{
  std::string tmp1,tmp2;
  tmp1=punkt;
  tmp2=spielfeld[v1][z2];
  spielfeld[v1][z2]=spielfeld[v1][v2]; //erste Verschiebung zum Ziel Platz ist immer gültig
  spielfeld[v1][v2]=tmp1;
  tmp1=tmp2;
///eine for Schleife von mindestens 2 Dürchlaüfe ist zur weitere Verschiebung und nachprüfen,ob ein Kugel raus ist, ausreichend
  for(size_t i=1;i<=2;i++)
  {
    if(tmp1!=punkt)
    {
      if(z2-i>=1) ///den lenken Rand
        {
          tmp2=spielfeld[v1][z2-i];
          spielfeld[v1][z2-i]=tmp1;
          tmp1=tmp2;
        }else
            {
              if(tmp1==weisskugel)
                {
                  std::cout<<"weiss geworfen!\n";
                  schwarzscore+=1;
                }else
                    {
                      std::cout<<"schwarz geworfen!\n";
                      weisscore+=1;
                    }
               break;
             }
    }
  }
    wechselturn();
}
/**
*Die Methode 'nachUntenSchieben' hat die Aufgabe die Elemente in der selben Spalte vom Spielfeld nach Unten zu verschieben
*und prüft, ob ein Kugel aus dem unteren Rand geworfen wurde und erhöht das Ergibnis der Spieler anhand des geworfenen Kugel
*und ruft die Funktion 'wechselturn' zum ändern der boolschen Wert des Objektes.
*
*@var tmp1 dient zur Verschiebung durch der Spalte und ist mit der Eigenschaft des leeren Element immer intialisiert
*@var tmp2 dient zur Verschiebung durch der Spalte und zum Speichern der Wert vom nachstehenden Element  
*/
void spiel::nachUntenSchieben()
{
  std::string tmp1,tmp2;
  tmp1=punkt;
  tmp2=spielfeld[z1][v2];
  spielfeld[z1][v2]=spielfeld[v1][v2];//erste Verschiebung zum Ziel Platz ist immer gültig
  spielfeld[v1][v2]=tmp1;
  tmp1=tmp2;
//eine for Schleife von mindestens 2 Dürchlaüfe ist zur weitere Verschiebung und nachprüfen,ob ein Kugel raus ist, ausreichend
  for(size_t i=1;i<=2;i++)
  {
    if(tmp1!=punkt)
    {
      if(z1+i<=7)
        {
          tmp2=spielfeld[z1+i][v2];
          spielfeld[z1+i][v2]=tmp1;
          tmp1=tmp2;
        }else
            {
              if(tmp1==weisskugel)
                {
                  std::cout<<"Weiss geworfen!\n";
                  schwarzscore+=1;
                }else
                    {
                        std::cout<<"schwarz geworfen!\n";
                      weisscore+=1;
                    }
               break;
            }
     }
  }
    wechselturn();
}

/**
*Die Methode 'nachObenSchieben' hat die Aufgabe die Elemente in der selben Spalte vom Spielfeld nach Oben zu verschieben
*und prüft, ob ein Kugel aus dem oberen Rand geworfen wurde und erhöht das Ergibnis der Spieler anhand des geworfenen Kugel
*und ruft die Funktion 'wechselturn' zum ändern der boolschen Wert des Objektes.
*
*@var tmp1 dient zur Verschiebung durch der Spalte und ist mit der Eigenschaft des leeren Element immer intialisiert
*@var tmp2 dient zur Verschiebung durch der Spalte und zum Speichern der Wert vom nachstehenden Element  
*/
void spiel::nachObenSchieben()
{
 std::string tmp1,tmp2;
  tmp1=punkt;
  tmp2=spielfeld[z1][v2];
  spielfeld[z1][v2]=spielfeld[v1][v2];//erste Verschiebung zum Ziel Platz ist immer gültig
  spielfeld[v1][v2]=tmp1;
  tmp1=tmp2;
//eine for Schleife von mindestens 2 Dürchlaüfe ist zur weitere Verschiebung und nachprüfen,ob ein Kugel raus ist, ausreichend
  for(size_t i=1;i<=2;i++)
  {
    if(tmp1!=punkt)
    {
      if(z1-i>=1)
        {
          tmp2=spielfeld[z1-i][v2];
          spielfeld[z1-i][v2]=tmp1;
          tmp1=tmp2;
        }else
            {
              if(tmp1==weisskugel)
                {
                  std::cout<<"Weiss geworfen!\n";
                  schwarzscore+=1;
                }else
                    {
                      std::cout<<"schwarz geworfen!\n";
                      weisscore+=1;
                    }
               break;
             }
      }
  }
    wechselturn();
}

/**
*Die Methode 'spielSpeichern' dient zum Speichern das aktuelle Spiel in der Datei save.txt
*Es wird wer am Zug ist, Ergibnisse der Spieler und das Spielfeld abgespeichert
*@var speichern eingabestrom auf dem eingegeben werden soll
*/
void spiel::spielSpeichern()
{
    std::ofstream speichern("save.txt");
    if(!speichern)
    {
      std::cout<<"Datei laesst sich nich verbinden!\n";
    }else
      {
         speichern<<turn;  //in der ersten Zeile wird , wer am zug ist in der Datei abgespeichert
         speichern<<'\n';
   	 speichern<<weisscore;  //speichert das Ergibnis des weißen Spieler in der Datei
   	 speichern<<'\n';
    	 speichern<<schwarzscore; //speichert das Ergibnis des schwarzen Spieler in der Datei
  	for(unsigned int i=0;i<8;i++)    //eine for Schleife zum Speichern des Spielfeldes in der Datei
         {
            for(unsigned int k=0;k<9;k++)
                {
                    speichern<<'\n';
                    speichern<<spielfeld[i][k];
                }
         }
        std::cout<<"Spiel wurde gespeichert!\n";
      }
}
/**
*Die Methode 'spielWiederherstellen' lädt die Datei save.txt zum fortsetzten einem abgespeicherten Spiel
*und gibt das geladenen Spiel am Blidschirm aus.
*@var ruckgabe ausgabestrom auf dem ausgegeben werden soll.
*/
void spiel::spielWiederherstellen()
{ 
    std::ifstream ruckgabe("save.txt");
    ruckgabe>>turn;  //in der ersten Zeile wird , wer am zug ist aus der Datei in der Klasse zum objekt abgespeichert.
    ruckgabe>>weisscore;  //speichert das Ergibnis des weißen Spieler in der Klasse aus der Datei.
    ruckgabe>>schwarzscore;  //speichert das Ergibnis des schwarzen Spieler in der Klasse aus der Datei.

///eine for Schleife zum Speichern des Spielfeldes in der Klasse aus der Datei   
 for(unsigned int i=0;i<8;i++)  
        {
            for(unsigned int k=0;k<9;k++)
                {
                    if(i==0&k==0)
                    {
                        spielfeld[i][k]="  ";
                    }else
                       {
                       ruckgabe>>spielfeld[i][k];
                       }
                       if((i!=0) & (k==0))
                            {
                            spielfeld[i][k]+=" ";
                            }
                }
        }
  std::cout<<"vorherige Spiel wurde geladen!\n";
  print();
}
