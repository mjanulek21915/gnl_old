
gcc \
-Wall -Wextra -Werror \
-I gnl_nouveau -I test_gnl \
main2.c \
gnl_nouveau/get_next_line$bonus.c gnl_nouveau/get_next_line_utils$bonus.c gnl_nouveau/get_next_line$bonus.h \
test_gnl/test_get_next_line_bonus.c test_gnl/test_get_next_line_bonus.h test_gnl/test_get_next_line_utils_bonus.c \
-D BUFFER_SIZE=8