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
// parcours en largeur d'abord en utilisent une file
const parcourGraphe_file = (g, racine) => {
  var pere = Array(n);
  var couleur = Array(n);
  var distance = Array(n);
  var file = [];
  for (let sommet in g) {
    pere[sommet] = null;
    couleur[sommet] = "blanc";
    // n pour graphe connexe sinon l'infini
    distance[sommet] = n;
  }
  distance[racine] = 0;
  file.push(racine);
  while (file.length) {
    const sommet_courant = file[0];
    for (let sommet_voisin of graphe[sommet_courant]) {
      if (couleur[sommet_voisin] === "blanc") {
        couleur[sommet_voisin] = "gris";
        distance[sommet_voisin] = distance[sommet_courant] + 1;
        file.push(sommet_voisin);
        pere[sommet_voisin] = sommet_courant;
      }
    }
    file.shift();
    couleur[sommet_courant] = "noir";
  }
  return [pere, distance];
};

// parcours en largeur d'abord en utilisent une file
const parcourGraphe_pile = (g, racine) => {
  var pere = Array(n);
  var couleur = Array(n);
  var distance = Array(n);
  var pile = [];
  for (let sommet in g) {
    pere[sommet] = null;
    couleur[sommet] = "blanc";
    // n pour graphe connexe sinon l'infini
    distance[sommet] = n;
  }
  distance[racine] = 0;
  pile.push(racine);
  while (pile.length) {
    const sommet_courant = pile.pop();
    console.log("courant " + sommet_courant);
    for (let sommet_voisin of graphe[sommet_courant]) {
      if (couleur[sommet_voisin] === "blanc") {
        couleur[sommet_voisin] = "gris";
        distance[sommet_voisin] = distance[sommet_courant] + 1;
        console.log("voisin " + sommet_voisin);
        pile.push(sommet_voisin);
        pere[sommet_voisin] = sommet_courant;
      }
    }
    couleur[sommet_courant] = "noir";
  }
  return [pere, distance];
};

// console.log(parcourGraphe_file(graphe, "c"));
console.log(parcourGraphe_pile(graphe, "c"));
