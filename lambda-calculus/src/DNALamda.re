// https://thealmarty.com/2018/09/25/lambda-calculus-in-ocaml-fun-and-function/
/* Recall that in lambda calculus, we have function expressions and function applications:

   λx.λy.x+y      (*A function expression*)
   λx.λy.x+y 3 4      (*A function application*)

    */
(x, y) => x + y((x, y) => x + y, 3, 4);
let f = (x, y) => x + y;
x => x + 1;

type dna = [ | `A | `C | `G | `T];

type rna = [ | `A | `C | `G | `U];

/*
 // .ml
 let convert dna =
   match dna with
     | `A -> `U
     | `C -> `G
     | `G -> `C
     | `T -> `A
  */
let convert1 = dna =>
  switch (dna) {
  | `A => `U
  | `C => `G
  | `G => `C
  | `T => `A
  };
let to_rna = dnalist => List.map(convert1, dnalist);

let convert =
  fun
  | `A => `U
  | `C => `G
  | `G => `C
  | `T => `A;

let to_rna = dnalist => List.map(convert, dnalist);