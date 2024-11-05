# Check if Directory and FIle exists in project
if [ ! -d build ]; then
  mkdir build
fi

if [ ! -d database ]; then
  mkdir database
fi

if [ ! -f database/user_data.json ]; then
  touch database/user_data.json
fi

# Make Variable for path
INPUT_OUTPUT_SRC="src/input_output.cpp"
INPUT_OUTPUT_BUILD="build/input_output.o"

USER_SRC="src/user.cpp"
USER_BUILD="build/user.o"

OPTION_SRC="src/option.cpp"
OPTION_BUILD="build/option.o"

INC_DIR="include"
LIB_DIR="library"

BUILD_DIR="build"
DATABASE_DIR="database"

# Compile the object file
clang++ -I$INC_DIR -c $INPUT_OUTPUT_SRC -o $INPUT_OUTPUT_BUILD
clang++ -I$INC_DIR -I$LIB_DIR -c $USER_SRC -o $USER_BUILD
clang++ -I$INC_DIR -c $OPTION_SRC -o $OPTION_BUILD

# Create the static library
ar rcs -o $BUILD_DIR/libstatic.so $INPUT_OUTPUT_BUILD $USER_BUILD $OPTION_BUILD

# Compile main program and link with shared library
clang++ main.cpp -I$INC_DIR -L./$BUILD_DIR -lstatic -o finman

# Wait user to press a key before exiting
echo "Script completed succesfully."
read -p "Enter any key to exit..." input