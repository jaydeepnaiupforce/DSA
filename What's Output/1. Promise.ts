const myPromose = (n: number) => {
  return Promise.resolve("i have resolved" + n);
};

const first = () => {
  myPromose(1).then((res) => console.log(res));
  console.log("he  i  m here");
};

const sec = async () => {
  console.log(await myPromose(2));
  console.log("he  i  m sec");
};

first();
sec();
