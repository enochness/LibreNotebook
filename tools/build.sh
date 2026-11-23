#!/bin/bash

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT_DIR="$ROOT/librenotebook.enochyu.com"
TMP_DIR="$ROOT/temp"
CONTENT="$OUT_DIR/content"
CSS="$OUT_DIR/assets/css/make4ht"

cd "$ROOT"
rm -r "$CONTENT" "$CSS"
mkdir -p "$CONTENT" "$CSS" "$OUT_DIR/static/svg" "$OUT_DIR/static/img"
mkdir -p "$CONTENT" "$CSS" "$OUT_DIR/data" "$OUT_DIR/static/svg" \
  "$OUT_DIR/static/img"

# Preface
make4ht -u -B temp -f html5 tex/preface.tex "mathjax"
tidy -wrap 0 -utf8 -m --show-body-only yes --force-output yes \
  temp/preface.html
mv temp/preface.html "$CONTENT"
mv temp/preface.css "$CSS"

ls tex/*/*.tex tex/*/*/*.tex | xargs -P 8 -n 1 tools/convert.sh

cd "$ROOT"
mv temp/*.svg "$OUT_DIR"/static/svg/
cp assets/img/* "$OUT_DIR"/static/img/
rm -r temp/

git log --date=short --pretty=format:'%H%x1f%h%x1f%ad%x1f%an%x1f%s' |
jq -Rn '[inputs | split("\u001f") |
  {hash: .[0], commit: .[1], date: .[2], author: .[3], message: .[4]}]
' > librenotebook.enochyu.com/data/changelog.json

printf '%s\n' '---' 'layout: "changelog"' '---' > "$CONTENT/changelog.md"

