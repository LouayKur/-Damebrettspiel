#include <iostream>
#include"spiel.hpp"
#include<string>

/**
*Die Klasse InvalidInfOrmation dient zur Erstellung der Objekte , die zur Fehler Werfen benötigen.
*/
class InvalidInfOrmation{};

unsigned int vertikal(spiel &spielfeld);
unsigned int horizontal_vertikal(spiel &spielfeld);
void syntax_2(std::string temp,unsigned int v1,unsigned int z1,spiel &spielfeld);
void syntax_1(std::string temp,spiel &spielfeld);
unsigned int horizontal_vertikal(spiel &spielfeld);
unsigned int nachLenks(spiel &spielfeld);
/**
*Die Funktion syntax_1 prüft, ob die Zeilen Buchstaben stimmen und speichert die index der Zeilen des Zuges.
*und ruft die Funktion 'syntax_2' zur prüfung der Spalten mit der resten eingabe.
*
*@param temp ist die eingabe von Benutzern.
*@param spielfeld ist ein Objekt von der Klasse spiel.
* 
*@var x wandelt die Buchstabe in ascii code.
*@var v1 speichert von welche Zeile der gewünschte Zug ist.
*@var z1 speichert zu welche Zeile der gewünschte Zug ist. 
*@pre temp.size()<=4 nicht ausreichende Eingabe.
*/
void syntax_1(std::string temp,spiel &spielfeld)
{
  unsigned int x,v1,z1;
  v1=0;
  z1=0;  //intialisierung der Variablen.
  x=0;
    if(temp.size()<=4 )  ///ungueltige Eingabe kleine gleich 4 Buchstaben.
	{
	 std::cout<<"Bitte waehlen Sie eine Zeile von 'A' bis 'G' und eine Spalte von '1' bis '8' Z.B:'A1 A2'";
	  throw InvalidInfOrmation();
	}  	
    for(size_t i=0;i<temp.size();i++ )
        {
            x=static_cast<unsigned int>(temp[i]);
            if(i==0 || i==3)
                {
                    if((65<=x)&&(x<=71)) //ascii code für die Buchstaben von A bis G.
                        {
                            if(i==0)
                             {
                               v1=static_cast<unsigned int>(x-64);
                             }else
                               {
                                 z1=static_cast<unsigned int>(x-64);
                               }
                        }else
                          {
                            std::cout<<"waehlen Sie bitte eine zeile von 'A' bis 'G' aus.";
                            throw InvalidInfOrmation();
                          }
                }else if(i>3)  //die Zeilen Buchstaben wurden geprüft
		     {
			syntax_2(temp,v1,z1,spielfeld);
		     }			
        }
}
/**
*Die Funktion syntax_2 prüft, ob die Spalten Nummern stimmen und speichert die index der Spalten des Zuges 
*und weist der Zug Daten zur Eigenschaften des Objektes der Klasse Spielfeld.
*
*@param temp ist die eingabe von Benutzern.
*@param spielfeld ist ein Objekt von der Klasse spiel.
*@param v1 speichert von welche Zeile ist die gewünschte Zug.
*@param z1 speichert zu welche Zeile ist die gewünschte Zug.
*
*@var x wandelt die Buchstabe in ascii code.
*@var v2 speichert von welcher Spalte der gewünschte Zug ist.
*@var zu speichert zu welcher Spalte der gewünschte Zug ist.
*/
void syntax_2(std::string temp,unsigned int v1,unsigned int z1,spiel &spielfeld)
{
  unsigned int x,v2,z2;
  v2=0;
  z2=0;  //intialisierung der Variablen. 
  x=0;
  for(size_t i=0;i<temp.size();i++ )
    {
      x=static_cast<unsigned int>(temp[i]);
      if(i==1 || i==4)
        {
          if((49<=x)&(x<=56))  //ascii code von 1 bis 8
            {
               if(i==1)
                 {
                   v2=static_cast<unsigned int>(x-48);
                 }else
                      {
                        z2=static_cast<unsigned int>(x-48);
                      }
            }else
                 {
                    std::cout<<"waehlen Sie bitte eine Spalte von '1' bis '8' aus.";
                    throw InvalidInfOrmation();
                 }
        }else if((i!=0) && (i!=3))
               {
                 if(temp[i]!=' ')
                   {
                     std::cout<<"Es sollte ein leerzeichen zwischen den zuege geben und nichts nach dem Zug.";
                     throw InvalidInfOrmation();
                    }
                }
    }
   spielfeld.set_zug(v1,v2,z1,z2); ///den Zug in der Klasse abspeichern.
}
/**
*Die Funktion horizontal_vertikal prüft, ob die Verschiebung durch die Zeile gültig ist und ruft die entsprechende
*Methode des Objktes 'spielfeld' auf oder die Funktion 'vertikal' für die Prüfung der Verschiebung durch die Spalte
*@param spielfeld ein Objekt der Klasse 'spiel' und dient zur Prüfung der Zug Daten
*@return weist eine vordifinierte positive Zahl zur feststellung der Richtung anhand der entsprechende Methode der Klasse  
*/
unsigned int horizontal_vertikal(spiel &spielfeld)
{
    if(spielfeld.getv1()==spielfeld.getz1())  //Prüfung der Zeilen index
        {
            if(spielfeld.getv2()==spielfeld.getz2())  //Prüfung der Spalten index
                {
                   std::cout<<"Die kugel kann nicht zum gleichen Feld bewegt werden.";
                   throw InvalidInfOrmation();
                }else if(spielfeld.getv2()==spielfeld.getz2()+1)  //prüft,ob die Verschiebung um eine Stelle nach Links
                     {
                        return nachLenks(spielfeld);
                     }else if(spielfeld.getz2()==spielfeld.getv2()+1) //prüft,ob die Verschiebung um eine Stelle nach Rechts
                                {
				   return spielfeld.nachRechts();
                                }else
                  		   {
 				     std::cout<<"Sie können die Kugel nur um eine Stelle verschieben.";
                                     throw InvalidInfOrmation();                     
                         	   }
        }else if(spielfeld.getv2()==spielfeld.getz2())
          {
            return vertikal(spielfeld);
          }else
             {
	       std::cout<<"Sie können die Kugel nur um eine Stelle verschieben.";	
               throw InvalidInfOrmation(); 	
             }
}
/**
*Die Funktion vertikal prüft, ob die Verschiebung durch die Spalte gültig ist und ruft die entsprechende
*Methode des Objktes auf  
*@param spielfeld ein Objekt der Klasse 'spiel' und dient zur Prüfung der Zug Daten
*@return weist eine vordifinierte positive Zahl zur feststellung der Richtung anhand der entsprechende Methode der Klasse
*/
unsigned int vertikal(spiel &spielfeld)
{
    if(spielfeld.getv1()==spielfeld.getz1()+1)  //prüft,ob die Verschiebung um eine Stelle nach Oben
       {
          return spielfeld.nachOben();
       }else if(spielfeld.getz1()==spielfeld.getv1()+1) //Verschiebung um eine Stelle nach Unten
	       {
	         return spielfeld.nachUnten();
               }else
                   {
	      	      std::cout<<"Sie können die Kugel nur um eine Stelle verschieben.";
                      throw InvalidInfOrmation();
                   }
}

