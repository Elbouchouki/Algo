function fibo(i) {
  if (i < 1) return 0;
  if (i === 1) return 1;
  return fibo(i - 1) + fibo(i - 2);
}
function fibo_optimized(i, memo = {}) {
  if (memo[i]) return memo[i];
  if (i < 1) return 0;
  if (i === 1) return 1;
  memo[i] = fibo_optimized(i - 1, memo) + fibo_optimized(i - 2, memo);
  return memo[i];
}

function test(x, fibo) {
  for (let i = 0; i < x; i++) {
    console.log("fibo(" + i + ")=" + fibo(i));
  }
}
function big_test(fibo) {
  console.log("fibo(20)=" + fibo(20));
  console.log("fibo(30)=" + fibo(30));
  console.log("fibo(50)=" + fibo(50));
  console.log("fibo(60)=" + fibo(60));
}
console.log("\n-->Optimized\n");
test(5, fibo_optimized);
big_test(fibo_optimized);
console.log("\n-->BruteForce\n");
test(5, fibo);
big_test(fibo);
