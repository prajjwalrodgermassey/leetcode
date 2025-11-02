let age = 28;
const print = () => {
  console.log(this.age);
};

const obj = {
  age: 29,
  test: function () {
    console.log(this.age);
  },
};

obj.test();
