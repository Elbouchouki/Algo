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
  var couleur = Array(n);
  var file = [];
  for (let sommet in g) {
    pere[sommet] = null;
    couleur[sommet] = "blanc";
  }
  file.push(racine);
  while (file.length) {
    const sommet_courant = file[0];
    for (let sommet_voisin of graphe[sommet_courant]) {
      if (couleur[sommet_voisin] === "blanc") {
        couleur[sommet_voisin] = "gris";
        file.push(sommet_voisin);
        pere[sommet_voisin] = sommet_courant;
      }
    }
    file.shift();
    couleur[sommet_courant] = "noir";
  }
  return pere;
};

console.log(parcourGraphe(graphe, "c"));
