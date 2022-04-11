// 풀이: https://www.notion.so/38c17259d8404217b580c27b814a5eac

function solution(land) {
  var answer = 0;

  for (let i = 1; i < land.length; i++) {
    for (let j = 0; j < land[0].length; j++) {
      land[i][j] += Math.max(...land[i - 1][(0, j)], ...land[i - 1][j + 1]);
    }
  }

  answer = Math.max(...land[land.length - 1]);
  return answer;
}
