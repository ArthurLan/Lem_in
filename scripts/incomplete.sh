for file in ../tests/incomplete_maze/*
do
	echo "\n\n<<<<<<<<<<<<<<<<<<<<<###################################################>>>>>>>>>>>>>>>>>>>>>\n\n"
	echo "File : $file\n\n"
	../lem_in < $file
done
