#!/bin/bash

OUT_DIR="$HOME/projects/LibreNotebook/librenotebook.enochyu.com"
TMP_DIR="$HOME/projects/LibreNotebook/temp"
CONTENT="$OUT_DIR/content"
CSS="$OUT_DIR/assets/css/make4ht"

dir=$(dirname "$1")
name=$(basename "$1" .tex)
nameLower=$(echo "$name" | tr 'A-Z' 'a-z')
page=$(echo "${dir#tex/}" | tr 'A-Z' 'a-z')

cd ~/projects/LibreNotebook/"$dir"

make4ht -u -B $TMP_DIR -f html5 "$name".tex "mathjax"
if grep -qE '\\(no)?cite|\\printbibliography' "$name".tex; then
  (cd "$HOME/projects/LibreNotebook" &&
   biber --output-directory temp "$name")
  make4ht -u -B "$TMP_DIR" -f html5 "$name".tex "mathjax"
fi

if [[ "$page" == */* ]]; then
  perl -0777 -pi -e "s#src\s*=\s*'([^']+\.svg)'#src='/svg/\$1'#g" \
    "$TMP_DIR/$name".html
  perl -pi -e 's/\\(?:displaybreak|linebreak|relax)//g' \
    "$TMP_DIR/$name.html"
  html="$CONTENT/$page/$nameLower".html
else
  html="$CONTENT/$page".html
fi

  
tidy -wrap 0 -utf8 -m --show-body-only yes --force-output yes \
  "$TMP_DIR/$name".html
mkdir -p "$(dirname "$html")"
mv "$TMP_DIR/$name".html "$html"
mv "$TMP_DIR/$name".css "$CSS/$nameLower".css


