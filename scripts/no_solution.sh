for file in ../tests/no_solution/*
do
	echo "\n<<<<<<<<<<<<<<<<<<<<<###################################################>>>>>>>>>>>>>>>>>>>>>\n"
	echo "File : $file"
	../lem_in < $file
done
