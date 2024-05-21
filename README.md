## TASK 1 - servere.cpp

Programul citește puterile și limitele serverelor dintr-un fișier și calculează pasul minim de alimentare pentru a menține serverele în limitele acceptabile.

* calculate_power: Calculează noua putere a unui server ajustând-o cu diferența dintre pasul de alimentare și limita serverului.
* get_alimentation_step: Determină pasul de alimentare necesar folosind serverul cu suma minimă dintre putere și limită și serverul cu cea mai mare diferență dintre acestea. Pasul este media ajustărilor necesare.
* Logica principală: Codul determină pasul de alimentare folosind serverele cu extreme în sume și diferențe ale valorilor putere și limită. Află pasul de alimentare care permite ajustarea tuturor serverelor la nivelurile lor optime.

Complexitate timp:    O(n)
Complexitate spatiu:  O(n)

## TASK 2 - colorare.cpp

Programul calculează rezultatele colorării zonelor, citind tipurile și numerele acestora dintr-un fișier, și aplică formule specifice pentru a determina numărul final de configurații posibile.

- modular_pow: Functia calculează puterea modulară a unei baze, utilizată pentru a evita supraîncărcarea numerelor mari în calcule.

- Logica principală: Începe cu stabilirea unui rezultat inițial bazat pe primul tip de zonă și ajustează acest rezultat pentru fiecare zonă următoare, folosind reguli specifice de tranzitie între tipurile de zone (H sau V). Rezultatul final este numărul de configurații posibile, modulo 1000000007.

- Funcționare: Prin citirea tipurilor și numărului fiecărei zone, programul determină impactul fiecărei zone asupra configurațiilor posibile, ajustând rezultatul pe baza relațiilor dintre zonele consecutive și aplicând puterea modulară pentru calcule precise și eficiente.

Complexitate timp:    O(nlog(x)) unde x este maximul dintre perechi
COmplexitate spatiu:  O(n) deoarece perechile sunt stocate in doi vectori de lungime N + 1

## TASK 3 - compresie.cpp

Programul verifică compresibilitatea a două secvențe de numere, comparând sumele lor parțiale pentru a identifica segmente comune.

- vector_sum: Calculează suma tuturor elementelor unui vector.

- Logica principală: După citirea și stocarea datelor din două secvențe, se calculează sumele parțiale pentru fiecare secvență. Dacă sumele totale ale secvențelor sunt diferite, se returnează -1, indicând că nu se pot compresa similar. Dacă sumele sunt egale, programul continuă prin căutarea sumelor parțiale comune între cele două secvențe.

- Funcționare: Verifică dacă există segmente de sumă egală între cele două secvențe folosind o metodă de căutare binară, care eficientizează procesul de comparare. În final, numărul de segmente comune este afișat.

Complexitate timp:    O(nlog(m))
Complexitate spatiu:  O(n + m)

## TASK 4 - oferta.cpp

Programul calculează costul minim al achiziționării unei serii de produse, aplicând reduceri specifice în funcție de numărul de produse cumpărate consecutiv.

- min_of_three: Returnează minimul dintre trei valori, util pentru calculul costurilor cu reduceri.

- Logica principală: Se citește numărul de produse și se verifică dacă condiția specifică (K=1) este îndeplinită. Dacă nu, programul se încheie prematur. Dacă da, se procedează la calculul costului minim al achiziției fiecărui produs, luând în considerare reducerile posibile când se achiziționează mai multe produse simultan.

- Funcționare: Calculează costul acumulat folosind trei strategii de reducere pentru fiecare produs începând cu al treilea:
  1. Cumpărarea produsului curent fără reducere.
  2. Cumpărarea produsului curent și a celui precedent cu o reducere de 50% pentru produsul mai ieftin dintre ele.
  3. Cumpărarea a trei produse consecutive cu prețul total redus cu valoarea celui mai ieftin produs.

Rezultatul final este costul total minim pentru achiziționarea tuturor produselor și este scris în fișierul de ieșire cu o precizie de un decim.

Complexitate timp:    O(n)
Complexitate spatiu:  O(n)