/**
*das **Hauptprogramm 'main'** 
*erstellt ein Objekt von der Typ spiel und gibt das Spielfeld ans Bildschrim aus
*und verlangt die Eingabe des Zuges von den Spielern . die Einagbe wird anhand entsprechende Funktionen und Methoden 
*der Klasse geprüft 
*bei richtiger Eingabe wird die entsprechende Methode der Klasse für die Durchführung der Verschiebung aufgerufen.
*bei Eingabe von 'S' wird das aktuelle Spiel anhand eine Methode der Klasse abgespeichert werden.
*bei Eingabe von 'L' wird das abgespeicherte Spiel für die fortsetztung geladen.
*hat ein Spieler 5 Kugeln verloren, wird der gegenSpieler gewinnen und wird das Spiel beendet.
*@var spielfeld ein Objekt der Klasse 'spiel' mit der bezeichnung der Kugeln und leeres Platz
*@var tmp speichert die Eingabe des Spielers ab 
*@var ziel speichert die Ruckgabewert von der Funktion 'horizontal_vertikal' und 
*dient zur Unterscheidung, in welcher Richtung die Verschiebung durchgeführt werden muss  
*/
int main()
{
 ///Erstellung ein Objekt von typ spiel.
  spiel spielfeld("W","S","."); 
  ///Das Spielfeld ans Bildschirm ausgeben.
   spielfeld.print();
    std::string tmp;
    unsigned int ziel;
    while(std::cin)
    {
        std::getline(std::cin,tmp);
        if(tmp=="S")
            {
              spielfeld.spielSpeichern();
            }else if(tmp=="L")
              {
                spielfeld.spielWiederherstellen();
              }else
                  {
                    try
                      {
                        syntax_1(tmp,spielfeld);//prüft die Einagbe syntaktisch und speichert den Zug in der Klasse
			tmp="";  ///Die Einagabe leeren.
                        ziel=horizontal_vertikal(spielfeld);//prüft,ob die Verschiebung gültig ist  
                        switch(ziel)
                             {
                                case 0:  //Die Verschiebung soll nach Rechts dürchgeführt werden
                                  {
                                    spielfeld.nachRechtsSchieben();
                                    spielfeld.print();
                                  }break;
                                case 1:   //Die Verschiebung soll nach Lenks dürchgeführt werden
                                  {
                                    spielfeld.nachLenksSchieben();
                                    spielfeld.print();
                                  }break;
                                case 2:  //Die Verschiebung soll nach Oben dürchgeführt werden
                                  {
                                     spielfeld.nachObenSchieben();
                                     spielfeld.print();
                                  }break;
                                case 3:  //Die Verschiebung soll nach Unten dürchgeführt werden
                                  {
                                    spielfeld.nachUntenSchieben();
                                    spielfeld.print();
                                  }break;
                             }
                            if(spielfeld.get_weisscore()==5)  //Prüfung, ob ein Spieler gewonnen hat 
                               {
                                  std::cout<<"\t weiss gewinnt\n";
                                   break;
                               }else if(spielfeld.get_schwarzscore()==5)
                                    {
                                       std::cout<<"\t Schwarz gewinnt\n";
                                       break;
                                    }
                       }catch(InvalidInfOrmation)  //bei einen flaschen Zug wird neue Eingabe verlangt
                           {
                             std::cout<<"\nBite geben Sie nochmal einen Zug ein: "<<'\n';
                           }
              }
    }
}

