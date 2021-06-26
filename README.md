Pour compiler le code source, il faut faire un `make exe` dans le dossier "programme".
Une fois compilé, vous pouvez utiliser notre compresseur en entrant les lignes de commande suivantes dans un terminal (il faut être dans le dossier bin/) :
* compression : `./huffman c nomFichier.txt`
* décompression : `./huffman d nomFichier.huff`

Pour compiler le code source des tests, il faut faire un `make tests` dans le dossier "programme".
Une fois compilé, vous pouvez lancer les tests en entrant les lignes de commande suivantes dans un terminal (il faut être dans le dossier tests/) :
* `./tests`

Pour générer la documentation, il faut faire un `make doc` dans le dossier "programme". La version pdf est le fichier "doc/ArbreHuffman.pdf". La version html est le fichier "doc/html/index.html".

L'instruction `make all` génère l'exécutable, les tests et la doc automatiquement.

Pour obtenir le pdf de notre rapport, il suffit de faire un `make` dans le dossier rapport.
