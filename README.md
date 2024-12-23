# Additional-program

# Programos aprašymas

**Programos tikslas:** suskaičiuoti žodžių pasikartojimo dažnį.
**Papildomi veiksmai:** 
* vartotojui suteikia galimybę sužinoti, kurioje eilutėje yra pasikartojantis tekstas
* vartotojui išmeta visus tekste esančius URL. Nesvarbu ar URL yra pilnas ```http://www.vu.lt``` ar sutrumpintas ```www.vu.lt```

# Programos failų aprašymai
### Header failai
* MyLib.h - faile deklaruotos visos programoje naudojamos bibliotekos.
* Methods.h - faile aprašyta Info clasė, ir deklaruoti pagrindiniai programoje naudojami metodai.

### .cpp Failai
* Main.cpp -  pagrindinis programos failas, kuris inicijuoja ir vykdo pagrindinę programos logiką.
* Functions.cpp - faile įgyvendinti visi metodai, naudojami programoje, susiję su teksto apdorojimu.
* Files.cpp - faile aprašyti metodai, skirti failų nuskaitymui ir informacijos išrašymui į rezultatų failą.

# Programos įgyventinimo logika

* Pirmiausia nuskaitomas tekstas iš .txt failo. 
* Naudojama ```findUrl``` funkcija, kuri remiasi iš Domain.txt sudarytą set, kad išrinktu visus tekste esančius URL ir juos išvestų į terminalą.
* Pašalinami visi skirybos ženklai ir visos raidės paverčiamos mažosiomis naudojant ```textCleaning``` funkcija.
* Skaičiuojami visi pasikartojantys žodžiai naudojant asociatyvų konteinerį **map**.
    * Kiekvienas Map - Key yra iš teksto išrinktas pasikartojantis žodis
    * Tikrinama ar iš teksto eilutės paduotas žodis egzistuoja konteineryje ar ne
    * Jeigu egzistuoja padidinamas žodžio pasikartojimo skaičius, jeigu ne tada naujas žodis įrašomas į konteinerį
* Programa baigiasi visą Map konteinerio informaciją išrašant į rezultatų failą.
