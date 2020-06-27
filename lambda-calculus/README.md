# [Anjana Vakil Lamda Calculus](https://www.youtube.com/watch?v=QrywiG2q-QQ) in [ReasonML](https://reasonml.github.io)

## Teachers

[@MartyStumpf](https://www.twitter.com/@MartyStumpf)
[@AnjanaVakil](https://www.twitter.com/@AnjanaVakil)

## Sketch.sh

Sketch.sh lets you copy the type info from your functions. Nice. I got some from [here](https://sketch.sh/s/H8yH3oU8CNhBeiw5tG8mqM/).

## Running

```sh
npm run start
```

## Church Numerals

Representing numbers like the following is called using [`Church Numerals/Encoding`](https://en.wikipedia.org/wiki/Church_encoding).

```ocaml
let toNumber = n => n(i => i + 1, 0);
let zero = (_f, x) => x;
let one = (f, x) => f(x);
let two = (f, x) => f(f(x));
let three = (f, x) => f(f(f(x)));
```

## Arithmetic

```ocaml
let add = n => m => f =>x => m(f)(n(f)(x));
```
