rm -rf result.txt
rm -rf main
g++ -o main *.cpp *.h
cat inputs/testDecodeCaesar.txt | ./main

if [ -f "result.txt" ]; then
  HORZ_CHECK=$(diff -b -B result.txt golden/resultDecodeCaesar.txt)
  if [ "$HORZ_CHECK" !=  "" ]; then
    echo "Decode Caesar - FAIL"
  else
    echo "Decode Caesar - PASS"
  fi 
else
  echo "Decode Caesar - FAIL (MISSING FILE)"
fi
