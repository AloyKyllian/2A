class Stack():

    def __init__(self):
        self.pile = []

    def size(self):
        return len(self.pile)

    def isEmpty(self):
        return self.size() == 0

    def getTete(self):
        return self.pile.pop()

    def add(self, cellule):
        self.pile.append(cellule)

    def affStack(self):
        print('queue')
        for cellule in self.pile:
            print(cellule)
        print('tete')


class Graph():

    def __init__(self):
        self.graphe = {}

    # def __init__(self,graphe):
    #     self.graphe={graphe}

    def size(self):
        return len(self.graphe)

    def isEmpty(self):
        return self.size() == 0

    def succeseur(self, noeud):
        if noeud in self.graphe.keys():
            return self.graphe[noeud]

    def depth_first(self, noeud_depart):
        '''itère sur les noeuds en profondeur d'abord, à partir d'un noeud donné'''
        if noeud_depart not in self.graphe.keys():
            return -1
        liste = []
        pile = Stack()
        pile.add(noeud_depart)
        while (pile.isEmpty() == False):
            noeud = pile.getTete()
            liste.append(noeud)
            # yield noeud
            succ = self.succeseur(noeud)
            for i in succ:
                if i not in liste:
                    pile.add(i)
        return liste

    def comp_con(self):
        '''donne les composantes connexes'''
        comps = []
        for i in self.graphe:
            comp = list(self.depth_first(i))
            comp.sort()
            if comp not in comps:
                comps.append(comp)
        return comps

    def path(self, noeud, noeud2):
        '''donne le plus court chemin d'un noeud à un autre (en nombre d'arcs/arête)'''
        if noeud in self.graphe.keys() and noeud2 in self.graphe.keys():
            if noeud in self.depth_first(noeud2):
                trajet = 0
                sommetobs = noeud
                dejavu = set()
                chemin = []
                pile = Stack()
                resultat = []
                poids = 0
                pile.add((noeud, poids))
                while pile.isEmpty() == False:
                    sommet = pile.getTete()
                    dejavu.add(sommet)
                    print(f"sommet = {sommet}")
                    chemin.append(sommet)
                    succ = self.succeseur(sommet[0])
                    print(set(succ) ^ dejavu)
                    for i in succ:
                        if i == noeud2:
                            chemin.append(i)
                            resultat.append(chemin)
                            print(chemin)
                            if (len(succ) == 2):
                                chemin = chemin[:-2]
                            else:
                                chemin = chemin[:-1]
                        if i not in dejavu and i != noeud2:
                            pile.add((i, poids))
                print(resultat)

                pile = Stack()
                resultat = []
                poids = 0
                pile.add((noeud, poids))
                while pile.isEmpty() == False:
                    sommet = pile.getTete()
                    succ = self.succeseur(sommet[0])
                    poids = poids+1
                    for i in succ:
                        if i in successeur:
                            table.append(i, poids)
                        successeur.append(i)

    def ajouter_arc(self, sommet1, sommet2):
        if sommet1 in self.graphe.keys() and sommet2 in self.graphe[sommet1]:
            return -1
        if sommet1 in self.graphe.keys():
            self.graphe[sommet1].append(sommet2)
        else:
            self.graphe[sommet1] = []
            self.graphe[sommet1].append(sommet2)

        if sommet2 in self.graphe.keys():
            self.graphe[sommet2].append(sommet1)
        else:
            self.graphe[sommet2] = []
            self.graphe[sommet2].append(sommet1)

    def enlever_arc(self, sommet1, sommet2):
        print(self.graphe[sommet1])
        print(sommet2 in self.graphe[sommet1])

        if (sommet1 in self.graphe.keys() and sommet2 in self.graphe[sommet1]):
            self.graphe[sommet1].remove(sommet2)
            self.graphe[sommet2].remove(sommet1)

    def affi_graphe(self):
        print(self.graphe)


if __name__ == "__main__":

    # pile=Stack()
    # pile.add(5)
    # pile.add(3)
    # pile.add(7)
    # pile.add(8)
    # pile.affStack()

    print("la")

    graphe = Graph()

    graphe.ajouter_arc(1, 2)

    graphe.ajouter_arc(1, 3)

    graphe.affi_graphe()

    graphe.enlever_arc(1, 2)

    graphe.ajouter_arc(2, 6)

    graphe.ajouter_arc(2, 8)

    graphe.ajouter_arc(5, 8)

    graphe.ajouter_arc(5, 6)

    graphe.ajouter_arc(7, 6)

    graphe.ajouter_arc(5, 9)

    graphe.ajouter_arc(5, 4)

    graphe.ajouter_arc(5, 7)

    graphe.ajouter_arc(2, 10)

    graphe.ajouter_arc(10, 11)

    graphe.ajouter_arc(11, 12)

    graphe.ajouter_arc(12, 5)

    # graphe.ajouter_arc(1,2)

    graphe.affi_graphe()

    for i in (graphe.depth_first(5)):
        print(i)
    print(list(graphe.depth_first(2)))

    graphe.comp_con()

    print(f"le tajet le plus court de 2 vers 5 est de : {graphe.path(2,5)}")

    liste = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    liste2 = liste[:-2]

    print(liste2)
