#! /bin/bash
echo "creating .PDF"

echo "test" >> test.PDF
echo "hello" >> hello.PDF.PDF

echo "Renaming"

for file in *.PDF ; do mv "$file" "${file%%.PDF}.pdf" ; done

echo "DONE!"

