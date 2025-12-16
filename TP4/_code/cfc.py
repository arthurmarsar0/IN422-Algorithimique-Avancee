def dfs(g):
    pass
        
def miroir(g):
    r = {x:[] for x in g}
    for x,ys in g.items():
        for y in ys:
            r[y].append(x)
    return r

def accessibles(g,x,f):
    pass
    
def cfc(g):
    pass

def quotient(g):
    pass
    