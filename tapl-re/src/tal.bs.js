// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Pervasives = require("bs-platform/lib/js/pervasives.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Parse$ReasonLambdas = require("./parse.bs.js");
var Lambda$ReasonLambdas = require("./lambda.bs.js");

function $$eval(_ast) {
  while(true) {
    var ast = _ast;
    var ast$1 = Lambda$ReasonLambdas.eval1(ast);
    if (ast$1 === undefined) {
      return ast;
    }
    _ast = Caml_option.valFromOption(ast$1);
    continue ;
  };
}

function eval_and_print(_ast) {
  while(true) {
    var ast = _ast;
    Pervasives.print_newline(Lambda$ReasonLambdas.print_ast(ast));
    var ast$1 = Lambda$ReasonLambdas.eval1(ast);
    if (ast$1 === undefined) {
      return ast;
    }
    _ast = Caml_option.valFromOption(ast$1);
    continue ;
  };
}

function main(param) {
  var term = Parse$ReasonLambdas.parse("\n  type id_t = unit -> unit in\n  type nat = id_t -> unit -> unit in\n  let n = (\n    let succ =\n      /n:nat./s:id_t./z:unit.s (n s z)\n    in\n    let zero =\n      /s:id_t./z:unit.z\n    in\n    succ (succ (succ zero))\n  ) in n @ ()\n  ");
  var term$1;
  if (term.TAG) {
    Pervasives.print_string("error: ");
    Pervasives.print_newline(Parse$ReasonLambdas.print_parser_error(term._0));
    term$1 = Pervasives.exit(1);
  } else {
    term$1 = term._0;
  }
  Pervasives.print_newline(Lambda$ReasonLambdas.print_term(term$1));
  var ast = Lambda$ReasonLambdas.finish(term$1);
  if (ast.TAG) {
    Pervasives.print_string("error: ");
    Pervasives.print_newline(Lambda$ReasonLambdas.print_type_error(ast._0));
    return Pervasives.exit(2);
  }
  var ast$1 = ast._0;
  eval_and_print(ast$1);
  
}

main(undefined);

var finish = Lambda$ReasonLambdas.finish;

exports.$$eval = $$eval;
exports.eval_and_print = eval_and_print;
exports.finish = finish;
exports.main = main;
/*  Not a pure module */
