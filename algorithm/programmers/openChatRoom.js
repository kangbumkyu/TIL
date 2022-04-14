function solution(record) {
  var answer = [];
  const obj = {};

  for (let i = 0; i < record.length; i++) {
    const [msg, id, username] = record[i].split(" ");
    if (msg === "Enter" || msg === "Change") {
      obj[id] = username;
    }
  }
  for (let i = 0; i < record.length; i++) {
    const [msg, id, username] = record[i].split(" ");
    if (msg === "Enter") {
      answer.push(`${obj[id]}님이 들어왔습니다.`);
    } else if (msg === "Leave") {
      answer.push(`${obj[id]}님이 나갔습니다.`);
    }
  }
  return answer;
}