/**
*Die Funktion nachLenks hat die Aufgabe ab dem Element des gewünschten Zug des Spielfelds bis zu lenken Rand zum prüfen,
*ob das element des Feldes ein Kugel ist
*und zählt wie viele Kugeln in dieser Richtung gibt und wie viele Kugeln gerade nach die eigene Kugel stehen.
*
*@param spielfeld ein Objekt der Klasse spiel und hat alle notwindige Eigenschaften des Spiels.
*
*@var eintrag speichert das element des Feldes ab.
*@var kugelzahl zählt wie viele Kugeln in dieser richtung gibt.
*@var stapel zählt wie viele Kugeln in dieser Richtung gerade nach dem eigenen Kugel stehen.
*@return ruft die Methode gueltigkeit auf und liefert ihr die Ergibnisse mit der vordefinierten Richtung '1'.
*'1=gewünschte Verschiebung nach Links' 
*/
unsigned int nachLenks(spiel &spielfeld)
{
  std::string eintrag;
  unsigned int kugelzahl=0;
  unsigned int stapel=0;
  ///speichert das element des Feldes ab.
  eintrag=spielfeld.get_element(spielfeld.getv1(),spielfeld.getv2());
  if((eintrag==spielfeld.get_weisskugel())||(eintrag==spielfeld.get_schwarzkugel()))
    {
    ///eine for schleife läuft ab dem Element des Feldes in der selben Zeile bis zum lenken Rand  
      for(unsigned int i=spielfeld.getv2();i>=1;i--)  
        {
          if(spielfeld.get_element(spielfeld.getv1(),i)!=spielfeld.get_punkt())
            {
              kugelzahl+=1;
            }
        }
        for(unsigned int i=spielfeld.getv2();i>=1;i--) // eine for schleife zum zählen die Kugeln nach dem eigenen Kugel.
          {
            if(spielfeld.get_element(spielfeld.getv1(),i)!=spielfeld.get_punkt())
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
  return spielfeld.gueltigkeit(eintrag,kugelzahl,stapel,1);     
}
