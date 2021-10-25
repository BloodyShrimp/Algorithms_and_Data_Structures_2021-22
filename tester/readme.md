---
title:	Tester rozwiązań do zajęć z Algorytmów i struktur danych FAIS UJ 2020
author:	Andrzej Görlich
date:	17.01.2021
---

## Wymagania

Wymagany system operacyjny Linux (w tym WSL) lub kompatybilny (np. `Msys2`),
powłoka `bash` i interpreter **Lua** w wersji 5.4.

## Testowanie zestawu

Kod źródłowy, razem z plikiem `Makefile`, należy przekopiować do odpowiedniego katalogu `Zestaw##`  w **bieżacym katalogu**, np. `Zestaw01`.
Następnie należy ruchomić tester dla odpowiedniego zestawu, np.

```bash
./test_Zestaw01.sh
```

Tester automatycznie kompiluje rozwiązanie na podstawie pliku `Makefile` w katalogu `Zestaw01`,
sprawdza czy kompilacja zakończyła się powodzeniem i czy niezbędne pliki wykonywalne istnieją.
Jeżeli tak, porównywane są wyniki działania programów z wynikami wzorcowymi.
