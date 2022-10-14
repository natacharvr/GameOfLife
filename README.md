# GameOfLife
Game of life en c

règles :
si une cellule est vivante, elle le reste si elle a 2 ou 3 voisins vivants
si une cellule n'est pas vivante, elle prend vie si elle a 3 voisins vivants
fonction d'affichage
fonction de calcul de nb de voisins
tableau une dimension de taille l*larg, de 0 à l-1 c'est la première ligne, de l à l+l c'est la largème ligne
chaque cellule est un tableau de taille 2 [1|0, nbVoisins]
monde torique
les voisins d'une cellule sont ceux qui la touchent horizontalement, verticalement et en diagonale
les voisins d'une celulle de position PosI,PosJ dans un espace de dimension haut*larg sont:
a) ((PosJ - 1) % larg) * larg + (PosI - 1) % haut (diagonale haute gauche)
b) ((PosJ - 1) % larg) * larg + PosI (au dessus)
c) ((PosJ - 1) % larg) * larg + (PosI + 1) % haut (diagonale haute droite)
d) (PosI - 1) % haut + PosJ * larg (gauche horizontal)
f) (PosI + 1) % haut + PosJ * larg (droite horizontal)
g) ((PosJ + 1) % larg) * larg + (PosI - 1) % haut (diagonale basse gauche)
h) ((PosJ + 1) % larg) * larg + PosI (au dessous)
i) ((PosJ + 1) % larg) * larg + (PosI + 1) % haut (diagonale basse droite)

a  b  c
d  e  f
g  h  i
■ pour une cellule en vie
□ pour une cellule morte
