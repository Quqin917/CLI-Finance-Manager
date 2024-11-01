# Make Variable for path
SRC_DIR="src"
INC_DIR="include"
LIB_DIR="library"
BUILD_DIR="build"

if [ ! -d $BUILD_DIR ]; then
  mkdir $BUILD_DIR
fi

# Compile the object file
g++ -c $SRC_DIR/input_output.cpp -I./$INC_DIR -o $BUILD_DIR/input_output.o
g++ -c $SRC_DIR/user.cpp -I./$INC_DIR -I./$LIB_DIR -o $BUILD_DIR/user.o
g++ -c $SRC_DIR/option.cpp -I./$INC_DIR -o $BUILD_DIR/option.o

# Create the shared library
g++ -shared -o myLibrary.dll $BUILD_DIR/input_output.o $BUILD_DIR/user.o $BUILD_DIR/option.o

# Compile main program and link with shared library
g++ main.cpp -L. -lmyLibrary -I./$INC_DIR -o finman.exe

# Wait user to press a key before exiting
read -p "Enter any key to exit..."