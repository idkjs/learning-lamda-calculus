/* https://thealmarty.com/2018/12/04/programming-with-lenses-in-haskell-and-ocaml/ */
let rec unfold = (p, g, b) =>
  if (p(b)) {
    [];
  } else {
    switch (g(b)) {
    | (a, bprime) => [a, ...unfold(p, g, bprime)]
    };
  };

/*Implement the example:
see [discussion](https://discordapp.com/channels/235176658175262720/235176658175262720/671374336824967188) on why you can call `example(7)` though no params are defined. Short answer is that functions always take one argument in OCaml/Reason, but they may return functions.

`example` is a partially applied function of unfold.  Basically it's equivalent to
```ocaml
let example(b) => unfold(x => x > 9, x => (x, x + 1), b);
```

See also @ambientlight's comment here: https://discordapp.com/channels/@me/667776437280964647/671375156039647233
 */
let example = unfold(x => x > 9, x => (x, x + 1));
example(7)


