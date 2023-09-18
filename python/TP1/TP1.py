
ponctuations = set(":/;.?,-_^()\"*!")
motbannis = "the and to a of she it I i in you her at on had all with but for so not as".split(" ")

def read_fichier():
    fichier = open("/home/pandou/Documents/2A/python/TP1/irit.fr_~Philippe.Muller_alice_wonderland.utf8.conll.txt",
                   "r", encoding="utf-8")
    
    return fichier.read().lower()

def remove_ponctuation(texte):
    for ponctuation in ponctuations:
        if ponctuation in texte:
            texte = texte.replace(ponctuation,"")
    return texte

def comptage(liste):
    dic={}
    for mot in liste:
        if mot not in motbannis:
            dic[mot] = dic.get(mot, 0)+1
    return dic

def sort_dictionnaire(dic):
    occurence =[]
    for (mot,occ) in dic.items():
        occurence.append((occ,mot))  
    occurence.sort()
    occurence.reverse()
    return occurence
    
def read_fichier_conll():
    fichier = open("/home/pandou/Documents/2A/python/TP1/irit.fr_~Philippe.Muller_alice_wonderland.utf8.conll.txt",
                   "r", encoding="utf-8")
    
    return fichier.read()
    
def trie_dico(texte):
    lines = texte.split("\n")
    
    liste_mot=[]
    
    for line in lines:
        liste_mot.append(line.split())
    
    dic={}
    dic['salut'] = {'occ':3,'cat':'NN'}
    dic['salut']['occ']=3
    print(dic)

    for rien,cat,mot in liste_mot[:len(liste_mot)-1]:
        print(cat)
        if mot != '<unknown>':
            if mot in dic:
                dic[mot]['occ'] = dic[mot]['occ']+1
            else:
                dic[mot]={}
                dic[mot]['occ'] = 1
                dic[mot]["cat"] = cat
        
    return dic

def sort_dictionnaire2(dic,categorie):
    occurence =[]
    for mot in dic:
        if dic[mot]['cat'] == categorie:
            occurence.append((dic[mot]['occ'],dic[mot]['cat'],mot))
    occurence.sort()
    occurence.reverse()
    return occurence
    
def lister_mot(nbr) :
    liste_tuple=[]
    for ind in range(len(liste)-nbr-1):
        liste_tuple.append(tuple(liste[ind:ind+nbr]))
    return liste_tuple    


if __name__=="__main__":
    
    
    ##########################################exo 1#########################################
    
    # texte = read_fichier()
    
    # texte=remove_ponctuation(texte)
    
    # liste = texte.split()
    
    # dic = {}
    # dic = comptage(liste)
    
    # print(dic["alice's"])
    
    # occurence=sort_dictionnaire(dic)
    
    # print(occurence[:50])
    
    ###########################################exo 2#########################################
    
    # texte = read_fichier_conll()
    
    # dic={}

    # dic = trie_dico(texte)
    
    # occurence=sort_dictionnaire2(dic,'RB')
    
    # print(occurence[:50])
    
    ##########################################exo 3###########################################
    
    texte = read_fichier()
    
    texte=remove_ponctuation(texte)
    
    liste = texte.split()

    liste_tuple = lister_mot(3)
        
    dic = comptage(liste_tuple)
    
    occurence=sort_dictionnaire(dic)
    
    print(occurence[:50])
    
        
    
    
