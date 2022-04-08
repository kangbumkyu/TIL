function solution(s) {
  let countOpen = 0;

  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(") {
      countOpen++;
    } else {
      countOpen--;
    }
    if (countOpen < 0) {
      return false;
    }
  }

  return countOpen === 0;
}
