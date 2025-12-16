from cfc import *

# Graphe donné en exemple dans l'énoncé
g1 = {"a":"e", "b":"a", "c":"bcfg", "d":"c", "e":"af", "f":"b", "g":"d", "h":"eg"}
# deuxième graphe un peu plus grand
g2 = {1 : [5, 7], 2 : [11], 3 : [9], 4 : [6, 10],\
      5 : [10], 6 : [2, 8], 7 : [3], 8 : [4], 9 : [],\
      10 : [1, 2, 3], 11 : [1, 2]}


def test_dfs():
    lst = dfs(g1)
    print(lst)
    
def test_cfc():
    CFC = cfc(g1)
    inv_CFC = {}
    for x,c in CFC.items():
        if c not in inv_CFC:
            inv_CFC[c] = []
        inv_CFC[c].append(x)
    print(CFC)
    print(inv_CFC)
    
def test_accessibles():
    print(accessibles(g1,"a",{x:True for x in g1}))
       
def test_quotient():
    pass
    
if __name__ == "__main__":
    #test_dfs()
    #test_accessibles()
    #test_cfc()
    #test_quotient()

