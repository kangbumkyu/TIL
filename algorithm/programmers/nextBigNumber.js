function solution(n) {
  const src = countOne(n);
  let dest;

  while (src !== (dest = countOne(++n)));

  return n;
}

function countOne(num) {
  const binary = num.toString(2);
  let count = 0;

  for (let i = 0; i < binary.length; i++) {
    if (binary[i] === "1") {
      count++;
    }
  }

  return count;
}

console.log(solution(15));
