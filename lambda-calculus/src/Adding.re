type toNumber = ((int => int, int) => int) => int;

let toNumber: toNumber = n => n(i => i + 1, 0);
/* let toNumber = n => n(i => i + 1)(0); */
let zero = (f, x) => x;
let one = (f, x) => f(x);
let two = (f, x) => f(f(x));
let three = (f, x) => f(f(f(x)));
toNumber(three);

let add = (n, m, f, x) => m(f, n(f, x));
let four = add(one, three);
toNumber(four);