# Užduotis_vidurkių_apskaičiaviumui
## Objektinio programavimo pirmoji užduotis

Programa nuskaito vartotojų įvedamus reikiamus duomenis arba nuskaito duomenis iš failo (struktūros elementai):

*Studento vardą ir pavardę;*
*Namų darbų ir egzamino rezultatą;*

Kiekvieno studento duomenys yra saugojami su vektoriumi.

Programoje galima pasirinkti pačiam įvesti mokinio gautus balus už namų darbus bei egzaminą arba juos sugeneruoti atsitiktinai.

Baigus duomenų įvedimą, galima pasirinkta ką isvesti su mokinio vardu ir pavarde. Ar galutinį balą, medianą ar juos abu kartu.

Galimas pasirinkimas išvesti į ekraną arba saugoti duomenis faile.

Sukurtos papildomos funkcijos, kurios paverčia mažasias raides didžiosiomis ir pasakančios ar įvestas simbolis yra skaičius, taip pagerinančios programos veikimą.

Galima pasirinkti sukurti failą su sugeneruotais šablonais (Vardas 1, Pavarde1...) arba su jau sugeneruotu failu atlikti veiksmus.

Tas failas yra surykiuojamas pagal vardą ir padalijamas į du vektorius, pagal studento vidurkį ir paskui atspauzdinami į atskirus failus.

Visų operacijų su sugeneruotu failu yra skaičiuojamas laikas ir atspauzdinams į ekraną.  


## List

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: |
| 1000    | 0.008006 s   | 0.023993 s  | 0 s             | 0.008008 s       | 0.031998 s | 0.14845 s    |
| 10000   | 0.095515 s   | 0.229117 s  | 0.015982 s      | 0.016003 s       | 0.123235 s | 0.596497 s   |
| 100000  | 0.905934 s   | 2.89868 s   | 0.120007 s      | 0.143998 s       | 0.931028 s | 5.56415 s    |
| 1000000 | 10.6177 s    | 33.3427 s   | 0.957757 s      | 1.16004 s        | 9.79661 s  | 60.2546 s    |
| 10000000| 94.784 s     | 261.812 s   | 15.4049 s       | 15.0431 s        | 46.6084 s  | 491.497 s    |


## Deque

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: |
| 1000    | 0.00401 s    | 0.003918 s  | 0.000983 s      | 0.001004 s       | 0.015996 s | 0.034963 s   |
| 10000   | 0.025993 s   | 0.034001 s  | 0.005008 s      | 0.008994 s       | 0.071 s    | 0.20149 s    |
| 100000  | 0.232228 s   | 0.430722 s  | 0.046896 s      | 0.069617 s       | 0.778454 s | 1.98002 s    |
| 1000000 | 2.34324 s    | 5.81856 s   | 0.507304 s      | 0.684151 s       | 5.40436 s  | 18.8731 s    |
| 10000000| 27.3146 s    | 75.651 s    | 54.0988 s       | 64.0965 s        | 50.4134 s  | 491.823 s    |


## Vector

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: |
| 1000    | 0.004444 s   | 0.001994 s  | 0 s             | 0.000996 s       | 0.007998 s | 0.019446 s   |
| 10000   | 0.028996 s   | 0.019011 s  | 0.00302 s       | 0.004269 s       | 0.069998 s | 0.149881 s   |
| 100000  | 0.248125 s   | 0.179567 s  | 0.018009 s      | 0.022988 s       | 0.56943 s  | 1.17479 s    |
| 1000000 | 2.44138 s    | 2.338 s     | 0.141542 s      | 0.234426 s       | 5.47496 s  | 11.7498 s    |
| 10000000| 25.1603 s    | 28.2908 s   | 2.68412 s       | 3.15171 s        | 43.4153 s  | 114.673 s    |

### Kompiuterio parametrai

Processor	AMD Ryzen 5 3500U with Radeon Vega Mobile Gfx, 2100 Mhz, 4 Core(s), 8 Logical
RAM	8.00 GB 
SSD 512 GB

