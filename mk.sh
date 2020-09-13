buffer_sizes_list=(1 2 3 4 5 6 7 8 9 10 11 100 101 1000 1001)
iteration_counts_list=(1 2 3 7 8 9 16 17 18 20)
is_leak=0


bonus=""

echo "SANITARY LOG" >sanitary_log
echo "VALGRIND LOG" >valgrind_log

	# -fsanitize=address -g \

for buffer_size in ${buffer_sizes_list[@]}
do
	echo $buffer_size
	valgrind_temp=""
	gcc \
	-Wall -Wextra -Werror \
	-I gnl_nouveau -I test_gnl \
	main.c \
	gnl_nouveau/get_next_line$bonus.c gnl_nouveau/get_next_line_utils$bonus.c gnl_nouveau/get_next_line$bonus.h \
	test_gnl/test_get_next_line_bonus.c test_gnl/test_get_next_line_bonus.h test_gnl/test_get_next_line_utils_bonus.c \
	-D BUFFER_SIZE=$buffer_size
	for iteration_count in ${iteration_counts_list[@]}
	do
		is_leak=0
		echo "buffer size = ${buffer_size}" >>sanitary_log
		echo "iteration count = ${iteration_count}" >>sanitary_log
		oldIFS=$IFS
		IFS=$'\n'
		./a.out $iteration_count 2>>sanitary_log
		valgrind_temp=$(valgrind --leak-check=full ./a.out $iteration_count 2>&1)
		for line in $valgrind_temp
		do
			if [[ $line =~ .*LEAK\ SUMMARY.* ]]
			then
				is_leak=1
				echo "line : ${line}"
			fi
		done
		if [ $is_leak -eq 1 ]
		then
			IFS=""

			echo "buffer size : ${buffer_size}" >>valgrind_log
			echo "iteration_count : ${iteration_count}" >>valgrind_log
			printf "\n" >>valgrind_log
			echo $valgrind_temp >>valgrind_log
			echo "valgrind_temp : ${valgrind_temp}"
			printf "\n\n" >>valgrind_log
		fi
		IFS=$oldIFS
	done
done
