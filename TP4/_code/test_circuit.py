from circuit import *

# 2 petits cas de test, sans puis avec circuits.
g1 = {"a":"bc", "b":"cde", "c":"e", "d":"", "e":""}
g2 = {"a":"bc", "b":"cde", "c":"e", "d":"a", "e":"e"}
    
def est_tri_topologique(g,t):
    pass

def test_est_tri_topologique():
    assert est_tri_topologique(g1,{"a":0,"b":1,"c":2,"d":3,"e":4})
    assert not est_tri_topologique(g1,{"a":0,"b":1,"e":2,"c":3,"d":4})

def est_circuit(g,c):
    pass

def test_est_circuit():
    assert not est_circuit(g1, "a")
    assert not est_circuit(g1, "bceb")
    assert not est_circuit(g2, "abdab")
    assert est_circuit(g2, "bdab")
    assert est_circuit(g2, "ee")
    assert not est_circuit(g2, "e")
    

    
def test_tri_topologique():
    pass
    
def test_decision_circuit():
    for g in [g1,g2]:
        b,r = decision_circuit(g)
        if b:
            assert est_circuit(g,r)
        else:
            assert est_tri_topologique(g,r)
 

if __name__ == "__main__":
    test_est_tri_topologique()