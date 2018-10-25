for file in ../tests/bad_tests/*
do
	echo "\nFile : $file"
	../lem_in < $file
done
