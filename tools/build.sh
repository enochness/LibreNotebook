#!/bin/bash

OUT_DIR="$HOME/projects/LibreNotebook/librenotebook.enochyu.com"
TMP_DIR="$HOME/projects/LibreNotebook/temp"
CONTENT="$OUT_DIR/content"
CSS="$OUT_DIR/assets/css/make4ht"

cd ~/projects/LibreNotebook
rm -r "$CONTENT" "$CSS"
mkdir "$CONTENT" "$CSS"

# Preface
make4ht -u -B temp -f html5 tex/preface.tex "mathjax"
tidy -wrap 0 -utf8 -m --show-body-only yes --force-output yes \
  temp/preface.html
mv temp/preface.html "$CONTENT"
mv temp/preface.css "$CSS"

# Notes
for dir in tex/*; do
  [[ -d "$dir" ]] || continue

  dirName="${dir#tex}"
  dirNameLower=$(echo "$dirName" | tr 'A-Z' 'a-z')
  mkdir -p "$CONTENT$dirNameLower"

  (
    cd "$HOME/projects/LibreNotebook/$dir"
    make4ht -u -B $TMP_DIR -f html5 "${dirName#/}".tex "mathjax"
    if grep -qE '\\(no)?cite|\\printbibliography' "${dirName#/}".tex; then
      (cd "$HOME/projects/LibreNotebook" &&
       biber --output-directory temp "${dirName#/}")
      make4ht -u -B "$TMP_DIR" -f html5 "${dirName#/}".tex "mathjax"
    fi
    tidy -wrap 0 -utf8 -m --show-body-only yes --force-output yes \
      "$TMP_DIR$dirName".html
    mv "$TMP_DIR$dirName".html "$CONTENT$dirNameLower".html
    mv "$TMP_DIR$dirName".css "$CSS$dirNameLower".css
  )

  for subdir in "$dir"/*; do
    [[ -d "$subdir" ]] || continue

    (
      cd "$HOME/projects/LibreNotebook/$subdir"

      subdirName="${subdir#"$dir"}"
      subdirNameLower=$(echo "$subdirName" | tr 'A-Z' 'a-z')
      mkdir -p "$CONTENT$dirNameLower/$subdirNameLower"

      for file in *.tex; do
        fileName="$(basename "$file" .tex)"
        fileNameLower=$(echo "$fileName" | tr 'A-Z' 'a-z')

        make4ht -u -B "$TMP_DIR" -f html5 "$fileName".tex "mathjax"
        if grep -qE '\\(no)?cite|\\printbibliography' "$fileName".tex; then
          (cd "$HOME/projects/LibreNotebook" &&
           biber --output-directory temp "$fileName")
          make4ht -u -B "$TMP_DIR" -f html5 "$fileName".tex "mathjax"
        fi

        perl -0777 -pi -e "s#src\s*=\s*'([^']+\.svg)'#src='/svg/\$1'#g" \
          "$TMP_DIR/$fileName".html
        perl -pi -e 's/\\(?:displaybreak|linebreak|relax)//g' \
          "$TMP_DIR/$fileName.html"
        tidy -wrap 0 -utf8 -m --show-body-only yes --force-output yes \
          "$TMP_DIR/$fileName".html

        mv "$TMP_DIR/$fileName".html \
           "$CONTENT$dirNameLower$subdirNameLower/$fileNameLower".html
        mv "$TMP_DIR/$fileName".css "$CSS/$fileNameLower".css
      done
    )
  done
done

cd "$HOME/projects/LibreNotebook/"
mv temp/*.svg "$OUT_DIR"/static/svg/
cp assets/img/* "$OUT_DIR"/static/img/
rm -r temp/

git log --date=short --pretty=format:'%H%x1f%h%x1f%ad%x1f%an%x1f%s' |
jq -Rn '[inputs | split("\u001f") |
  {hash: .[0], commit: .[1], date: .[2], author: .[3], message: .[4]}]
' > librenotebook.enochyu.com/data/changelog.json

printf '%s\n' '---' 'layout: "changelog"' '---' > "$CONTENT/changelog.md"

