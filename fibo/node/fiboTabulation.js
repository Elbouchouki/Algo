const fibo = (n) => {
  const arr = Array(n).fill(0);
  arr[1] = 1;
  for (let i = 0; i < n; i++) {
    arr[i + 1] += arr[i];
    arr[i + 2] += arr[i];
  }
  return arr[n - 1];
};

console.log(fibo(1));
console.log(fibo(2));
console.log(fibo(3));
console.log(fibo(4));
console.log(fibo(5));
console.log(fibo(6));
