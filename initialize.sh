rm -r ./bin
mkdir ./bin
g++ generate_problem_derived_parameters.cpp -o ./bin/generate_problem_derived_parameters && ./bin/generate_problem_derived_parameters
cat ./problem_derived_parameters.txt
