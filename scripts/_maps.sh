for file in ../tests/_maps/*
do
	echo "\n\n<<<<<<<<<<<<<<<<<<<<<###################################################>>>>>>>>>>>>>>>>>>>>>\n\n"
	echo "File : $file\n\n"
	../lem_in < $file
done
