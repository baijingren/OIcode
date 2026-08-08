#!/usr/bin/env bash
set -u
LOOPS=${1:-1000}

for ((i = 1; i <= LOOPS; i++)); do
  ./Bg > in.txt || exit 1

  ./Bc < in.txt > out_bc.txt || { echo "Bc RE on iteration $i (input in in.txt)"; exit 1; }
  ./B  < in.txt > out_b.txt  || { echo "B RE on iteration $i (input in in.txt)"; exit 1; }

  if ! diff <(tr -s '[:space:]' '\n' < out_bc.txt) <(tr -s '[:space:]' '\n' < out_b.txt) > /dev/null; then
    echo "WA on iteration $i (input in in.txt)"
    echo "--- Bc ---"
    cat out_bc.txt
    echo "--- B ---"
    cat out_b.txt
    exit 1
  fi
done

echo "All $LOOPS iterations OK"
