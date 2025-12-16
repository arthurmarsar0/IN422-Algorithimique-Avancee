from dijkstra import *
from gv_valence import gv_valence, ID_ESISAR, ID_GARE

def test_longueur_chemin():
    assert longueur_chemin(exemple1, "afe")==23
    assert longueur_chemin(exemple1, "acde")==26
    assert longueur_chemin(exemple1, "a")==0
    assert longueur_chemin(exemple1, "ae")==INFINI
    print("Test done")
    
# def test_dijkstra():
#     d, p = dijkstra("a", exemple1)
#     assert d == {'a': 0, 'b': 7, 'c': 9, 'd': 20, 'e': 20, 'f': 11}

# def test_dijkstra_optimise():
#     pass
    
# def test_diametre():
#     pass

# def test_valence():
#     gv, labels = gv_valence()
#     d,p = dijkstra(gv, ID_ESISAR)
#     print(f"La longeur d'un plus court chemin jusqu'à la gare est {d[ID_GARE]} m.")
#     id_courant = ID_GARE
#     iti = []
#     while id_courant != ID_ESISAR:
#         iti = [id_courant] + iti
#         id_courant = p[id_courant]
#     print("On pourra visiter sucessivement les noeuds suivants :")
#     for i in iti:
#         print(labels[i])
    
if __name__ == "__main__":
    test_longueur_chemin()
    
