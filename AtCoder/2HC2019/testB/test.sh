echo "2HC2019 1B test scrpit"
g++ -std=c++14 -o ./contestant ../b.cpp
python3 ../toolkitB/scripts/interactive.py --judge './judge 1 ${RANDOM}' --contestant ./contestant
exit 0