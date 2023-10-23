d = {1: {"a": 2, "b": 4},
     2: {"c": 4},
     5: {"b": 4, "d": 2, "e": 7}}


def dict_paires(dico):
    dictionnaire = {}
    for keys, dic2 in dico.items():
        for keys2, value in dic2.items():
            dictionnaire[(keys, keys2)] = value

    return dictionnaire


print(dict_paires(d))


def dict_split(dico):
    dictionnaire = {}
    dico2 = []
    for (key, key2), value in dico.items():
        dico2 = {key2: value}
        if key in dictionnaire:
            # dictionnaire[key] = dictionnaire[key] | dico2
            dictionnaire[key].update(dico2)
        else:
            dictionnaire[key] = dico2.copy()
        dico2.clear()

    return dictionnaire


print(dict_split(dict_paires(d)))
