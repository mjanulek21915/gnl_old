filename_list=("test" "test_continu" "test_ligne_7+1" "test_ligne_8+1" "test_lignes_vides" "test_vide")


if [ ! -z $1 ]
then
	echo "dollar 1 = $1"
	buffer_size=$1
else
	echo "no dollar 1"

	buffer_size=1
fi

if [ ! -z $2 ]
then
	echo "dollar 2 = $2"
	iterations_count=$2
else
	echo "no dollar 2"
	iterations_count=1
fi

for filename in ${filename_list[@]}
do
	gcc \
	-Wall -Wextra -Werror \
	-I gnl_nouveau -I test_gnl \
	-fsanitize=address -g \
	main2.c \
	gnl_nouveau/get_next_line$bonus.c gnl_nouveau/get_next_line_utils$bonus.c gnl_nouveau/get_next_line$bonus.h \
	test_gnl/test_get_next_line_bonus.c test_gnl/test_get_next_line_bonus.h test_gnl/test_get_next_line_utils_bonus.c \
	-D BUFFER_SIZE=$buffer_size
	./a.out $filename $iterations_count
done