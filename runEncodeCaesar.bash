rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat inputs/testEncodeCaesar.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultEncodeCaesar.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Encode Caesar - FAIL"
  else
    echo "Encode Caesar - PASS"
  fi 
else
  echo "Encode Caesar - FAIL (MISSING FILE)"
fi
