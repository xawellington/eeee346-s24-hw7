rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat inputs/testEncodeAutokey.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultEncodeAutokey.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Encode Autokey - FAIL"
  else
    echo "Encode Autokey - PASS"
  fi 
else
  echo "Encode Autokey - FAIL (MISSING FILE)"
fi
