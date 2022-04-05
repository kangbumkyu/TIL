function solution(arr1, arr2) {
  var answer = new Array(arr1.length)
    .fill()
    .map(() => new Array(arr2[0].length).fill());

  for (let i = 0; i < arr1.length; i++) {
    let sum = 0;
    for (let j = 0; j < arr2[0].length; j++) {
      for (let k = 0; k < arr1[0].length; k++) {
        sum += arr1[i][k] * arr2[k][j];
      }
      answer[i][j] = sum;
      sum = 0;
    }
  }

  return answer;
}

console.log(
  solution(
    [
      [1, 4],
      [3, 2],
      [4, 1],
    ],
    [
      [3, 3],
      [3, 3],
    ]
  )
);
