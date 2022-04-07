function solution(s) {
  const [min, max] = getMinMax(s);
  return min + " " + max;
}

function getMinMax(nums) {
  const temp = nums.split(" ").sort((a, b) => Number(a) - Number(b));
  return [temp[0], temp[temp.length - 1]];
}

console.log(solution("-10 -10 -5 4 6"));
