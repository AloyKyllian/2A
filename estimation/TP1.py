import numpy as np
import matplotlib.pyplot as plt

# Simuler N = 1000 réalisations d'une variable aléatoire Gaussienne scalaire X
N = 1000
mu = 0  # Moyenne
sigma = 1  # Écart-type

# Utiliser la fonction randn de NumPy pour générer les réalisations
x = np.random.randn(N) * sigma + mu


y = 10 + np.sqrt(2) * x
countsy, centersy, _ = plt.hist(y, bins=100, density=True, alpha=0.7)
bin_width = centersy[1] - centersy[0]
# Ajuster les centers pour avoir la bonne dimension
centersy = 0.5 * (centersy[:-1] + centersy[1:])

y_theoretical = np.arange(min(y), max(y), 0.1)
print(min(y), max(y))
sigmay = np.sqrt(2)
muy = 10
pdf_theoretical = (1 / (np.sqrt(2 * np.pi) * sigmay)) * \
    np.exp(-(y_theoretical - muy)**2 / (2 * sigmay**2))
plt.plot(y_theoretical, pdf_theoretical,
         label='Densité théorique de y', color='red')


# Afficher l'histogramme
counts, centers, _ = plt.hist(x, bins=100, density=True, alpha=0.7)

# Normaliser l'histogramme
bin_width = centers[1] - centers[0]
# Ajuster les centers pour avoir la bonne dimension
centers = 0.5 * (centers[:-1] + centers[1:])

# Tracer la densité de probabilité théorique
x_theoretical = np.arange(min(x), max(x), 0.1)
pdf_theoretical = (1 / (np.sqrt(2 * np.pi) * sigma)) * \
    np.exp(-(x_theoretical - mu)**2 / (2 * sigma**2))
plt.plot(x_theoretical, pdf_theoretical,
         label='Densité théorique', color='red')

# plt.plot(y, pdf_theoretical,
#          label='Densité y', color='bleu')


# Ajouter des labels et un titre
plt.xlabel('Valeurs de la variable aléatoire')
plt.ylabel('Fréquence / Densité de probabilité')
plt.title('Histogramme et Densité théorique d\'une variable aléatoire Gaussienne')

# Afficher la légende
plt.legend()

# Afficher le graphique
plt.show()


######################################## 2############################
