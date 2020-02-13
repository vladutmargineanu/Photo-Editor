# Photo-Editor
Homework for the Computer Programming course @ ACS, UPB 2019

# Algorithm

 Pentru citirea a N*M triplete si executarea a N*M pasi, folosim o instructiune repetitiva for, la sfarsitul careia afisam fiecare triplet (H', S', V') obținut în urma transformării.
 Citim tripletul (R, G, B) pentru fiecare pixel in instructiunea repetitiva for si il transformam in tripletul analog (H, S, V) normat, astfel: 
 1) Aflam maximul dintre (R1, G1, B1).
 2) Aflam minimul dintre (R1, G1, B1).
 3) Aflam valoarea variabilei delta.
 4) Aflam valoriile H (Hue) , S (Saturation), V (Value) dupa functiile
 date.
 5) Selectam caracteristica 'c' si o modificam, pentru fiecare pixel cu
 factorul de modificare a caracteristicii.
 6) Verificam daca valoriile V, S, H au depasit intervalul [0,1] si le
 modificam dupa caz.
