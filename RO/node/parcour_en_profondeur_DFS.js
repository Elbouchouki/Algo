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
console.log(parcourGraphe(graphe, "c"));
