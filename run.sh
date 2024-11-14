# Make Variable for path
SRC_DIR="src"
INC_DIR="include"
LIB_DIR="library"
BUILD_DIR="build"
DATABASE_DIR="database"
USER_DATA="database/user_data.json"

if [ ! -d $BUILD_DIR ]; then
  mkdir $BUILD_DIR
fi

if [ ! -d $DATABASE_DIR ]; then
  mkdir $DATABASE_DIR
fi

if [ ! -f $USER_DATA ]; then
  echo -n >$USER_DATA
fi

# Compile the object file
g++ -c $SRC_DIR/input_output.cpp -I./$INC_DIR -o $BUILD_DIR/input_output.o
g++ -c $SRC_DIR/user.cpp -I./$INC_DIR -o $BUILD_DIR/user.o
g++ -c $SRC_DIR/option.cpp -I./$INC_DIR -o $BUILD_DIR/option.o
# g++ -c $SRC_DIR/hash.cpp -I./$INC_DIR -o $BUILD_DIR/hash.o

# Create the shared library
g++ -shared -o myLibrary.dll $BUILD_DIR/*.o

# Compile main program and link with shared library
g++ main.cpp -L. -lmyLibrary -I./$INC_DIR -o finman.exe

# Wait user to press a key before exiting
read -p "Enter any key to exit..."