# Make Variable for path
BUILD_DIR="build"
DATABASE_DIR="database"
USER_DATA="database/user_data.json"

# Check if folder exist, if not make a new folder

if [ ! -d $BUILD_DIR ]; then 
  mkdir $BUILD_DIR 
fi

if [ ! -d $DATABASE_DIR ]; then
  mkdir $DATABASE_DIR
fi

if [ ! -f $USER_DATA ]; then
  echo -n >$USER_DATA
fi

echo "DONE"