# Užduotis_vidurkių_apskaičiaviumui
## Objektinio programavimo pirmoji užduotis

Programa nuskaito vartotojų įvedamus reikiamus duomenis arba nuskaito duomenis iš failo (struktūros elementai):

*Studento vardą ir pavardę;*
*Namų darbų ir egzamino rezultatą;*

Kiekvieno studento duomenys yra saugojami su vector, deque, list ir class.

Programoje galima pasirinkti pačiam įvesti mokinio gautus balus už namų darbus bei egzaminą arba juos sugeneruoti atsitiktinai ar nuskaityti iš failo.

Baigus duomenų įvedimą, galima pasirinkta ką išvesti su mokinio vardu ir pavarde. Ar galutinį balą, medianą ar juos abu kartu.

Galimas pasirinkimas išvesti į ekraną arba saugoti duomenis faile.

Sukurtos papildomos funkcijos, kurios paverčia mažasias raides didžiosiomis ir pasakančios ar įvestas simbolis yra skaičius, taip pagerinančios programos veikimą.

Galima pasirinkti sukurti failą su sugeneruotais šablonais (Vardas 1, Pavarde1...) arba su jau sugeneruotu failu atlikti veiksmus.

Tas failas yra surykiuojamas pagal vardą ir padalijamas į du vektorius, pagal studento vidurkį ir paskui atspauzdinami į atskirus failus.

Visų operacijų su sugeneruotu failu yra skaičiuojamas laikas ir atspauzdinams į ekraną.  

## Konteinerių palyginimas

### List

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: |
| 1000    | 0.008006 s   | 0.023993 s  | 0 s             | 0.008008 s       | 0.031998 s | 0.14845 s    |
| 10000   | 0.095515 s   | 0.229117 s  | 0.015982 s      | 0.016003 s       | 0.123235 s | 0.596497 s   |
| 100000  | 0.905934 s   | 2.89868 s   | 0.120007 s      | 0.143998 s       | 0.931028 s | 5.56415 s    |
| 1000000 | 10.6177 s    | 33.3427 s   | 0.957757 s      | 1.16004 s        | 9.79661 s  | 60.2546 s    |
| 10000000| 94.784 s     | 261.812 s   | 15.4049 s       | 15.0431 s        | 46.6084 s  | 491.497 s    |


### Deque

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: |
| 1000    | 0.00401 s    | 0.003918 s  | 0.000983 s      | 0.001004 s       | 0.015996 s | 0.034963 s   |
| 10000   | 0.025993 s   | 0.034001 s  | 0.005008 s      | 0.008994 s       | 0.071 s    | 0.20149 s    |
| 100000  | 0.232228 s   | 0.430722 s  | 0.046896 s      | 0.069617 s       | 0.778454 s | 1.98002 s    |
| 1000000 | 2.34324 s    | 5.81856 s   | 0.507304 s      | 0.684151 s       | 5.40436 s  | 18.8731 s    |
| 10000000| 27.3146 s    | 75.651 s    | 54.0988 s       | 64.0965 s        | 50.4134 s  | 491.823 s    |


### Vector

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

## Studentų rūšiavimo (dalijimo) į dvi kategorijas palyginimas

### List

| Dydis   | 1 Strategija  | 2 Strategija  |   
| :-----: | :-----------: | :-----------: |
| 1000    | 0.008008 s    | 0 s           |
| 10000   | 0.031985 s    | 0.010527 s    |
| 100000  | 0.264005 s    | 0.068562 s    |
| 1000000 | 2.117797 s    | 0.643927 s    |
| 10000000| 30.448  s     | 6.50695 s     |



### Deque

| Dydis   | 1 Strategija  | 2 Strategija  | 
| :-----: | :-----------: | :-----------: |
| 1000    | 0.001987 s    | 0.002 s       |
| 10000   | 0.014002 s    | 0.019997 s    |
| 100000  | 0.116513 s    | 0.173 s       |
| 1000000 | 1.191455 s    | 2.01967 s     |
| 10000000| 118.1953 s    | 175.637 s     |



### Vector

| Dydis   | 1 Strategija  | 2 Strategija  | 
| :-----: | :-----------: | :-----------: |
| 1000    | 0.000996 s    | 0 s           |
| 10000   | 0.007289 s    | 0.016004 s    |
| 100000  | 0.040997 s    | 0.127964 s    |
| 1000000 | 0.375968 s    | 1.072 s       |
| 10000000| 5.83583  s    | 14.6001 s     |

## Class ir Struct palyginimas

### 100000 Vector

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas | Visas Laikas su -O1 | Visas Laikas su -O2 | Visas Laikas su -O3 |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: | :-----------------: | :-----------------: | :-----------------: |
| Struct  | 0.248125 s   | 0.179567 s  | 0.018009 s      | 0.022988 s       | 0.56943 s  | 1.17479 s    | 0.83338 s           | 0.774122 s          | 0.904723 s          |
| Class   | 0.265108 s   | 0.231634 s  | 0.017001 s      | 0.023989 s       | 0.578866 s | 1.26268 s    | 0.93736 s           | 0.890504 s          | 1.0453 s            |

### 1000000 Vector

| Dydis   | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas | Visas Laikas su -O1 | Visas Laikas su -O2 | Visas Laikas su -O3 |
| :-----: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: | :-----------------: | :-----------------: | :-----------------: |
| Struct  | 2.44138 s    | 2.338 s     | 0.141542 s      | 0.234426 s       | 5.47496 s  | 11.7498 s    | 8.20266 s           | 8.82027 s           | 9.67858 s           |
| Class   | 2.66262 s    | 3.05908 s   | 0.144465 s      | 0.267374 s       | 5.80229 s  | 13.0283 s    | 10.9506 s           | 10.662 s            | 10.3665 s           |


## MyVector

### funkcijos

#### Capacity
* Default-constructed capacity is 0
* Capacity of a 100-element vector is 100
* Capacity after resize(50) is 100
* Capacity after shrink_to_fit() is 50
* Capacity after adding 300 elements is 512
* Capacity after shrink_to_fit() is 300

### Spartos analize

| Dydis   | std::vector   |   MyVector    | 
| :-----: | :-----------: | :-----------: |
| 10000   | 0 s           | 0.001942 s    |
| 100000  | 0.000991 s    | 0.000994 s    |
| 1000000 | 0.03134 s     | 0.045002 s    |
| 10000000| 0.221757 s    | 0.342043 s    |
|100000000| 1.43557 s     | 2.52124 s     |

### capacity() == size()

| Dydis   | std::vector   |   MyVector    |
| :-----: | :-----------: | :-----------: |
|100000000|      27       |       27      |

### v2.0 programos veikimo lyginimas

|   100000  | Nuskaitymas  | Rykiavimas  | Var. į vectorių | Gal. į vectorių  | Išvedimas  | Visas Laikas |
| :-------: | :----------: | :---------: | :-------------: | :--------------: | :--------: | :----------: |
|std::vector| 0.248125 s   | 0.179567 s  | 0.018009 s      | 0.022988 s       | 0.56943 s  | 1.17479 s    |
| MyVector  | 0.328997 s   | 0.503985 s  | 0.056997 s      | 0.078014 s       | 0.613983 s | 1.88006 s    |

