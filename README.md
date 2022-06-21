# Projekt z Narzędzi Komputerowych

Projekt realizuje zadanie o następującej tematyce:
```
Narysowałaś mapę najkrótszych połączeń Twojego domu z domami kolegów. Wyszło z
tego drzewo, którego korzeniem jest Twój dom, a wierzchołkami ich domy. Na czerwono
pomalowałaś wierzchołki będące domami ulubionych kolegów. Myślisz sobie, że byłoby jednak
dobrze, uniknąć przypadkowych niepożądanych spotkań po drodze. Napisz algorytm, który
sprawdzi czy na drogach z korzenia do czerwonych wierzchołków nie ma innych czerwonych
wierzchołków.
```

## Kompilacja
Możliwe sposoby kompilacji
- Make
- gcc
- mingw 


## Instrukcja obsługi
Program przyjmuje dane wejściowe w postaci pliku txt podanego jako argument.
Przykładowa struktura znajduje się w plikach graph.txt, oraz graph2.txt
Budowa pliku:
```
V <liczba wierzchołków grafu>
E <liczba krawędzi grafu>
R <liczba wybranych (czerwonych) wierzchołków grafu>
<R lini zawierających numery wyróżnionych wierzchołków>
<E lini z numerami dwóch wierzchołków tworzących krawędź>
```

## Uruchomienie
Z poziomu wiersza poleceń poprzez komendę
```
./main.exe graph.txt
```

## Dane wyjściowe
```
Opening file: graph.txt                 << plik wejściowy
Number of vertices read: 8             \
Number of edges read: 7                | liczba wierzchołków, krawędzi grafu, oraz czerwone wierzchołki
Number of red vertices: 3              /
Red vertices read
Vertex: 1, iter: 0          \
        2       5       7    \
Vertex: 2, iter: 0            \
        1       3       4     |
Vertex: 3, iter: 0            |
        2                     |
Vertex: 4, iter: 0            | Struktura grafu wejściowego
        2                     | Vertex: numer wierzchołka
Vertex: 5, iter: 0            | iter: odległośc od korzenia (wszędzie jest 0 ponieważ graf nie został jeszcze przeszukany - stan wejściowy)
        1       6             | Ponizej kazdego wierzchołka znajdują się numery wierzchołków sąsiadujących z danym węzłem
Vertex: 6, iter: 0            |
        5                     |
Vertex: 7, iter: 0            |
        1       8             /
Vertex: 8, iter: 0           /
        7                   /
Given tree does not contain more than one red vertex on the same path. Success!     << wynik działana programu czyli odpowiedź czy na drogach z korzenia do czerwonych wierzchołków nie ma innych czerwonych wierzchołków
Vertex: 1, iter: 0              \\ V // Ponownie struktura grafu lecz z zaktualizowaną wartością "iter:"
        2       5       7        \\ //
Vertex: 2, iter: 1
        1       3       4
Vertex: 3, iter: 2
        2
Vertex: 4, iter: 2
        2
Vertex: 5, iter: 1
        1       6
Vertex: 6, iter: 2
        5
Vertex: 7, iter: 1
        1       8
Vertex: 8, iter: 2
        7
```
