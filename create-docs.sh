#!/bin/bash
set -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

echo "Generating appledocs..."
appledoc --project-name "WilddogUI" \
--project-company "Wilddog" \
--company-id com.Wilddog \
--no-create-docset \
--create-html \
--keep-intermediate \
--output ./docs/output/ \
--templates=./appledoc/Templates/ \
--output "$DIR/site/" \
--search-undocumented-doc \
--exit-threshold 2 \
"$DIR"/WilddogUI/API/*.h

echo "Copying docs to Wilddog site..."
cp -r site/html/* ../WilddogUI/docs/ios
