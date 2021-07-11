#Get the current directory
cd `dirname $0`

# creat build directory
mkdir -p build

# navigate to the build directory
cd build

# build the code
cmake .. 
make

# Run the binary file
./pid

