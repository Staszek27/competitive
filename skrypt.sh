rm -f brut gen lazy_propagation
make brut
make gen
make lazy_propagation

for i in {1..1000}; do
    ./gen $i > test.in
    ./brut < test.in > test1.out
    ./lazy_propagation < test.in > test2.out
    if diff -bq test1.out test2.out; then echo $i
    else break
    fi 
done