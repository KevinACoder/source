#!bin/sh
#$1 file name
#$2 author name

FILENAME=""
FILECOMMENT=""
FILEAUTHOR="Kevin"
DATE=`date '+%Y-%m-%d %H:%M:%S'`
if [ $# -eq 0 ]
then
	echo "Please input file name first"
	exit
elif [ $# -eq 1 ]
then
	FILENAME=$1
	echo "No file comments input"
elif [ $# -eq 2 ]
then 
	FILENAME=$1
	FILECOMMENT=$2
	echo "Create for default user"
else
	FILENAME=$1
	FILECOMMENT=$2
	FILEAUTHOR=$3
fi

touch $FILENAME
echo "/*author: $FILEAUTHOR" >> $FILENAME
echo "  create date: $DATE" >> $FILENAME
echo "  propose: $FILECOMMENT" >> $FILENAME
echo "********************/" >> $FILENAME
echo "java source file $FILENAME created !!"
