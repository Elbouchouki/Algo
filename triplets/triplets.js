const MAX = 100;

const oldTriplet = (max) => {
  const res = [];
  let a, b, c;
  for (a = 0; a <= max; a++) {
    for (b = a + 1; b <= max; b++) {
      for (c = b + 1; c <= max; c++) {
        if (a * a + b * b === c * c) {
          res.push([a, b, c]);
        }
      }
    }
  }
  return res;
};

const newTriplet = (limit) => {
  let a,
    a2,
    b,
    b2,
    c,
    c2,
    result = [];
  for (a = 1; a < limit; ++a) {
    a2 = a * a;
    b = a + 1;
    c = b + 1;
    while (c <= limit) {
      c2 = 0;
      b2 = b * b;
      while (c * c < (c2 = a2 + b2)) {
        ++c;
      }
      if (c * c == c2 && c <= limit) {
        result.push([a, b, c]);
      }
      ++b;
    }
  }
  return result;
};

const affichage = (res) => {
  for (let x in res) {
    console.log(
      x + " triplet : (" + res[x][0] + "," + res[x][1] + "," + res[x][2] + ")"
    );
  }
};

const res1 = oldTriplet(MAX);
const res2 = newTriplet(MAX);
// affichage(res1);
console.log(res1.length);
// console.log("------------");
// affichage(res2);
console.log(res2.length);
