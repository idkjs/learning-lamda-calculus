type toNumber = ((int => int, int) => int) => int;
let toNumber: toNumber;
let zero: ('a, 'b) => 'b;
let one: ('a => 'b, 'a) => 'b;
let two: ('a => 'a, 'a) => 'a;
let three: ('a => 'a, 'a) => 'a;