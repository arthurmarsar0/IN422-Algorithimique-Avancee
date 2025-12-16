# Code Élève
from heapq import *

# exemple basique
exemple1 = {"a":[("f",14),("c",9),("b",7)],\
            "b":[("c",10),("d",15)],\
            "c":[("f",2),("d",11)],\
            "d":[("e",6)],\
            "e":[],\
            "f":[("e",9)]}

INFINI = float("inf")

def longueur_chemin(gv, c): #ex c = "abc"
    longueur = 0
    size_loop = len(c) - 1

    if size_loop == 0: 
        # print("Entrou")
        return longueur #Se for um ponto unico é 0
   
    for i in range(size_loop):
        if gv.get(c[i]): 
            # print("E Aqui?")
            nb_routes = len(gv.get(c[i]))
            count = 0
            for route in gv.get(c[i]):
                # print(route)
                if route[0] == c[i+1]:
                    # print("Aqui")
                    longueur += route[1]
                    # print(count)
                else: #There isnt a path in the middle of the trajectory
                    # print("Else")
                    count+=1
                    # return INFINI
                if count == nb_routes:
                    return INFINI

    return longueur

        
#Em c:
#for(int i = 0; i < len(c) - 1; i++){
#   Busca no diocionario a rota c[i] -> c[i + 1]
#   Soma ao proximo elemento
#}

def dijkstra(s, gv):
    pass
    

def dijkstra_optimise(s, gv):
    pass

        

    
# list = exemple1.get("a")

# # print(list[1])

# print(longueur_chemin(exemple1, "ae"))