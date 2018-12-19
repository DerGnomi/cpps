struct T_Artikel{ # Deklaration Struktur
  string Bez;
  double Preis;
};

T_Artikel *pA1=NULL; #Definition Pointer
pA1 = new T_Artikel; #Speicher Anfordern
(*pA1).Preis = 2.5;    #Zugriff () -> Dereferenzieren
pA1->Preis=2.5;        #Optional für Zugriff

pA1 = new T_Artikel [5]; #Speicher anfordern für ein Array
pA1[x].Preis = 2.5;      #Zugriff Arrayschreibweise
(*(pA1+x)).Preis = 2.5;    #Pointerschreibweise
(pA1+x)->Preis=2.5;        #Pointerschreibweise

delete pA1;   #Speicherfreigeben
pA1=NULL;     #Pointer auf Null setzen
