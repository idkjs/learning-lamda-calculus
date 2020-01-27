// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");

function f(x, y) {
  return x + y | 0;
}

function convert1(dna) {
  if (dna >= 71) {
    if (dna >= 84) {
      return /* A */65;
    } else {
      return /* C */67;
    }
  } else if (dna >= 67) {
    return /* G */71;
  } else {
    return /* U */85;
  }
}

function convert(param) {
  if (param >= 71) {
    if (param >= 84) {
      return /* A */65;
    } else {
      return /* C */67;
    }
  } else if (param >= 67) {
    return /* G */71;
  } else {
    return /* U */85;
  }
}

function to_rna(dnalist) {
  return List.map(convert, dnalist);
}

exports.f = f;
exports.convert1 = convert1;
exports.convert = convert;
exports.to_rna = to_rna;
/* No side effect */
