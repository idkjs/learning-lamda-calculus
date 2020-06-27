const toNumber = n => n(i => i + 1)(0);
// const three = toNumber(3);
const zero = f => x => x;
const one = f => x => f(x);
const two = f => x => f(f(x));
const three = f => x => f(f(f(x)));
console.log(toNumber(three));

let toNumber = n => n(i => i + 1)(0);
let zero = f => x => x;
let one = f => x => f(x);
let two = f => x => f(f(x));
let three = f => x => f(f(f(x)));