# [Types And Programming Languages](https://github.com/strega-nil/tapl-re)
===============================

[source](https://github.com/strega-nil/tapl-re)

My implementation of a lambda calculus. It's fairly simple, it's simply typed,
and written in reasonML.

The type system includes only `unit` and `->`. There are two constants;
`(): unit`, and `@: unit -> unit`. `@` is only included for printing; an
application of `@` is not evaluated (although the body *is* evaluated). This
is useful for printing numbers; `n @ ()`, which would print as if `()` is
`Z`, while `@` is `S`. Similarly, `true` can be implemented as `@ ()`, versus
`false` is `()`.

Notes: DO NOT RUN `refmt`! It makes the do blocks *really* ugly.

## Running

Running `dune exec ./tal.exe` should build and run `tal.exe`.

If not, do following:

Build with `dune build tal.exe`
Run with `dune exec ./tal.exe`