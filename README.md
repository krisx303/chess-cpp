# chess-cpp
Projest of chess created in cpp and SFML (for simple GUI)

## Krzysztof Usnarski

## About
Na początku projekt miał być silnikiem do szybkiego i łatwego tworzenia gier szacho-podobnych (np. shogi). Jednak koniec końców powstały zwykłe szachy (w wersji beta).
Projekt korzysta z zewnętrznej bilbioteki SFML do tworzenia GUI.

## Struktura projektu
* U podstaw szachów znajdują się takie elementy jak abstrakcyjna klasa Pionka (Pawn), abstrakcyjna klasa Panel do zarządzania aktualnie aktywnym oknem i jego stanem.
* Klasa Generator i jej klasy potomne odpowiadają za generowanie w procesie iteracyjnym wszystkich możliwych ruchów/ataków danego rodzaju pionka.
* Klasa Panel dostarcza wszystkie niezbędne funkcje do przechwycenia wejścia z klawiatury/myszki jak i również miejsce na implementacje zachowania/renderowania okna w każdej następnej klatce.
* Klasa Board odpowiada za trzymywanie informacji o aktualnym stanie planszy.

## Informacje dotyczące wersji beta
Ponieważ projekt nadal jest w wersji beta, gra nie zawiera wszystkich możliwych przypadków oraz szczególnych ruchów jak roszada wieży z królem.

## Jak grać?
Zaczynają białe pionki (no co ty nie powiesz ;))
Po naciśnięciu i przytrzymaniu danego pionka ukażą nam się na planszy wszystkie możliwe ruchy tego pionka.
Aby pionek się poruszył należy przeciągnąć go (nadal trzymając LPP) na wybrane pole.
W przypadku gdy ruch pionka powoduje zaistnienie/podtrzymanie szacha na twoim królu, ruch ten zostaje cofnięty a w konsoli wyswietla się odpowiedni komunikat.
Gdy sytuacja powtórzy się 4 razy, gra zostaje przerwana (zwyciężył drugi z graczy).

![chess-main](https://github.com/krisx303/chess-cpp/assets/57154118/80e0dec9-9a64-4b8f-8f81-1c8162f899cc)
![chess-move](https://github.com/krisx303/chess-cpp/assets/57154118/cc517f5a-0e93-4f51-9813-d9a5e8be9b0f)
