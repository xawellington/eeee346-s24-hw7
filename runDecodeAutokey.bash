rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat inputs/testDecodeAutokey.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultDecodeAutokey.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Decode Autokey - FAIL"
  else
    echo "Decode Autokey - PASS"
  fi 
else
  echo "Decode Autokey - FAIL (MISSING FILE)"
fi
