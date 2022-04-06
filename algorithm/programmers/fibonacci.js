// 해설 & 노트: https://www.notion.so/bc89cd40852a463db9eeaaa248ab4316?v=34dc44b7fe1940d582db4dd181639e7c&p=4372c91c904f41849022424a5ba0946e

function solution(n) {
  let pp = 0;
  let p = 1;
  for (let i = 2; i <= n; i++) {
    let tmp = (p + pp) % 1234567;
    pp = p;
    p = tmp;
  }
  return p;
}

console.log(solution(100000));
