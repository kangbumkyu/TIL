function solution(board) {
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      if (
        board[i][j] >= 1 &&
        board[i - 1] !== undefined &&
        board[i][j - 1] !== undefined
      ) {
        board[i][j] =
          Math.min(board[i][j - 1], board[i - 1][j - 1], board[i - 1][j]) + 1;
      }
    }
  }

  const length = Math.max(...board.map((row) => Math.max(...row)));
  return length * length;
}
