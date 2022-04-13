function solution(s) {
  const lengths = [];
  for (let i = 1; i <= s.length; i++) {
    lengths.push(compressStr(s, i));
  }

  return Math.min(...lengths);
}

function compressStr(s, by) {
  let current = s.slice(0, by);
  let count = 0;
  let compressed = "";

  for (let i = 0; i < s.length; i = i + by) {
    if (s.slice(i, i + by) === current) {
      count++;
    } else {
      if (count > 1) {
        compressed = `${compressed}${count}${current}`;
      } else {
        compressed = `${compressed}${current}`;
      }
      current = s.slice(i, i + by);
      count = 1;
    }
  }
  if (count > 1) {
    compressed = `${compressed}${count}${current}`;
  } else {
    compressed = `${compressed}${current}`;
  }

  return compressed.length;
}

console.log(solution("aabbaccc"));
