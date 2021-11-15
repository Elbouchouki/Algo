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