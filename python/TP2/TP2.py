class Stack():

    def __init__(self):
        self.pile=[]
        

    def getTete(self):
        return self.pile.pop()


    def add(self,cellule):
        self.pile.append(cellule)

    def affStack(self):
        print('queue')
        for cellule in self.pile:
            print(cellule)
        print('tete')


class Graph():

    def __init__(self):
        self.graphe={}
    
    # def __init__(self,graphe):
    #     self.graphe={graphe}



    def depth_first():
        '''itère sur les noeuds en profondeur d'abord, à partir d'un noeud donné'''
        
        pass


    def comp_con():
        '''donne les composantes connexes'''
        pass


    def path():
        '''donne le plus court chemin d'un noeud à un autre (en nombre d'arcs/arête)'''
        pass

    def ajouter_arc(self,sommet1,sommet2):
        if sommet1 in self.graphe.keys():
            self.graphe[sommet1].append(sommet2)
        else :
            self.graphe[sommet1]=[]
            self.graphe[sommet1].append(sommet2)

        if sommet2 in self.graphe.keys():
            self.graphe[sommet2].append(sommet1)
        else :
            self.graphe[sommet2]=[]
            self.graphe[sommet2].append(sommet1)


    def enlever_arc(self,sommet1,sommet2):
        print(self.graphe[sommet1])
        print(sommet2 in self.graphe[sommet1])

        if (sommet1 in self.graphe.keys() and sommet2 in self.graphe[sommet1]):
            self.graphe[sommet1].remove(sommet2)
            self.graphe[sommet2].remove(sommet1)


    def affi_graphe(self):
        print(self.graphe)




if __name__=="__main__":

    # pile=Stack()
    # pile.add(5)
    # pile.add(3)
    # pile.add(7)
    # pile.add(8)
    # pile.affStack()

    print("la")

    graphe = Graph()

    graphe.ajouter_arc(1,2)

    graphe.ajouter_arc(1,3)

    graphe.affi_graphe()

    graphe.enlever_arc(1,2)

    graphe.ajouter_arc(2,6)

    graphe.affi_graphe()