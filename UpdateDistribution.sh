#!/bin/sh

LIBRARY_FILE=/Users/jared/Projects/mvc_menu/build/libmvc_menu.dylib
HEADERS_DIRECTORY=/Users/jared/Projects/mvc_menu/public
DISTRIBUTION_DIRECTORY=/Users/jared/Projects/mvc_menu/distribution

cp $LIBRARY_FILE $DISTRIBUTION_DIRECTORY
rsync -r $HEADERS_DIRECTORY/ $DISTRIBUTION_DIRECTORY
