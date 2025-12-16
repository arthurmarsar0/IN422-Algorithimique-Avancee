import json

ID_ESISAR = 1175823697
ID_GARE = 21639073

def gv_valence():
    with open("graphe_valence.json") as f:
        gv_valence, labels = json.load(f)  
    gv_valence = {int(x):xs for x,xs in gv_valence.items()}
    labels = {int(x):xs for x,xs in labels.items()}
    return gv_valence,labels