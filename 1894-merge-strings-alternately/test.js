let a = 100;

async function increment(counter) {
  console.log(`start ${counter}`);
  await a++;
  console.log(`end ${counter}`);
}

increment(1);
increment(2);
increment(3);
console.log(a);
