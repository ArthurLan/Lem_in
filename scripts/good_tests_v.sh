for file in ../tests/good_tests/*
do
	echo "\n\n<<<<<<<<<<<<<<<<<<<<<###################################################>>>>>>>>>>>>>>>>>>>>>\n\n"
	echo "File : $file\n\n"
	../lem_in -v < $file
done
