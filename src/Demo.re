// toNumber is a function that takes in x and another function that takes a y then returns an int and returns an int.
type toNumber = ((int => int, int) => int) => int;

let toNumber: toNumber = n => n(i => i + 1, 0);
let zero = (_f, x) => x;
let one = (f, x) => f(x);
let two = (f, x) => f(f(x));
let three = (f, x) => f(f(f(x)));

toNumber(three) |> Js.log2("three");
toNumber(zero) |> Js.log2("zero");
toNumber(one) |> Js.log2("one");
toNumber(two) |> Js.log2("two");

// Arithmetic
// type addA = (('a, 'b) => 'c, ('a, 'c) => 'd, 'a, 'b) => 'd;

type add = ((int, int) => int, (int, int) => int, int, int) => int;

// let add: add = (n, m, f, x) => m(f, n(f, x));
// function `four` fails when we add the type parameter to it but then you see that four gets correctly typed as ints: ```
let add = (n, m, f, x) => m(f, n(f, x));

let four = add(one, three);
toNumber(four);
Js.log2("four");

let mul = (n, m, f, x) => m(n(f), x);

toNumber(mul(three, four)) |> Js.log2("three x four");
toNumber(mul(three, two)) |> Js.log2("three x two");
// A Deep Thought
let answer = add(two, mul(four, mul(two, add(four, one))));
toNumber(answer) |> Js.log2("the answer");

// Booleans and Conditionals -> Control Flow
// We need an `if`, `then`, `else` construction
// Boolean is a function that when applied to a `then` and an `else` will pick one of them.

let ifThenElse = (bool, thn, els) => bool(thn, els);
let troo = (thn, els) => thn;
let falz = (thn, els) => els;

let tired = falz;
let amTired = bool => ifThenElse(bool, three, one);
amTired(falz)|>toNumber|>Js.log2("amTired(falz)")
amTired(troo)|>toNumber|>Js.log2("amTired(true)")
let coffeesToday = ifThenElse(tired, three, one);
let howManyCoffeesToday = bool => ifThenElse(bool, three, one);
toNumber(coffeesToday) |> Js.log2("coffeesToday->tired=true");
let tired = falz;
toNumber(amTired(tired)) |> Js.log2("amTired->tired=false");
toNumber(howManyCoffeesToday(amTired(tired)))
|> Js.log2("howManyCoffeesToday->tired=false");
let tired = troo;
toNumber(howManyCoffeesToday(amTired(tired)))
|> Js.log2("howManyCoffeesToday->tired=true");

// Logic https://youtu.be/QrywiG2q-QQ?t=1817
let toBoolean = bool => bool(true)(false);
toBoolean(falz)|>Js.log2("toBoolean:falz");
toBoolean(troo)|>Js.log2("toBoolean:troo");

// call not on bool to get the opposite so if bool is false return true.
let not = (bool) => thn => els => bool(els,thn);
toBoolean(not(falz))|>Js.log2("not falz should be true:");

// or operator returns true when they are both false.
let or_ = a => b => (a)(b);
// this might be redundant in reason. `b` is never used?
// toBoolean(or_(falz,troo))|>Js.log2("toBoolean(or_(falz)):");
toBoolean(or_(troo))|>Js.log2("toBoolean(or_(troo)):");
toBoolean(or_(falz))|>Js.log2("toBoolean(or_(falz)):");
toBoolean(falz)|>Js.log2("bool(falz)):");
toBoolean(troo)|>Js.log2("bool(troo)):");

let or_ = a => a;
toBoolean(or_(falz))|>Js.log2("toBoolean(or_(falz)):");
toBoolean(or_(troo))|>Js.log2("toBoolean(or_(troo)):");
toBoolean(falz)|>Js.log2("bool(falz)):");
toBoolean(troo)|>Js.log2("bool(troo)):");

// More Logic
// And https://youtu.be/QrywiG2q-QQ?t=2162
// if a is false return whatever b is. If if a is true, returns a.
let and_ = a => b => (a)(b);
toBoolean(and_(troo)(falz))|>Js.log2("a is true so should return true:");
toBoolean(and_(troo)(troo))|>Js.log2("and_(troo)(troo):",_);
// toBoolean(and_(falz)(falz))|>Js.log2("and_(falz)(falz):");
// toBoolean(and_(falz)(troo))|>Js.log2("and_(falz)(troo):");
Unfold.example(4)->Js.log;