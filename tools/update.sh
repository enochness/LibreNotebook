#!/bin/bash

cd ~/projects/LibreNotebook
cp build/main.pdf \
  ~/projects/archive/website/static/LibreNotebook.pdf

cd ~/projects/archive/website
git add .
git commit -S -m "feat: Update LibreNotebook"
git push origin main

