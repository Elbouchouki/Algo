// graphe de n sommets
const n = 9;
var graphe = Array(n);
graphe["a"] = ["b", "g"];
graphe["b"] = ["a", "c", "e", "g"];
graphe["c"] = ["b", "d", "f"];
graphe["d"] = ["c"];
graphe["e"] = ["b", "f", "h"];
graphe["f"] = ["c", "e", "i"];
graphe["g"] = ["a", "b", "h"];
graphe["h"] = ["g", "e", "i"];
graphe["i"] = ["f", "h"];
// parcours en largeur d'abord
const parcourGraphe = (g, racine) => {
  var pere = Array(n);
  var explore = Array(n);
  var debut = Array(n);
  var fin = Array(n);
  var j = 1;
  const explorer = (sommet) => {
    explore[sommet] = true;
    debut[sommet] = j++;
    for (let voisin of g[sommet]) {
      if (!explore[voisin]) {
        pere[voisin] = sommet;
        explorer(voisin);
      }
    }
    fin[sommet] = j++;
  };
  for (let sommet in g) {
    explore[sommet] = false;
    pere[sommet] = null;
    debut[sommet] = 0;
    fin[sommet] = 0;
  }
  for (let sommet in g) {
    if (!explore[sommet]) explorer(sommet);
  }

  return [pere, debut, fin];
};

const parcourGraphe_pile = (g, racine) => {
  var pere = Array(n);
  var couleur = Array(n);
  var distance = Array(n);
  var pile = [];
  for (let sommet in g) {
    pere[sommet] = null;
    couleur[sommet] = "blanc";
    distance[sommet] = n;
  }
  distance[racine] = 0;
  pile.push(racine);
  while (pile.length) {
    const sommet_courant = pile.pop();
    for (let sommet_voisin of graphe[sommet_courant]) {
      if (couleur[sommet_voisin] === "blanc") {
        couleur[sommet_voisin] = "gris";
        distance[sommet_voisin] = distance[sommet_courant] + 1;
        pile.push(sommet_voisin);
        pere[sommet_voisin] = sommet_courant;
      }
    }
    couleur[sommet_courant] = "noir";
  }
  return [pere, distance];
};
console.log(parcourGraphe(graphe, "c"));
