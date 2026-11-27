#!/bin/bash

cd "$(dirname "$0")/.."

files=$(find tex -name '*.tex')
notes=$(cat $files)
count() {
  grep -oE "\\\\begin\{($1)\}" <<< "$notes" | wc -l
}

jq -n '$ARGS.named' \
  --argjson lines       "$(cat $files | wc -l)" \
  --argjson definitions "$(count 'definition')" \
  --argjson theorems    "$(count 'theorem')" \
  --argjson lemmas      "$(count 'lemma\*?')" \
  --argjson corollaries "$(count 'corollary')" \
  --argjson proofs      "$(count 'proof|proofInBox')" \
  --argjson problems    "$(count 'problem|listproblem')" \
  --argjson solutions   "$(count 'solution')" \
  --argjson tips        "$(count 'important')" \
  > librenotebook.enochyu.com/data/stats.json


